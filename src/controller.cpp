#include controller.h
#include <iostream>
#include "SDL.h"
#include "ship.h"

void Controller::HandleInput(bool &running, ship &ship) const {
  
  SDL_Event e;
  
  while (SDL_PollEvent(&e)) {
    
    if (e.type == SDL_QUIT) {
      running = false;
      
    } else if (e.type == SDL_KEYDOWN) {
      
      switch (e.key.keysym.sym) {          

        case SDLK_LEFT:
          ChangeDirection(snake, Snake::Direction::kLeft,Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake::Direction::kRight,Snake::Direction::kLeft);
          break;
      }
    }
  }
}

void Controller::ChangeDirection(Ship &ship, Ship::Direction input) const {
  snake.direction = input;
}