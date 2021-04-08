#ifndef METEOR_H
#define METEOR_H

class Meteor {

public:
  
  Meteor(float x_pos, float y_pos, int size) : x_pos(x_pos), y_pos(y_pos), size(size) {}
  
  
  ~Meteor(){}
  
private:
  
  float x_pos;
  float y_pos;
  float trajectory;
  int size;
  
};

#endif