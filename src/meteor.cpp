#include "meteor.h"

#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <math.h>  

Meteor::Meteor(std::tuple<int,int> location, int size, int speed) : location(location), size(size), speed(speed) {
  InitializeVertices();
};

void Meteor::InitializeVertices(){
  
  // Intialize the meteor's four vertices
  this->vertices.push_back(std::make_tuple(std::get<0>(this->location) - this->size, std::get<1>(this->location) - this->size));
  this->vertices.push_back(std::make_tuple(std::get<0>(this->location) + this->size, std::get<1>(this->location) - this->size));
  this->vertices.push_back(std::make_tuple(std::get<0>(this->location) + this->size, std::get<1>(this->location) + this->size));
  this->vertices.push_back(std::make_tuple(std::get<0>(this->location) - this->size, std::get<1>(this->location) + this->size));
  
};

void Meteor::Update() {
  // Only move the meteors downward, i.e. no rotation
  Move();
};

void Meteor::Move() {
  std::get<1>(location) += speed;
  for (int index = 0; index < vertices.size(); index++) {
    std::get<1>(vertices[index]) += speed;
  };
};
