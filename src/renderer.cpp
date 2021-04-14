#include "renderer.h"
#include "ship.h"

#include <vector>
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

void Renderer::ClearScreen() {
  
  // Clear the screen: very inefficient, i.e. we must redraw everything on every single frame, but hell whatever
  SDL_SetRenderDrawColor(this->sdl_renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(this->sdl_renderer);
  
};

std::unique_ptr<Ship> Renderer::RenderObject(std::unique_ptr<Ship> object) {
  
  //Setting the actual draw color.
  SDL_SetRenderDrawColor(this->sdl_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  
  // Get The necessary tuples
  std::vector<std::tuple<int,int>> vertices = object.get()->GetVertices();
  
  // Iterate over each of the vertices
  for (int index = 0; index < size(vertices); index++) {
    
    // Drawing the lines we want: 
    // inspiration for implementation: https://gist.github.com/queercat/f8069b3b69178bdf3787d2b77f59551e
    // the input (described here: https://wiki.libsdl.org/SDL_RenderDrawLine)
    // 0: renderer | int x1 | int y1 | int x2 | int y2
    SDL_RenderDrawLine(this->sdl_renderer, 
                       std::get <0> ( vertices[ index ] ), 
                       std::get <1> ( vertices[ index ] ), 
                       std::get <0> ( vertices[(index + 1) % size(vertices)] ), 
                       std::get <1> ( vertices[(index + 1) % size(vertices)] ) 
     );
  };
  
  //Update the Renderer.
  SDL_RenderPresent(this->sdl_renderer);
  
  return std::move(object);
}

std::unique_ptr<Meteor> Renderer::RenderObject(std::unique_ptr<Meteor> object) {
                                                                                             
  //Setting the actual draw color.
  SDL_SetRenderDrawColor(this->sdl_renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
  
  // Get The necessary tuples
  std::vector<std::tuple<int,int>> vertices = object.get()->GetVertices();

  std::cout << object.get() << "\n";
  for (int index = 0; index < size(vertices); index++) {
    std::cout << "index " << index << ": (" << std::get<0>(vertices[index]) << ", " << std::get<1>(vertices[index]) << ")\n"; 
  };
               
  // Iterate over the ordered indeces and draw their lines
  for (int index = 0; index < size(vertices); index++) {
    
    // Drawing the lines we want: 
    SDL_RenderDrawLine(this->sdl_renderer, 
                       std::get <0> ( vertices[ index ] ), 
                       std::get <1> ( vertices[ index ] ), 
                       std::get <0> ( vertices[(index + 1) % size(vertices)] ), 
                       std::get <1> ( vertices[(index + 1) % size(vertices)] ) 
     );
    
  };
  
  //Update the Renderer.
  SDL_RenderPresent(this->sdl_renderer);
  
  return std::move(object);

};
                                                                                                                                                                                                                 

                             