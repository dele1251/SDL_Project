//**************************************************************************** 
// File name:	Sprite.h
// Author:		
// Date:		  4/29/2016
// Class:		  CS 250
// Assignment:08_MissileCommand
// Purpose:		Interface of the Sprite class
//*****************************************************************************

#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "SDL2_gfxPrimitives.h"
#include <iostream>
#include <string>
#include "SDL_ttf.h"

using namespace std;

class Sprite
{
	public:

	Sprite ();
	~Sprite ();

	void loadImage(SDL_Renderer *pRenderer, const char *fileName, int x, int y);
	void drawSprite (SDL_Renderer *pRenderer) const;
	int getXPosition () const;
	int getYPosition () const;
	void setXPosition (int x);
	void setYPosition (int y);
	
	bool collision (const Sprite &oSprite) const;
	int getHeight () const;
	int getWidth () const;

	bool getBIsAlive ();
	void setBIsAlive (bool alive);

	private:

	SDL_Rect mSpriteSurface;
	SDL_Texture *mpSpriteTexture;

	bool mbIsAlive;

};