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
  
  void Run(Renderer &renderer, Controller &controller);

 private:
  
  std::unique_ptr<Ship> ship;
  std::vector<std::unique_ptr<Meteor>> meteors;
  
//   std::random_device dev;
//   std::mt19937 engine;
//   std::uniform_int_distribution<int> random_w;
//   std::uniform_int_distribution<int> random_h;
  const std::tuple<int,int> screen_bounds;
  const std::size_t FRAMES_PER_SECOND;
  const std::size_t KM_PER_FRAME;
  
  int score{-1};
  bool running;
  
};

#endif