#include "game.h"
#include "ship.h"

#include <iostream>
#include <unistd.h>

Game::Game(int fps, int width, int height) : ship(width,height), FRAMES_PER_SECOND(fps), KM_PER_FRAME(1000/fps) {};

void Game::Run(Renderer &renderer, Controller &controller) {
  
  // Set a bunch of FPS-related
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
    
    // Keep track of how long each loop through the input/update/render cycle
    frame_end = SDL_GetTicks();
    frame_count++;
    frame_duration = frame_end - frame_start;

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate and game speed
    if (frame_duration < KM_PER_FRAME) {
      SDL_Delay(KM_PER_FRAME - frame_duration);
    }

  };
};