//****************************************************************************
// File name:	 SDLSprite.cpp
// Author:     Chadd Williams modified by Ernesto De Leon
// Date:       3/30/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************
#include "SDLSpriteWidget.h"


//***************************************************************************
// Constructor: SDLSprite
//
// Description: Load the sprite at location x,y
//
// Parameters:  pcApp - the SDLApp to use
//              spriteName - the filename to load
//              x - x coordinate on the screen
//              y - y coordinate on the screen
//
// Returned:    None
//***************************************************************************
SDLSpriteWidget::SDLSpriteWidget (SDLApp * pcApp, std::string spriteName, int x, int y)
{

  loadSprite (pcApp, spriteName, x, y);
}

//***************************************************************************
// Function:    loadSprite
//
// Description: Load the sprite at location x,y
//
// Parameters:  pcApp - the SDLApp to use
//              spriteName - the filename to load
//              x - x coordinate on the screen
//              y - y coordinate on the screen
//
// Returned:    True on success, false otherwise
//***************************************************************************
bool SDLSpriteWidget::loadSprite (SDLApp * pcApp, std::string spriteName,
  int x, int y)
{
  mX = x;
  mY = y;

  mSpriteName = spriteName;

  return pcApp->loadSprite (spriteName, mW, mH);
}

//***************************************************************************
// Function:    getX
//
// Description: Get the x coordinate
//
// Parameters:  None
//
// Returned:    the x coordinate
//***************************************************************************
int SDLSpriteWidget::getX () const
{
  return mX;
}

//***************************************************************************
// Function:    getY
//
// Description: Get the y coordinate
//
// Parameters:  None
//
// Returned:    the y coordinate
//***************************************************************************
int SDLSpriteWidget::getY () const
{
  return mY;
}

//***************************************************************************
// Function:    getW
//
// Description: Get the width
//
// Parameters:  None
//
// Returned:    the width
//***************************************************************************
int SDLSpriteWidget::getW () const
{
  return static_cast<int>(mW * mScale);
}

//***************************************************************************
// Function:    getH
//
// Description: Get the height
//
// Parameters:  None
//
// Returned:    the height
//***************************************************************************
int SDLSpriteWidget::getH () const
{
  return static_cast<int>(mH * mScale);
}

//***************************************************************************
// Function:    getName
//
// Description: Get the file name
//
// Parameters:  None
//
// Returned:    the filename
//***************************************************************************
std::string SDLSpriteWidget::getName () const
{
  return mSpriteName;
}

//***************************************************************************
// Function:    draw
//
// Description: draw the sprite on the screen
//
// Parameters:  rcApp - the SDLApp to use
//
// Returned:    None
//***************************************************************************
void SDLSpriteWidget::draw (SDLApp & rcApp)
{
  rcApp.displaySpriteWidget (*this);
}

//***************************************************************************
// Function:    clicked
//
// Description: determine if the sprite has been clicked
//
// Parameters:  x - x coordinate of mouse click on screen
//              y - y coordinate of mouse click on screen
//
// Returned:    true if the x,y falls inside the sprite
//***************************************************************************
bool SDLSpriteWidget::clicked (int x, int y)
{
  bool bRetVal = false;
  if (x >= mX && x <= mX + mW &&
    y >= mY && y <= mY + mH)
  {
    bRetVal = true;
    //clickEventHandler ();
  }

  return bRetVal;
}

//***************************************************************************
// Function:    setScale
//
// Description: Set the scaling factor for the Sprite.  
//
// Parameters:  scale - the scaling factor. 
//              1.0 is no change. <1.0 is shrink, >1.0 is expand
//
// Returned:    None
//***************************************************************************
void SDLSpriteWidget::setScale (double scale)
{
  mScale = scale;
}

//***************************************************************************
// Function:    setRotation
//
// Description: Set the angle of rotation of the sprite.
//
// Parameters:  rotation - the degrees of rotation, 0.0 to 359.0
//
// Returned:    None
//***************************************************************************
void SDLSpriteWidget::setRotation (double rotation)
{
  mRotation = rotation;
}

//***************************************************************************
// Function:    getRotation
//
// Description: Get the angle of rotation of the sprite.
//
// Parameters:  None
//
// Returned:    the rotation of the sprite
//***************************************************************************
double SDLSpriteWidget::getRotation () const
{
  return mRotation;
}
