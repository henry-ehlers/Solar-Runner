#ifndef SHIP_H
#define SHIP_H

#include <tuple>

/*
DO NOT INCLUDE RENDERER HERE. it cause a cyclic dependence as outline here:
https://stackoverflow.com/questions/23347826/classes-have-not-been-declared-but-they-were-included
*/

class Ship {
  
public:
  
  // Concstructor and Destructor
  Ship(int x_pos, int y_pos);
  //~Ship();
  
  // Getters
  std::tuple<int,int> GetNosePos(){return this->nose_pos;};
  std::tuple<int,int> GetLtipPos(){return this->ltip_pos;};
  std::tuple<int,int> GetRtipPos(){return this->rtip_pos;};
  
  // Update based on player input
  
private:
  
  // Set Ship Constants
  float nose_angle; // to radians
  int ship_length ;
  int fin_length;
  
  // The Ship's locations in 2D space
  int base_length{-1};
  float wing_length{-1};
  std::tuple<int,int> cent_pos;
  std::tuple<int,int> nose_pos;
  std::tuple<int,int> ltip_pos;
  std::tuple<int,int> rtip_pos;
  
  // Define Ship's Critical Points
  void SetShipNose();
  void SetShipLtip();
  void SetShipRtip();
  void SetShipWing();
  void SetShipBase();

};

#endif