#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "renderer.h"
#include "ship.h"

class Game {
  
 public:
  
  // Constructor
  Game();
  
  void Run(Renderer &renderer, std::size_t frame_duration);
  int GetScore() const;
  int GetSize() const;

 private:
  
  Ship ship;
  

//   std::random_device dev;
//   std::mt19937 engine;
//   std::uniform_int_distribution<int> random_w;
//   std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceMeteor();
  void Update();
};

#endif