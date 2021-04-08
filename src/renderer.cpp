#include "renderer.h"
#include "ship.h"

#include <tuple>
#include <iostream>
#include <string>
#include <math.h>

Renderer::Renderer(const std::size_t screen_width, const std::size_t screen_height) : screen_width(screen_width), screen_height(screen_height) {
  
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Solar Runner", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();

};

void Renderer::RenderShip(Ship &ship) {
  
  // Set the color to be drawn
  SDL_SetRenderDrawColor(this->sdl_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  
  // Clear the screen: very inefficient, i.e. we must redraw everything on every single frame, but hell whatever
  SDL_RenderClear(this->sdl_renderer);
  
  //Setting the actual draw color.
  SDL_SetRenderDrawColor(this->sdl_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  
  // Get The necessary tuples
  std::tuple<int,int> nose_pos = ship.GetNosePos();
  std::tuple<int,int> ltip_pos = ship.GetLtipPos();
  std::tuple<int,int> rtip_pos = ship.GetRtipPos();
  
  // Drawing the lines we want: 
  // inspiration for implementation: https://gist.github.com/queercat/f8069b3b69178bdf3787d2b77f59551e
  // the input (described here: https://wiki.libsdl.org/SDL_RenderDrawLine)
  // 0: renderer | int x1 | int y1 | int x2 | int y2
  
  std::cout << std::get<0>(nose_pos) << " " << std::get<1>(nose_pos) << "\n";
  std::cout << std::get<0>(ltip_pos) << " " << std::get<1>(ltip_pos) << "\n";
  std::cout << std::get<0>(rtip_pos) << " " << std::get<1>(rtip_pos) << "\n";
  
  // Render Nose to Ltip
  SDL_RenderDrawLine(this->sdl_renderer, 
                     std::get<0>(nose_pos), std::get<1>(nose_pos), 
                     std::get<0>(ltip_pos), std::get<1>(ltip_pos));
  
  // Render ltip to rtip
  SDL_RenderDrawLine(this->sdl_renderer, 
                     std::get<0>(rtip_pos), std::get<1>(rtip_pos), 
                     std::get<0>(ltip_pos), std::get<1>(ltip_pos));
  
  // Render tip to rtip
  SDL_RenderDrawLine(this->sdl_renderer, 
                     std::get<0>(nose_pos), std::get<1>(nose_pos), 
                     std::get<0>(rtip_pos), std::get<1>(rtip_pos));
  
  //Update the Renderer.
  SDL_RenderPresent(this->sdl_renderer);
  
}

void Renderer::Render() {
  
  // Set the color to be drawn
  SDL_SetRenderDrawColor(this->sdl_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  
  // Clear the screen: very inefficient, i.e. we must redraw everything on every single frame, but hell whatever
  SDL_RenderClear(this->sdl_renderer);

  //this->RenderShip(ship);

  //Update the Renderer.
  SDL_RenderPresent(this->sdl_renderer);

}
