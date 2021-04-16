#ifndef SHIP_H
#define SHIP_H

#include "object.h"
#include "meteor.h"

#include <memory>
#include <tuple>
#include <vector>
/*
DO NOT INCLUDE RENDERER HERE. it cause a cyclic dependence as outline here:
https://stackoverflow.com/questions/23347826/classes-have-not-been-declared-but-they-were-included
*/

class Ship : public Object {
  
public:
  
  // Concstructor and Destructor
  Ship(const std::tuple<int,int> xy_bounds);
  ~Ship(){};
  
  void Update();
  
  // Setters
  void InitializeVertices();
  
  // Getters
  
  // Update based on player input
  void BankLeft();
  void BankRight();
  
protected:
  
  // Set Ship Constants
  float nose_angle; // to radians
  int ship_length ;
  int fin_length;
  
  // The Ship's locations in 2D space
  int base_length{-1};
  float wing_length{-1};
  
  // Define Ship's Critical Points
  std::tuple<int,int> SetShipNose();
  std::tuple<int,int> SetShipLtip();
  std::tuple<int,int> SetShipRtip();
  
  void SetShipWing();
  void SetShipBase();
  
  // Change Stuff
  void UpdateInformation(int x_delta);

};

#endif