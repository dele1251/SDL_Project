#include "SpriteTest.h"

SpriteTest::SpriteTest ()
{
  mCharacter1 = nullptr;
}
SpriteTest:: ~SpriteTest ()
{

}

void SpriteTest::initGame ()
{
  int width = 256;
  int height = 32;
  loadSprite ("test.bmp", width, height);
  
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