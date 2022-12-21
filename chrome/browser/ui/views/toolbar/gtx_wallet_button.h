#ifndef CHROME_BROWSER_UI_VIEWS_TOOLBAR_GTX_WALLET_BUTTON_H_
#define CHROME_BROWSER_UI_VIEWS_TOOLBAR_GTX_WALLET_BUTTON_H_

#include "base/memory/raw_ptr.h"
#include "base/memory/weak_ptr.h"
#include "chrome/browser/ui/views/toolbar/toolbar_button.h"

class Browser;

class GtxWalletButton : public ToolbarButton {
 public:
  METADATA_HEADER(GtxWalletButton);

  explicit GtxWalletButton(Browser* browser);
  GtxWalletButton(const GtxWalletButton&) = delete;
  GtxWalletButton& operator=(const GtxWalletButton&) = delete;
  ~GtxWalletButton() override;

  // ToolbarButton:
  void UpdateIcon() override;
  void Layout() override;
  void NotifyClick(const ui::Event& event) override;

 private:
  void UpdateExistingIcon();

  raw_ptr<Browser> browser_;
  base::WeakPtrFactory<GtxWalletButton> weak_factory_{this};
};

#endif  // CHROME_BROWSER_UI_VIEWS_TOOLBAR_GTX_WALLET_BUTTON_H_
