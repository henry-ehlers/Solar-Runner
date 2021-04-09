#include "game.h"
#include "ship.h"

#include <iostream>
#include <unistd.h>
#include <memory>
#include <tuple>

Game::Game(const int fps, const std::tuple<int,int> xy_bounds) : ship(std::make_unique<Ship>(xy_bounds)), FRAMES_PER_SECOND(fps), KM_PER_FRAME(1000/fps) {};

void Game::Run(Renderer &renderer, Controller &controller) {
  
  // Set a bunch of FPS-related
  // based on template code provided by udacity:
  // https://github.com/udacity/CppND-Capstone-Snake-Game
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  
  this->running = true;
  while (this->running) {
    
    // Count / keep track of when this frame started
    frame_start = SDL_GetTicks();
    
    std::cout << ship.get() << "\n";
    
    // Lister for controller / keyboard input
    std::cout << "MOVING SHIP INTO THE CONTROLLER\n";
    ship = controller.HandleInput(running, std::move(ship));
    std::cout << "MOVED THE SHIP BACK INTO GAME.RUN()\n";
    
    std::cout << ship.get() << "\n";
    
    // Render changes in 
    std::cout << "MOVING SHIP INTO THE RENDERER\n";
    ship = renderer.RenderObject(std::move(ship));
    std::cout << "MOVED THE SHIP BACK INTO GAME.RUN()\n";
    
    // Debug print
    std::cout << "running\n";
    
    // Keep track of how long each loop through the input/update/render cycle
    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate and game speed
    if (frame_duration < KM_PER_FRAME) {
      SDL_Delay(KM_PER_FRAME - frame_duration);
    }
    
  };
};