#include <iostream>
#include <unistd.h>

#include "ship.h"
#include "game.h"
#include "renderer.h"

int main() {
  
  // Set Properties of Game
  int fps = 60;
  constexpr std::size_t SCREEN_WIDTH{320};
  constexpr std::size_t SCREEN_HEIGHT{640};

  // Create Renderer
  Renderer renderer = Renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Create Controller
  Controller controller = Controller();
  
  // Create Game and run it
  Game game = Game(fps);
  game.Run(renderer, controller);

  std::cout << "Game has terminated successfully!\n";
  return 0;
  
}