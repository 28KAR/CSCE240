//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //

#include"height.h"
#include<iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ostream;

//  Constructor
Height::Height(double value, string units) {

  if (value < 0)
    this->value = 0;
  else
    this->value = value;
  if ((units == "feet") || (units == "inches") ||
      (units == "meters") || (units == "centimeters"))
    this->units = units;
  else
    this->units = "feet";

}

//  Mutators
void Height::SetValue(double value) {
  if (value < 0)
    return;
  this->value = value;
}

void Height::SetUnits(string units) {
  if ((units == "feet") || (units == "inches") ||
      (units == "meters") || (units == "centimeters"))
    this->units = units;
  return;
}

//  Accessors
double Height::GetValue() const {
  return this->value;
}

string Height::GetUnits() const {
  return this->units;
}

//  Converts height from one unit to another
void Height::ConvertUnits(string units) {

  if (this->units == units)
    return;

  if (this->units == "feet") {

    if (units == "inches")
      this->value *= 12;
    if (units == "centimeters")
      this->value *= 30.48;
    if (units == "meters")
      this->value *= 0.3048;
    this->units = units;
    return;
  }

  if (this->units == "inches") {

    if (units == "feet")
      this->value /= 12;
    if (units == "centimeters")
      this->value *= 2.54;
    if (units == "meters")
      this->value *= 0.0254;
    this->units = units;
    return;
  }

  if (this->units == "meters") {
    if (units == "inches")
      this->value /= 0.0254;
    if (units == "feet")
      this->value /= 0.3048;
    if (units == "centimeters")
      this->value *= 100;
    this->units = units;
    return;
  }

  if (this->units == "centimeters") {
    if (units == "inches")
      this->value /= 2.54;
    if (units == "feet")
      this->value /= 30.48;
    if (units == "meters")
      this->value /= 100;
    this->units = units;
    return;
  }
  return;

}

// Overloading
ostream& operator << (ostream& where, const Height& h) {
    where << h.GetValue() << " " << h.GetUnits();
    return where;
}

bool operator <= (const Height& h1, const Height& h2) {
    Height h1_copy = h1, h2_copy = h2;
    h1_copy.ConvertUnits("inches");
    h2_copy.ConvertUnits("inches");
    return (h1_copy.GetValue() <= h2_copy.GetValue());
}