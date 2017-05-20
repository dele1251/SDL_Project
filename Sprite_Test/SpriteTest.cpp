#include "SpriteTest.h"

SpriteTest::SpriteTest ()
{
  mCharacter1 = nullptr
}
SpriteTest:: ~SpriteTest ()
{

}

void SpriteTest::initGame ()
{
  mCharacter1 = new SDLSprite (*this,"sprite_transparent.bmp", 100, 100);
  
}
void SpriteTest::update ()
{

}
void SpriteTest::handleEvent (SDL_Event event)
{

}
void SpriteTest::render ()
{
}