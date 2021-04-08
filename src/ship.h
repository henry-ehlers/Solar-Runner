#ifndef SHIP_H
#define SHIP_H

#include <tuple>
#include "renderer.h"

class Ship {
  
public:
  
  Ship(int x_pos, int y_pos);
  ~Ship();
  
private:
  
  // Set Ship Constants
  float const nose_angle = 30 * 0.0174533; // to radians
  int const ship_length = 10;
  int const fin_length = 2;
  
  // The Ship's locations in 2D space
  int x_pos;
  int y_pos;
  int base_length{-1};
  float wing_length{-1};
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