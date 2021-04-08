#include "ship.h"

#include <tuple>
#include <iostream>
#include <string>
#include <math.h>

// Constructor
Ship::Ship(int x_bound, int y_bound) : nose_angle(30 * 0.0174533), ship_length(10), fin_length(2), speed(5) {
  this->dim_bounds = std::make_tuple(x_bound, y_bound);
  this->cent_pos = std::make_tuple(x_bound/2, y_bound-4*ship_length);
  this->SetShipWing();
  this->SetShipBase();
  this->SetShipNose();
  this->SetShipLtip();
  this->SetShipRtip();
};

// Calculate the Location of the Ship's nose based on x/y and height
void Ship::SetShipNose() {
  this->nose_pos = std::make_tuple(std::get<0>(cent_pos), std::get<1>(cent_pos) - ship_length/2);
};

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

//
void Ship::BankLeft() {
  if (std::get<0>(ltip_pos) >= (0+20) ) {
    UpdateInformation(-speed);
  } else {
    std::cout << "Something is wrong on the left\n";
  }
};

void Ship::BankRight() {
  if (std::get<0>(rtip_pos) <= (std::get<0>(dim_bounds)-20) ) {
    UpdateInformation(speed);
  } else {
    std::cout << "Something is wrong on the right\n";
  }
};

void Ship::UpdateInformation(float x_delta) {
  std::get<0>(nose_pos) += x_delta;
  std::get<0>(ltip_pos) += x_delta;
  std::get<0>(rtip_pos) += x_delta;
};