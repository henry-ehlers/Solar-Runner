#ifndef METEOR_H
#define METEOR_H

#include "object.h"
#include <tuple>
#include <vector>

class Meteor : public Object {

public:
  
  // Constructor
  Meteor(std::tuple<int,int> location, std::tuple<int,int> bounds, int size, int speed, float rotation);
  //~Meteor(){}
  
  // Setters
  void SetSpeed(int speed) { this->speed = speed; };
  
  // Getters
  
protected:
  
  //
  void InitializeVertices();
  
  // Fields required in addition to those of the 'Object' class
  float rotation;
  int size;
  
  // Update-Specific methods
  void Move();
  void Rotate();
  
};

#endif