#include "ISDLWidgetClickable.h"

void ISDLWidgetClickable::registerClickEventHandler (
  std::function<void (void)> cFunction)
{
  mcClickHandler = cFunction;
}

void ISDLWidgetClickable::clickEventHandler ()
{
  if (nullptr != mcClickHandler)
  {
    mcClickHandler ();
  }
}