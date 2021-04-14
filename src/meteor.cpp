#include "meteor.h"

#include <iostream>
#include <tuple>
#include <vector>
#include <cmath>
#include <math.h>  

Meteor::Meteor(std::tuple<int,int> location, int size, int speed) {
  this->location = location;
  this->bounds   = bounds; 
  this->speed    = speed;
  InitializeVertices();
};

void Meteor::InitializeVertices(){
  
  // Initialization ignored, despite the discussion and code example here:
  // https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
  // Problems with tuples seemingly
  // see https://stackoverflow.com/questions/686353/random-float-number-generation
  //float random_initial_rotation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360));
  vertices.push_back(std::make_tuple(std::get<0>(location) - size, std::get<1>(location) - size));
  vertices.push_back(std::make_tuple(std::get<0>(location) + size, std::get<1>(location) - size));
  vertices.push_back(std::make_tuple(std::get<0>(location) + size, std::get<1>(location) + size));
  vertices.push_back(std::make_tuple(std::get<0>(location) - size, std::get<1>(location) + size));
  
};

void Meteor::Update() {
  Move();
};

void Meteor::Move() {
  std::get<1>(location) += speed;
  for (int index = 0; index < vertices.size(); index++) {
    std::get<1>(vertices[index]) += speed;
  };
};
