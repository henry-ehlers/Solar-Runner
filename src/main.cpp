#include <iostream>
#include <unistd.h>

#include "ship.h"
#include "game.h"
#include "renderer.h"

int main() {
  
  // Set Constants of Renderer
  constexpr std::size_t FRAMES_PER_SECOND{60};
  constexpr std::size_t PER_SECOND{1000 / FRAMES_PER_SECOND};
  constexpr std::size_t SCREEN_WIDTH{320};
  constexpr std::size_t SCREEN_HEIGHT{640};

  // Create Renderer
  Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
  
  // Create Controller
  // Controller controller();
  
  // Create Game and run it
  Game game = Game();
  game.Run(renderer);

  std::cout << "Game has terminated successfully!\n";
  return 0;
  
}