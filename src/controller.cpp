#include "controller.h"

#include <iostream>
#include "SDL.h"
#include "ship.h"

std::unique_ptr<Ship> Controller::HandleInput(bool &running, std::unique_ptr<Ship> ship) const {
  
  SDL_Event e;
  
  while (SDL_PollEvent(&e)) {
    
    if (e.type == SDL_QUIT) {
      running = false;
      
    } else if (e.type == SDL_KEYDOWN) {
      
      switch (e.key.keysym.sym) {          

        case SDLK_LEFT:
          ship.get()->BankLeft();
          break;

        case SDLK_RIGHT:
          ship.get()->BankRight();
          break;
      }
    }
  }
  
  return std::move(ship);
}
