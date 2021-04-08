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

void Renderer::RenderShip() {
  
  // Set the color to be drawn
  SDL_SetRenderDrawColor(this->sdl_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  
  // Clear the screen: very inefficient, i.e. we must redraw everything on every single frame, but hell whatever
  SDL_RenderClear(this->sdl_renderer);
  
  //Setting the actual draw color.
  SDL_SetRenderDrawColor(this->sdl_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  
  // Get Location and Shape of ship (placeholder)
  int center_x = 320/2;
  int center_y = 640/2;
  float nose_angle = 35 * 0.0174533; // to radians
  int ship_length = 10;
  int fin_length = 2;
  int body_length = ship_length - fin_length;
  float wing_length = ship_length / std::sin(nose_angle/2);
  int base_length = wing_length / std::cos(nose_angle);
  
  
  std::tuple<int, int> nose_pos = std::make_tuple(center_x                , center_y - ship_length/2);
  std::tuple<int, int> lfin_pos = std::make_tuple(center_x - ship_length/2, center_y + base_length/2);
  std::tuple<int, int> rfin_pos = std::make_tuple(center_x + ship_length/2, center_y + base_length/2);
  
  // Drawing the lines we want: 
  // inspiration for implementation: https://gist.github.com/queercat/f8069b3b69178bdf3787d2b77f59551e
  // the input (described here: https://wiki.libsdl.org/SDL_RenderDrawLine)
  // 0: renderer | int x1 | int y1 | int x2 | int y2
  
  std::cout << std::get<0>(nose_pos) << " " << std::get<1>(nose_pos) << "\n";
  std::cout << std::get<0>(lfin_pos) << " " << std::get<1>(lfin_pos) << "\n";
  std::cout << std::get<0>(rfin_pos) << " " << std::get<1>(rfin_pos) << "\n";
  
  SDL_RenderDrawLine(this->sdl_renderer, 
                     std::get<0>(nose_pos), std::get<1>(nose_pos), 
                     std::get<0>(lfin_pos), std::get<1>(lfin_pos));
  SDL_RenderDrawLine(this->sdl_renderer, 
                     std::get<0>(rfin_pos), std::get<1>(rfin_pos), 
                     std::get<0>(lfin_pos), std::get<1>(lfin_pos));
  SDL_RenderDrawLine(this->sdl_renderer, 
                     std::get<0>(nose_pos), std::get<1>(nose_pos), 
                     std::get<0>(rfin_pos), std::get<1>(rfin_pos));
  
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
