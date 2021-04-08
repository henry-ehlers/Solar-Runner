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
  
  void Run(Renderer &renderer);
  int GetScore() const;
  int GetSize() const;

 private:
  
  Ship ship;

//   std::random_device dev;
//   std::mt19937 engine;
//   std::uniform_int_distribution<int> random_w;
//   std::uniform_int_distribution<int> random_h;

  int score{-1};
  bool running;
  
  void PlaceMeteor();
  void Update();
};

#endif