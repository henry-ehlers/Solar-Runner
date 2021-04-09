#ifndef RENDERER_H
#define RENDERER_H

#include "SDL.h"
#include "ship.h"
#include "meteor.h"

#include <memory>

class Renderer {
 
 public:
  
  // Constructor
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  
  // Desctructor
  ~Renderer();

  // Render the Ship (and meteors once implemented)
  void Render();
  
  // Individual Rendering functionn
  std::unique_ptr<Ship> RenderObject(std::unique_ptr<Ship> object);
  std::unique_ptr<Meteor> RenderObject(std::unique_ptr<Meteor> object);
  // Update the score
  void UpdateWindowTitle(int score, int fps);

 private:
  
  // SDL
  SDL_Window   *sdl_window;
  SDL_Renderer *sdl_renderer;

  // The Screen Height and Width to be rendered
  const std::size_t screen_width;
  const std::size_t screen_height;
  
};

#endif
