#include "controller.h"

#include <iostream>
#include "SDL.h"
#include "ship.h"

void Controller::HandleInput(bool &running, Ship &ship) const {
  
  SDL_Event e;
  
  while (SDL_PollEvent(&e)) {
    
    if (e.type == SDL_QUIT) {
      running = false;
      
    } else if (e.type == SDL_KEYDOWN) {
      
      switch (e.key.keysym.sym) {          

        case SDLK_LEFT:
          ship.BankLeft();
          break;

        case SDLK_RIGHT:
          ship.BankRight();
          break;
      }
    }
  }
}
