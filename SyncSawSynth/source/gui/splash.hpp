// (c) 2019 Takamitsu Endo
//
// This file is part of SyncSawSynth.
//
// SyncSawSynth is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SyncSawSynth is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SyncSawSynth.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include <memory>

#include "vstgui/vstgui.h"

#include "guistyle.hpp"

namespace Steinberg {
namespace Vst {

using namespace VSTGUI;

class CreditView : public CControl {
public:
  CreditView(const CRect &size, IControlListener *listener) : CControl(size, listener)
  {
    fontIDTitle = std::make_shared<CFontDesc>(
      Style::fontName(), fontSizeTitle, CTxtFace::kBoldFace);
    fontIDText = std::make_shared<CFontDesc>(Style::fontName(), fontSize);
  }

  void draw(CDrawContext *pContext) override;

  CMouseEventResult onMouseDown(CPoint &where, const CButtonState &buttons) override
  {
    if (buttons.isLeftButton()) {
      valueChanged();
      return kMouseDownEventHandledButDontNeedMovedOrUpEvents;
    }
    return kMouseEventNotHandled;
  }

  CLASS_METHODS(CreditView, CControl)

private:
  CCoord fontSize = 12.0;
  CCoord fontSizeTitle = 18.0;

  std::shared_ptr<CFontDesc> fontIDTitle;
  std::shared_ptr<CFontDesc> fontIDText;
};

class SplashLabel : public CSplashScreen {
public:
  SplashLabel(
    const CRect &size,
    IControlListener *listener,
    int32_t tag,
    CView *splashView,
    UTF8StringPtr txt = nullptr)
    : CSplashScreen(size, listener, tag, splashView), txt(txt)
  {
    fontID
      = std::make_shared<CFontDesc>(Style::fontName(), fontSize, CTxtFace::kBoldFace);
  }

  CLASS_METHODS(SplashLabel, CSplashScreen);

  void draw(CDrawContext *pContext) override;

  CMouseEventResult onMouseEntered(CPoint &where, const CButtonState &buttons) override;
  CMouseEventResult onMouseExited(CPoint &where, const CButtonState &buttons) override;
  CMouseEventResult onMouseCancel() override;

  void setDefaultFrameColor(CColor color);
  void setHighlightColor(CColor color);
  void setDefaultFrameWidth(float width);
  void setHighlightWidth(float width);

protected:
  UTF8StringPtr txt = nullptr;

  std::shared_ptr<CFontDesc> fontID;
  double fontSize = 24.0;
  CColor fontColor = CColor(0, 0, 0, 255);

  CColor frameColor = CColor(0, 0, 0, 255);
  CColor highlightColor = CColor(0, 0, 0, 255);
  float frameWidth = 1.0f;
  float highlightFrameWidth = 2.0f;

  bool isMouseEntered = false;
};

} // namespace Vst
} // namespace Steinberg
