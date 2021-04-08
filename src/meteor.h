#ifndef METEOR_H
#define METEOR_H

#include <tuple>

class Meteor {

public:
  
  Meteor(std::tuple<int,int> position, int radius, int speed, float rotation);
  
  //~Meteor(){}
  
  void Update();
  
private:
  
  std::tuple<int,int> cent_pos;
  std::tuple<int,int> vertex_1;
  std::tuple<int,int> vertex_2;
  std::tuple<int,int> vertex_3;
  std::tuple<int,int> vertex_4;
  float rotation;
  int radius;
  int speed;
  
  //
  void CalculateVertices();
  void Move();
  void Rotate();
  
};

#endif