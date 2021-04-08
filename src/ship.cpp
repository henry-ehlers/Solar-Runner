#include "ship.h"

#include <tuple>
#include <iostream>
#include <string>
#include <math.h>

// Constructor
Ship::Ship(int x_pos, int y_pos) : nose_angle(30 * 0.0174533), ship_length(10), fin_length(2) {
  this->cent_pos = std::make_tuple(x_pos, y_pos);
  this->SetShipWing();
  this->SetShipBase();
  this->SetShipNose();
  this->SetShipLtip();
  this->SetShipRtip();
}

// Calculate the Location of the Ship's nose based on x/y and height
void Ship::SetShipNose() {
  this->nose_pos = std::make_tuple(std::get<0>(cent_pos), std::get<1>(cent_pos) - ship_length/2);
}

// Calculate the location of the left wing tip based on height, nose_angle, and x/y position
void Ship::SetShipLtip(){
  if (this->base_length < 0) {this->SetShipBase();};
  this->ltip_pos = std::make_tuple(std::get<0>(cent_pos) - ship_length/2, std::get<1>(cent_pos) + base_length/2);
};

// Calculate the location of the right wing tip based on height, nose_angle, and x/y position
void Ship::SetShipRtip(){
  if (this->base_length < 0) {this->SetShipBase();};
  this->rtip_pos = std::make_tuple(std::get<0>(cent_pos) + ship_length/2, std::get<1>(cent_pos) + base_length/2);
};

// Calculate the wing length based on ship length and nose_angle
void Ship::SetShipWing(){
  this->wing_length = ship_length / std::sin(nose_angle/2);
};

// Calculate the length of the base based on ship length and nose_angle
void Ship::SetShipBase(){
  this->base_length = wing_length / std::cos(nose_angle);
};

