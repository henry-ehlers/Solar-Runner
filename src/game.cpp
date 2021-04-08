#include "game.h"
#include "ship.h"

#include <iostream>

Game::Game() : ship(10,10) {};

void Game::Run(Renderer &renderer) {
  this->running = true;
  while (this->running) {
    renderer.RenderShip(ship);
    std::cout << "running\n";
    //break;
  };
};