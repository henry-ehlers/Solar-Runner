#include <iostream>
#include <unistd.h>

#include "ship.h"
#include "game.h"
#include "renderer.h"

int main() {
  
  // Set Properties of Game
  constexpr int fps = 60;
  constexpr std::tuple<int,int> xy_bounds = std::make_tuple(320,640);
  constexpr std::size_t SCREEN_WIDTH{  std::get<0>(xy_bounds) };
  constexpr std::size_t SCREEN_HEIGHT{ std::get<1>(xy_bounds) };

  // Create Renderer
  Renderer renderer = Renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Create Controller
  Controller controller = Controller();
  
  // Create Game and run it
  Game game = Game(fps, xy_bounds);
  game.Run(renderer, controller);

  //std::cout << "Final Score: " << game.GetScore() << "\n";
  std::cout << "Game has terminated successfully!\n";
  return 0;
  
}