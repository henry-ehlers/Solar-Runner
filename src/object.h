#ifndef OBJECT_H
#define OBJECT_H

#include <tuple>
#include <vector>

// Abstract Parent Class of all renderable object (i.e. Meteor and Ship)
// Following some of the notes of virtual functions outlined here:
// https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/
class Object {

public:
  
  //virtual ~Object() = 0;
  
  // Key Virtual functions required for game ticks and intialization
  virtual void Update() = 0;
  
  // Getters
  std::vector<std::tuple<int,int>> GetVertices() { return this->vertices; };
  std::tuple<int,int> GetLocation() { return this->location; } 
  
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
