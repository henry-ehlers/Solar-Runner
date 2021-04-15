#include "game.h"
#include "ship.h"

#include <iostream>
#include <unistd.h>
#include <memory>
#include <tuple>

Game::Game(const int fps, const std::tuple<int,int> xy_bounds) : ship(std::make_unique<Ship>(xy_bounds)), screen_bounds(xy_bounds), FRAMES_PER_SECOND(fps), KM_PER_FRAME(1000/fps) {};

void Game::BoolIndex (std::vector<std::unique_ptr<Meteor>> &meteors, std::vector<bool> to_delete) {
  std::vector<std::unique_ptr<Meteor>> tmp;
  for  (int index = 0; index < meteors.size(); index++) {
    if (!to_delete[index]) {
      tmp.push_back(std::move(meteors[index]));
    };
  };
  meteors.erase(meteors.begin(),meteors.end());
  for (int index = 0; index < tmp.size(); index++) {
    meteors.push_back(std::move(tmp[index]));
  };
};
  

void Game::Run(Renderer &renderer, Controller &controller) {
  
  // Set a bunch of FPS-related
  // based on template code provided by udacity:
  // https://github.com/udacity/CppND-Capstone-Snake-Game
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  
  // Inititialize Key variables
  this->running = true;
  this->score = 0;

  // Start Game Loop
  while (this->running) {
    
    // Count / keep track of when this frame started
    frame_start = SDL_GetTicks();

    // Update Bernoulli Distribution
    meteor_probability = 0.5 - 1.0 * (1.0 / this->score);
    spawn_meteor(meteor_probability);

    // Decide whether to and where spawn new Meteor
    if (if meteors.size() <= 10 & spawn_meteor(this->engine)) {
      std::tuple<int,int> MeteorLocation = std::make_tuple(320/2, 640/2);
      meteors.push_back(std::make_unique<Meteor>(MeteorLocation,10,2));
    }
    
    // Lister for controller / keyboard input and update the ship accordingly
    ship = controller.HandleInput(running, std::move(ship));
    
    // Update the existing meteors
    // If out of scope, delete their contents and pointers
    to_delete.erase(to_delete.begin(),to_delete.end());
    for (std::unique_ptr<Meteor> &meteor : meteors) {
      meteor.get()->Update();  		// movement update
      if (meteor.get()->GetUpperY() <= std::get<1>(screen_bounds)) {
        to_delete.push_back(false);	// indicate non-removal
      } else {
        score += 1;					// increment score
        meteor.reset(); 			// delete object and its pointer
        to_delete.push_back(true);	// indicate removal of nullptr
      };
    };
    BoolIndex(meteors, to_delete);	// remove deleted nullptrs
    
    // Render Scene
    renderer.ClearScreen();
    ship = renderer.RenderObject(std::move(ship));
    for (std::unique_ptr<Meteor> &meteor : meteors) {
      meteor = renderer.RenderObject(std::move(meteor));
    };
    
    // Keep track of how long each loop through the 
    frame_end      = SDL_GetTicks();
    frame_duration = frame_end - frame_start;

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate and game speed
    if (frame_duration < KM_PER_FRAME) {
      SDL_Delay(KM_PER_FRAME - frame_duration);
    }
    
  };
};

