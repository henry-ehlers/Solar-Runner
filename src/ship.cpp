#include "ship.h"
#include <tuple>
#include <iostream>
#include <string>
#include <math.h>

Ship::Ship(int x_pos, int y_pos) : x_pos(x_pos), y_pos(y_pos) {
  this->SetShipWing();
  this->SetShipBase();
  this->SetShipNose();
  this->SetShipLtip();
  this->SetShipRtip();
}

void Ship::SetShipNose() {
  this->nose_pos = std::make_tuple(x_pos, y_pos - ship_length/2);
}

void Ship::SetShipLtip(){
  if (this->base_length < 0) {this->SetShipBase();};
  this->ltip_pos = std::make_tuple(x_pos - ship_length/2, y_pos + base_length/2);
};

void Ship::SetShipRtip(){
  if (this->base_length < 0) {this->SetShipBase();};
  this->rtip_pos = std::make_tuple(x_pos + ship_length/2, y_pos + base_length/2);
};

void Ship::SetShipWing(){
  this->wing_length = ship_length / std::sin(nose_angle/2);
};

void Ship::SetShipBase(){
  this->base_length = wing_length / std::cos(nose_angle);
};

