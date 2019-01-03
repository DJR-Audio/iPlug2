/*
 ==============================================================================

 This file is part of the iPlug 2 library. Copyright (C) the iPlug 2 developers.

 See LICENSE.txt for  more info.

 ==============================================================================
*/

#pragma once

/**
 * @file
 * @copydoc TestColorControl
 */

#include "IControl.h"

/** Control to colors
 *   @ingroup TestControls */
class TestColorControl : public IControl
{
public:
  TestColorControl(IGEditorDelegate& dlg, IRECT rect)
  :  IControl(dlg, rect)
  {
    SetTooltip("TestColorControl");
  }
  
  void OnResize() override
  {
    int idx = 0;
    float nstops = 7.;
    float stop = 0.;
    auto nextStop = [&]() {
      stop = (1.f/nstops) * idx++;
      return stop;
    };
    
    mPattern = IPattern::CreateLinearGradient(mRECT.L, mRECT.MH(), mRECT.R, mRECT.MH(),
    {
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
      {IColor::GetFromHSLA(nextStop(), 1., 0.5), stop},
    } );
  }

  void Draw(IGraphics& g) override
  {
    if(g.HasPathSupport())
    {
      g.PathRect(mRECT);
      g.PathFill(mPattern);
    }
  }

private:
  IPattern mPattern = IPattern(kLinearPattern);
};
