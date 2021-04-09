#include "ship.h"

#include <tuple>
#include <iostream>
#include <string>
#include <math.h>

// Constructor
Ship::Ship(const std::tuple<int,int> xy_bounds) : nose_angle(30 * 0.0174533), ship_length(10), fin_length(2) {
  this->bounds   = std::make_tuple(std::get<0>(xy_bounds), std::get<1>(xy_bounds));
  this->location = std::make_tuple(std::get<0>(xy_bounds)/2, std::get<1>(xy_bounds)-(4*ship_length));
  this->speed = 5;
  this->SetShipWing();
  this->SetShipBase();
  this->InitializeVertices();
};

void Ship::InitializeVertices() {
  this->vertices.push_back(this->SetShipNose());
  this->vertices.push_back(this->SetShipRtip());
  this->vertices.push_back(this->SetShipLtip());
}

// Calculate the Location of the Ship's nose based on x/y and height
std::tuple<int,int> Ship::SetShipNose() {
  return (std::make_tuple(std::get<0>(location), std::get<1>(location) - ship_length/2));
};

// Calculate the location of the left wing tip based on height, nose_angle, and x/y position
std::tuple<int,int> Ship::SetShipLtip(){
  if (this->base_length < 0) {this->SetShipBase();};
  return(std::make_tuple(std::get<0>(location) - ship_length/2, std::get<1>(location) + base_length/2));
};

// Calculate the location of the right wing tip based on height, nose_angle, and x/y position
std::tuple<int,int> Ship::SetShipRtip(){
  if (this->base_length < 0) {this->SetShipBase();};
  return(std::make_tuple(std::get<0>(location) + ship_length/2, std::get<1>(location) + base_length/2));
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
  std::cout << "BANK LEFT: \n";
  if (std::get<0>(vertices[2]) >= (0+20) ) {
    UpdateInformation((-speed));
  } else {
    std::cout << "Something is wrong on the left\n";
  }
};

void Ship::BankRight() {
  std::cout << "BANK RIGHT: \n";
  if (std::get<0>(vertices[1]) <= (std::get<0>(bounds)-20) ) {
    UpdateInformation(speed);
  } else {
    std::cout << "Something is wrong on the right\n";
  }
};

void Ship::UpdateInformation(int x_delta) {
  std::cout << "delta x: " << x_delta << "\n";
  for (std::tuple<int,int> &vertex : vertices) {
    std::get<0>(vertex) += x_delta;
  }
};