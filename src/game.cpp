#include "game.h"
#include "ship.h"

#include <iostream>
#include <unistd.h>

Game::Game(int fps, int width, int height) : ship(width,height), FRAMES_PER_SECOND(fps), KM_PER_FRAME(1000/fps) {};

void Game::Run(Renderer &renderer, Controller &controller) {
  
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  
  int frame_count = 0;
  this->running  = true;
  
  while (this->running) {
    frame_start = SDL_GetTicks();
    controller.HandleInput(running, ship);
    renderer.RenderShip(ship);
    std::cout << "running\n";
    frame_end = SDL_GetTicks();
    
  };
};