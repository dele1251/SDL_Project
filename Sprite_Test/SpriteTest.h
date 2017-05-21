#pragma once
#include <istream>
#include "SDLApp.h"

class SpriteTest : public SDLApp
{
public:
  SpriteTest ();
  virtual ~SpriteTest ();

  virtual void initGame ();
  virtual void update ();
  virtual void handleEvent (SDL_Event event);
  virtual void render ();

private:
  SDLSpriteWidget* mCharacter1;
};
