#include "meteor.h"

Meteor::Meteor(std::tuple<int,int> position, int radius, int speed, float rotation) {
  this->cent_pos = position;
  this->rotation = rotation;
  this->radius   = radius;
  this->speed    = speed;
};

void Meteor::SetVertices(){
  // see https://stackoverflow.com/questions/686353/random-float-number-generation
  //float random_initial_rotation = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360));
  float random_initial_rotation = 0;
  vertex_1 = std::make_tuple(std::get<0> - radius, std::get<1> - radius);
  vertex_2 = std::make_tuple(std::get<0> + radius, std::get<1> - radius);
  vertex_3 = std::make_tuple(std::get<0> + radius, std::get<1> + radius);
  vertex_4 = std::make_tuple(std::get<0> - radius, std::get<1> + radius);
};

void Meteor::Rotate(){
  // outlined here: https://www.gamedev.net/forums/topic/532033-how-to-rotate-a-square-by-an-ngle-image/
};