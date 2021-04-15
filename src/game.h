#ifndef GAME_H
#define GAME_H

#include <random>
#include <tuple>
#include <vector>

#include "SDL.h"

#include "renderer.h"
#include "controller.h"
#include "ship.h"
#include "meteor.h"

class Game {
  
 public:
  
  // Constructor
  Game(const int fps, const std::tuple<int,int> xy_bounds);
  
  // Main Loop
  void Run(Renderer &renderer, Controller &controller);

 private:
  
  // Function that updates a vector of unique pointers based on bool vec.
  void BoolIndex(std::vector<std::unique_ptr<Meteor>> &meteors, std::vector<bool> to_delete);
  
  // Unique Pointer to a singular, player-controlled ship
  std::unique_ptr<Ship> ship;

  // Vector of unique pointers to meteors on screen + 2 vectors for updating
  std::vector<std::unique_ptr<Meteor>> meteors;
  std::vector<std::unique_ptr<Meteor>> tmp_met;
  std::vector<bool> to_delete;

  // Random Number Generator for meteor location
  std::random_device dev;
  std::mt19937 engine;
  std::bernoulli_distribution spawn_meteor;
  std::uniform_int_distribution <int> metor_x_locaction;
  std::uniform_int_distribution <int> meteor_speed;
  std::uniform_int_distribution <int> meteor_size;
  
  // Meteor Parameters
  int default_meteor_speed;		// number of pixels traveled per frame
  int default_meteor_size;		// see meteor size parameter
  int meteor_spawn_speed;		// Measured in frames
  int max_n_meteors;			// max number of meteors that can exist

  // Constants relating to game rendering (FPS, sceen dimensionis)
  const std::tuple<int,int> screen_bounds;
  const std::size_t FRAMES_PER_SECOND;
  const std::size_t KM_PER_FRAME;
  
  // The Score and whether the game is running
  int score{-1};
  bool running;
  
};

#endif