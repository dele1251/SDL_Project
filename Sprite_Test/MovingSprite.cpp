//**************************************************************************** 
// File name:	MovingSprite.cpp
// Author:		
// Date:		  5/6/2016
// Class:		  CS 250
// Assignment:08_MissileCommand
// Purpose:		Implementation of the MovingSprite class
//*****************************************************************************

#include "MovingSprite.h"

MovingSprite::MovingSprite ()
{
 mcDirection = mcDirection.SOUTH;
 mSpeed = 0;
}

//****************************************************************************
// Function:	  setSpeed
//
// Description:	sets the mSpeed private data member if the speed is > 0
//
// Parameters:  int speed - the speed of the object 
//               
// Returned:	  none
//***************************************************************************

void MovingSprite::setSpeed (int speed)
{
	if (0 <= speed)
	{
		mSpeed = speed;
	}
}

//****************************************************************************
// Function:	  setDirection
//
// Description: sets the direction of the object	
//
// Parameters:  direction2D cDi r - a direction class            
//
// Returned:	  none
//***************************************************************************

void MovingSprite::setDirection (const Direction2D & cDir)
{
	mcDirection = cDir;
}

//****************************************************************************
// Function:	  getSpeed
//
// Description:	returns the spped of the moving circle
//
// Parameters:  none               
//
// Returned:	  int mSpeed - the speed of the moving circle
//***************************************************************************

int MovingSprite::getSpeed () const
{
	return mSpeed;
}

//****************************************************************************
// Function:	  move
//
// Description:	Moves the sprite on the screen
//
// Parameters:   none
//               
// Returned:	  none
//***************************************************************************
void MovingSprite::move ()
{
	setXPosition ((getXPosition () + mcDirection.getXMove () * mSpeed));
	setYPosition ((getYPosition () + mcDirection.getYMove () * mSpeed));
}