#ifndef METEOR_H
#define METEOR_H

#include "object.h"
#include <tuple>
#include <vector>

class Meteor : public Object {

public:
  
  // Constructor
  Meteor(std::tuple<int,int> location, int size, int speed);
  
  void Update();
  
  // Getters
  std::tuple<int,int> GetLocation(){return(this->location);}
  int GetUpperY(){return(std::get<1>(this->location) - this->size);}
  
protected:
  
  //
  void InitializeVertices();
  
  // Fields required in addition to those of the 'Object' class
  float rotation;
  int size;
  
  // Update-Specific methods
  void Move();
  
};

#endif