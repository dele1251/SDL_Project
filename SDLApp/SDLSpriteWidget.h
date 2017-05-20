//****************************************************************************
// File name:	 SDLSprite.h
// Author:     Chadd Williams modified by Ernesto De Leon
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#pragma once

#include "SDLApp.h"
#include <functional>
#include "ISDLWidgetClickable.h"
#include "ISDLWidget.h"

class SDLSpriteWidget : public ISDLWidgetClickable, public ISDLWidget
{
public:

  SDLSpriteWidget () = default;
  SDLSpriteWidget (SDLApp *pcApp, std::string spriteName, int x ,int y);

  bool loadSprite (SDLApp *pcApp, std::string spriteName, int x, int y);

  int getX () const;
  int getY () const;
  int getW () const;
  int getH () const;
  std::string getName () const;

  void draw (SDLApp &rcApp) ;

  bool clicked (int x, int y);

  void setScale (double scale);

  void setRotation (double rotation);
  double getRotation () const;

private:

  std::string mSpriteName;
  int mX, mY;
  int mH, mW;
  double mScale = 1.0;
  double mRotation = 0.0;

};
