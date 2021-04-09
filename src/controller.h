#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ship.h"

#include <memory>
class Controller {
  
 public:
  
  std::unique_ptr<Ship> HandleInput(bool &running, std::unique_ptr<Ship> ship) const;
  
};

#endif