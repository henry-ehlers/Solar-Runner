#ifndef OBJECT_H
#define OBJECT_H

#include <tuple>
#include <vector>

// Abstract Parent Class of all renderable object (i.e. Meteor and Ship)
class Object {

public:
  
  // Key Virtual functions required for game ticks and intialization
  void Update();
  
  // Getters
  std::vector<std::tuple<int,int>> GetVertices() { return this->vertices; };
  std::tuple<int,int> GetLocation() { return this->location; } 
  
  // Setters
  virtual void SetSpeed() = 0;
  
protected:
  
  // Key Virtual functions required for game ticks and intialization
  virtual void InitializeVertices() = 0;
  
  // Key Fields required for a renderable object in this game
  std::vector<std::tuple<int,int>> vertices;
  std::tuple<int,int> location;
  std::tuple<int,int> bounds;
  int speed;
  
};

#endif
