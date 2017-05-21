//**************************************************************************** 
// File name:	MovingSprite.h
// Author:		
// Date:		  5/6/2016
// Class:		  CS 250
// Assignment:08_MissileCommand
// Purpose:		Interface of the MovingSprite class
//*****************************************************************************

#pragma once

#include "Sprite.h"
#include "Direction2D.h"

class MovingSprite : public Sprite
{
	public:

		static const int MAX_SPRITES = 100;
		MovingSprite ();
		//MovingSprite (SDL_Renderer *pRenderer, const char *fileName, int x, int y, int speed, Direction2D direction);
		void move ();
		void setSpeed (int);
		void setDirection (const Direction2D & cDirt);
		int getSpeed () const;

	private:

	int mSpeed;
	Direction2D mcDirection;
};