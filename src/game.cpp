#include "game.h"
#include "ship.h"

#include <iostream>
#include <unistd.h>
#include <memory>
#include <tuple>

Game::Game(const int fps, const std::tuple<int,int> xy_bounds) : ship(std::make_unique<Ship>(xy_bounds)), screen_bounds(xy_bounds), FRAMES_PER_SECOND(fps), KM_PER_FRAME(1000/fps), engine(dev()), meteor_x_location(20, static_cast<int>(std::get<0>(xy_bounds) - 20)), meteor_speed(-2, 2), spawn_meteor(1), meteor_size(-2, 2) {
};

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
  
  // Inititialize Key Game Logic variables
  this->running = true;
  this->score = 0;
  
  // Initialize Meteor Variables
  this->meteor_spawn_speed = 120;
  int frame_since_last_spawn = 1;
  std::tuple<int,int> meteor_location;
  int meteor_x_location;
  int meteor_speed;
  int meteor_size;
  
  // Start Game Loop
  while (this->running) {
    
    // KEEP FRAMES CONSISTENT
    frame_start = SDL_GetTicks();

    // UPDATE KEY QUANTITIES
    frame_since_last_spawn -= 1;
    UpdateMeteorSpeed();
   	UpdateMeteorSize();
    
    // SPAWN METEOR
    if ((meteors.size() <= 10) & (spawn_meteor(this->engine) == 1) & (frame_since_last_spawn == 0)) {
      meteor_size  = this->default_meteor_size + this->meteor_size( this->engine );
      meteor_speed = this->default_meteor_speed + this->meteor_speed( this->engine );
      while (true)  {
        meteor_x_location = this->meteor_x_location(this->engine);
        break;
      };
      // Determine the Meteor's location
      meteor_location = std::make_tuple(meteor_x_location, 0 - meteor_size);
      meteors.push_back(std::make_unique<Meteor>(meteor_location, meteor_size, meteor_speed));
      frame_since_last_spawn = this->meteor_spawn_speed;
    };
    
    // USER INPUT
    ship = controller.HandleInput(running, std::move(ship));
    
    // MOVE METEORS AND FIGURE OUT WHICH ARE OUT OF SCOPE, AND DELETE (MEMORY MANAGEMENT)
    to_delete.erase(to_delete.begin(),to_delete.end());
    for (std::unique_ptr<Meteor> &meteor : meteors) {
      meteor.get()->Update(); 
      if (meteor.get()->GetUpperY() <= std::get<1>(screen_bounds)) {
        to_delete.push_back(false);	// indicate non-removal
      } else {
        std::tuple<int,int> cur_loc = meteor.get()->GetLocation();
      	std::cout << "DELETE METEOR AT:" << std::get<0>(cur_loc) << " - " << std::get<1>(cur_loc) << "\n";
        score += 1;					// increment score
        meteor.reset(); 			// delete object and its pointer
        to_delete.push_back(true);	// indicate removal of nullptr
      };
    };
    BoolIndex(meteors, to_delete);	// remove deleted nullptrs
    
    // CHECK FOR COLLISSION
    for (std::unique_ptr<Meteor> &meteor : meteors) {
      if (CheckCollision(meteor, ship)) {
        return;
      }
    }
    
    // RENDER FRAME
    renderer.ClearScreen();
    ship = renderer.RenderObject(std::move(ship));
    for (std::unique_ptr<Meteor> &meteor : meteors) {
      std::tuple<int,int> cur_loc = meteor.get()->GetLocation();
      std::cout << "RENDER METEOR AT:" << std::get<0>(cur_loc) << " - " << std::get<1>(cur_loc) << "\n";
      meteor = renderer.RenderObject(std::move(meteor));
    };
    renderer.UpdateScreen();
    renderer.UpdateWindowTitle(this->score);
    
    // KEEP FRAMES PER SECOND CONSISTENT
    frame_end      = SDL_GetTicks();
    frame_duration = frame_end - frame_start;
    if (frame_duration < KM_PER_FRAME) {
      SDL_Delay(KM_PER_FRAME - frame_duration);
    }
    
  };
};

bool Game::CheckCollision(std::unique_ptr<Meteor> &meteor, std::unique_ptr<Ship> &ship) {
  std::tuple<int,int> met_loc = meteor.get()->GetLocation();
  std::tuple<int,int> ship_loc = ship.get()->GetLocation();
  
  std::cout << "DIFF X: " << std::abs(std::get<0>(met_loc) - std::get<0>(ship_loc)) << "\n";
  std::cout << "DIFF Y: " << std::abs(std::get<1>(met_loc) - std::get<1>(ship_loc)) << "\n";
  
  // Heuristic Check
  if (20 <= std::abs( std::get<0>(met_loc) - std::get<0>(ship_loc) ) || 
      20 <= std::abs( std::get<1>(met_loc) - std::get<1>(ship_loc) ) 
  ) {
    return false;
  } else {
    return true;
  }
};

bool Game::CheckAllVertices(std::unique_ptr<Meteor> &meteor, std::unique_ptr<Ship> &ship) {
  
};

bool Game::CheckTwoVertices(std::tuple<int,int> seg_1_a, std::tuple<int,int> seg_1_b, std::tuple<int,int> seg_2_a, std::tuple<int,int> seg_2_b) {
  // Intersection mathematics outlined here:
  // https://stackoverflow.com/questions/3838329/how-can-i-check-if-two-segments-intersect
  float A1 = ( std::get<1>(seg_1_a) - std::get<1>(seg_1_b) ) / ( std::get<0>(seg_1_a) - std::get<1>(seg_1_b) );
  float A2 = ( std::get<1>(seg_2_a) - std::get<1>(seg_2_b) ) / ( std::get<0>(seg_2_a) - std::get<1>(seg_2_b) );
  float b1 = std::get<1>(seg_1_a) - ( A1 * std::get<0>(seg_1_a) );
  float b2 = std::get<1>(seg_2_a) - ( A1 * std::get<0>(seg_2_a) );
  if (A1 == A2) {
    return false;
  };
  float Xa = (b2 - b1) / (A1 - A2);
  if (
    ( Xa < std::max( std::min(std::get<0>(seg_1_a),std::get<0>(seg_1_b) ), std::min( std::get<0>(seg_2_a),std::get<0>(seg_2_b) ) ) ) || 
    ( Xa > std::min( std::max(std::get<0>(seg_1_a),std::get<0>(seg_1_b) ), std::max( std::get<0>(seg_2_a),std::get<0>(seg_2_b) ) ) ) 
  ) {
    return false;
  } else {
    return true;
  };
};

bool Game::CheckAllVertices(std::unique_ptr<Meteor> &meteor, std::unique_ptr<Ship> &ship) {}