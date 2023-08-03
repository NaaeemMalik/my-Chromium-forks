// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

import {PostMessageAPIClient} from 'chrome-untrusted://projector/js/post_message_api_client.m.js';
import {RequestHandler} from 'chrome-untrusted://projector/js/post_message_api_request_handler.m.js';

const TARGET_URL = 'gtx://projector/';
import {AnnotatorBrowserProxyImpl, browserProxy} from './annotator_browser_proxy.js';
import {UntrustedAnnotatorPageCallbackRouter} from './ash/webui/projector_app/mojom/untrusted_annotator.mojom-webui.js';

/**
 * Returns the projector app element inside this current DOM.
 * @return {projectorApp.AnnotatorApi}
 */
function getAnnotatorElement() {
  return /** @type {projectorApp.AnnotatorApi} */ (
      document.querySelector('projector-ink-canvas-wrapper'));
}


// A client that sends messages to the gtx://projector embedder.
export class TrustedAnnotatorClient extends PostMessageAPIClient {
  /**
   * @param {!Window} parentWindow The embedder window from which requests
   *     come.
   */
  constructor(parentWindow) {
    super(TARGET_URL, parentWindow);
  }

  /**
   * Notifies the native ui that undo/redo has become available.
   * @param {boolean} undoAvailable
   * @param {boolean} redoAvailable
   * @return {Promise}
   */
  onUndoRedoAvailabilityChanged(undoAvailable, redoAvailable) {
    return this.callApiFn(
        'onUndoRedoAvailabilityChanged', [undoAvailable, redoAvailable]);
  }
}

/**
 * Class that implements the RequestHandler inside the Projector untrusted
 * scheme for Annotator.
 */
export class UntrustedAnnotatorRequestHandler extends RequestHandler {
  /**
   * @param {!Window} parentWindow The embedder window from which requests
   *     come.
   */
  constructor(parentWindow) {
    super(null, TARGET_URL, TARGET_URL);
    this.targetWindow_ = parentWindow;

    this.registerMethod('setTool', (args) => {
      getAnnotatorElement().setTool(args[0]);
      return true;
    });

    this.registerMethod('undo', () => {
      getAnnotatorElement().undo();
      return true;
    });

    this.registerMethod('redo', () => {
      getAnnotatorElement().redo();
      return true;
    });

    this.registerMethod('clear', () => {
      getAnnotatorElement().clear();
      return true;
    });
  }

  /** @override */
  targetWindow() {
    return this.targetWindow_;
  }
}

/**
 * This is a class that is used to setup the duplex communication channels
 * between this origin, chrome-untrusted://projector/* and the embedder content.
 */
export class AnnotatorUntrustedCommFactory {
  /**
   * Creates the instances of PostMessageAPIClient and Requesthandler.
   */
  static maybeCreateInstances() {
    if (AnnotatorUntrustedCommFactory.client_ ||
        AnnotatorUntrustedCommFactory.requestHandler_) {
      return;
    }

    AnnotatorUntrustedCommFactory.client_ =
        new TrustedAnnotatorClient(window.parent);

    AnnotatorUntrustedCommFactory.requestHandler_ =
        new UntrustedAnnotatorRequestHandler(window.parent);
    const elem = getAnnotatorElement();
    elem.addUndoRedoListener((undoAvailable, redoAvailable) => {
      AnnotatorUntrustedCommFactory.client_.onUndoRedoAvailabilityChanged(
          undoAvailable, redoAvailable);
    });
  }

  /**
   * In order to use this class, please do the following (e.g. To notify when
   * undo-redo becomes available):
   * AnnotatorUntrustedCommFactory.
   *     getPostMessageAPIClient().
   *     onUndoRedoAvailabilityChanged(true, true);
   * @return {!TrustedAnnotatorClient}
   */
  static getPostMessageAPIClient() {
    // AnnotatorUntrustedCommFactory.client_ should be available. However to be
    // on the cautious side create an instance here if getPostMessageAPIClient
    // is triggered before the page finishes loading.
    AnnotatorUntrustedCommFactory.maybeCreateInstances();
    return AnnotatorUntrustedCommFactory.client_;
  }
}
/* @type {AnnotatorPageCallbackRouter} */
let annotatorPageRouter = null;

const observer = new MutationObserver(() => {
  if (getAnnotatorElement()) {
    if (annotatorPageRouter) {
      // We have already registered. Therefore, return early.
      return;
    }

    annotatorPageRouter = browserProxy.getAnnotatorCallbackRouter();

    // Register for callbacks from the browser process.
    annotatorPageRouter.undo.addListener(() => {
      try {
        getAnnotatorElement().undo();
      } catch (error) {
        console.error('AnnotatorToolErrorType.UNDO_ERROR', error);
      }
    });
    annotatorPageRouter.redo.addListener(() => {
      try {
        getAnnotatorElement().redo();
      } catch (error) {
        console.error('AnnotatorToolErrorType.REDO_ERROR', error);
      }
    });
    annotatorPageRouter.clear.addListener(() => {
      try {
        getAnnotatorElement().clear();
      } catch (error) {
        console.error('AnnotatorToolErrorType.CLEAR_ERROR', error);
      }
    });
    annotatorPageRouter.setTool.addListener((tool) => {
      try {
        getAnnotatorElement().setTool(tool);
      } catch (error) {
        console.error('AnnotatorToolErrorType.SET_TOOL_ERROR', error);
      }
    });

    // Pass calls to the browser process.
    const elem = getAnnotatorElement();
    elem.addUndoRedoListener((undoAvailable, redoAvailable) => {
      browserProxy.onUndoRedoAvailabilityChanged(undoAvailable, redoAvailable);
    });
    elem.addCanvasInitializationCallback((success) => {
      browserProxy.onCanvasInitialized(success);
    });
  }
});

observer.observe(document, {childList: true, subtree: true});
