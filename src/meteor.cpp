#include "meteor.h"

#include <tuple>
#include <vector>

Meteor::Meteor(std::tuple<int,int> location, std::tuple<int,int> bounds, int size, int speed, float rotation) {
  this->location = location;
  this->bounds   = bounds; 
  this->rotation = rotation;
  this->speed    = speed;
  InitializeVertices();
};

void Meteor::InitializeVertices(){
  
  // Initialization ignored, despite the discussion and code example here:
  // https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
  // Problems with tuples seemingly
  // see https://stackoverflow.com/questions/686353/random-float-number-generation
  //float random_initial_rotation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360));
  float random_initial_rotation = 0;
  
  vertices.push_back(std::make_tuple(std::get<0>(location) - size, std::get<1>(location) - size));
  vertices.push_back(std::make_tuple(std::get<0>(location) + size, std::get<1>(location) - size));
  vertices.push_back(std::make_tuple(std::get<0>(location) + size, std::get<1>(location) + size));
  vertices.push_back(std::make_tuple(std::get<0>(location) - size, std::get<1>(location) + size));
  
};

void Meteor::Rotate(){
  // outlined here: https://www.gamedev.net/forums/topic/532033-how-to-rotate-a-square-by-an-ngle-image/
};
