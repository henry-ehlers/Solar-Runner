#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ship.h"

class Controller {
  
 public:
  
  void HandleInput(bool &running, Ship &ship) const;
  
private:
  
  void ChangeDirection(Ship &ship, Ship::Direction input) const

#endif