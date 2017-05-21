//**************************************************************************** 
// File name:	Sprite.cpp
// Author:		
// Date:		  4/29/2014
// Class:		  CS 250
// Assignment:08_MissileCommand
// Purpose:		Implementation of the Sprite class
//*****************************************************************************

#include "Sprite.h"

//****************************************************************************
// Method:	    Sprite (constructor)
//
// Description:	sets private member mbIsAlive to true
//
// Parameters:  none
//
// Returned:	  none
//***************************************************************************

Sprite::Sprite ()
{
	mbIsAlive = false;
}

//****************************************************************************
// Method:	    drawSprite
//
// Description:	draws the sprite on the screen
//
// Parameters:  SDL_Renderer *pRender - the renderer pointer
//
// Returned:	  none
//***************************************************************************

void Sprite::drawSprite (SDL_Renderer *pRenderer) const
{
	SDL_RenderCopy (pRenderer, mpSpriteTexture, NULL, &mSpriteSurface);
}

//****************************************************************************
// Method:	    setXPosition
//
// Description:	sets the origin X position of the SDL_Surface 
//
// Parameters:  int x - X coordinate
//
// Returned:	  none
//***************************************************************************

void Sprite::setXPosition (int x)
{
	mSpriteSurface.x = x;
}

//****************************************************************************
// Method:	    setYPosition
//
// Description:	sets the origin Y position of the SDL_Surface
//
// Parameters:  int y - Y coordinate
//
// Returned:	  none
//***************************************************************************

void Sprite::setYPosition (int y)
{
	mSpriteSurface.y = y;
}

//****************************************************************************
// Method:	    ~Sprite (destructor)
//
// Description:	destroys the SDL_Texture pointer, a member variable
//
// Parameters:  none
//
// Returned:	  none
//***************************************************************************

Sprite::~Sprite () 
{
	SDL_DestroyTexture (mpSpriteTexture);
}

//****************************************************************************
// Method:	    getWidth
//
// Description:	gets the width of the surface rectangle
//
// Parameters:  none
//
// Returned:	  mSpriteSurface.w - the width of the rectangle
//***************************************************************************

int Sprite::getWidth () const
{
	return mSpriteSurface.w;
}

//****************************************************************************
// Method:	    getHeight
//
// Description:	gets the height of the surface rectangle
//
// Parameters:  none
//
// Returned:	  mSpriteSurface.h - the height of the rectangle  
//***************************************************************************

int Sprite::getHeight () const
{
	return mSpriteSurface.h;
}

//****************************************************************************
// Method:	    getXPosition
//
// Description:	gets the X coordinate, the origin of the surface rectangle
//
// Parameters:  none
//
// Returned:	  mSpriteSurface.x - the X coordinate
//***************************************************************************

int Sprite::getXPosition () const
{
	return mSpriteSurface.x;
}

//****************************************************************************
// Method:	    getYPosition
//
// Description:	gets the Y coordinate, the origin of the surface rectangle
//
// Parameters:  none
//
// Returned:	  mSpriteSurface.y - the Y coordinate	  
//***************************************************************************

int Sprite::getYPosition () const
{
	return mSpriteSurface.y;
}

//****************************************************************************
// Method:	    collision
//
// Description:	checks for a collision with another sprite
//
// Parameters:  const Sprite &bomb - another sprite
//
// Returned:	  True or False
//***************************************************************************

bool Sprite::collision (const Sprite &bomb) const
{
	bool bIsColl = false; 

	// if the Y origin is less than the other sprites height and the y origin is
	// greater than the other sprites y origin
	if (mSpriteSurface.y <= bomb.getYPosition () + bomb.getHeight () && 
		mSpriteSurface.y >= bomb.getYPosition ())
	{

		// if the X origin is less than the other sprites width and the sprites x 
		// origin is greater than the other sprites x origin
		if (mSpriteSurface.x <= bomb.getXPosition () + bomb.getWidth () && 
			mSpriteSurface.x >= bomb.getXPosition ())
		{
			bIsColl = true;
		}
	}

	// if the y origin is less than the other sprites height and the y origin is
	// greater than the other sprites y origin
	if (mSpriteSurface.y <= bomb.getYPosition () + bomb.getHeight () && 
		mSpriteSurface.y >= bomb.getYPosition ())
	{

		// if the width is greater than the other sprites X origin and the width is
		// less than the other sprites width
		if (mSpriteSurface.x + mSpriteSurface.w >= bomb.getXPosition () && 
			mSpriteSurface.x + mSpriteSurface.w <= bomb.getXPosition () + 
			bomb.getWidth ())
		{
			bIsColl = true;
		}
	}
	return bIsColl;
}

//****************************************************************************
// Method:	    getbIsAlive
//
// Description:	gets the bool private datamember
//
// Parameters:  none
//
// Returned:	  True or False
//***************************************************************************

bool Sprite::getBIsAlive ()
{
	return mbIsAlive;
}

//****************************************************************************
// Method:	    setbIsAlive
//
// Description:	sets the private bool datamember
//
// Parameters:  bool alive - true or false
//
// Returned:	  none
//***************************************************************************

void Sprite::setBIsAlive (bool alive)
{
	mbIsAlive = alive;
}

//****************************************************************************
// Method:	    loadImage
//
// Description:	loads an image from a file
//
// Parameters: SDL_Renderer *pRenderer - the renderer pointer
//             const char *fileName - the file name of the image
//             int x - the X coordinate of origin
//             int y - the Y coordinate of origin
//
// Returned:	  none
//***************************************************************************

void Sprite:: loadImage(SDL_Renderer *pRenderer, const char *fileName, int x, 
	int y)
{
	mpSpriteTexture = IMG_LoadTexture(pRenderer, fileName);
	SDL_QueryTexture(mpSpriteTexture, NULL, NULL, &mSpriteSurface.w, 
		&mSpriteSurface.h);
	mSpriteSurface.x = x;
	mSpriteSurface.y = y;
}
