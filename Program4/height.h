#ifndef _HEIGHT_H_
#define _HEIGHT_H_

#include<string>
using std::string;
#include<iostream>
using std::ostream;
// Define a Height class that has private integer data members for the
//    height value - a non-negative real number (a double)
//    height units - allow for feet, inches, meters, and centimeters only
//                   (a string)
// The class should ensure that the data members always remain in a consistent
// state.

class Height {

  // Add a constructor to allow the user to initialize the value and units, in
  // that order, with default arguments of 0 and "feet"
  // If the first argument value is invalid, the height value should be
  // initialized to 0. If the second argument is invalid, the height units
  // should be initialized to feet.


  // Add mutator functions SetValue, and SetUnits that set the data member if
  // the argument is valid, and leave the data member unchanged if the argument
  // is invalid.


  // Add accessor functions GetValue and GetUnits that return
  // a copy of the value of the corresponding data member.


  // Add a ConvertUnits function that takes a string parameter for units to
  // convert the Height to. If the argument is valid, the object's value and
  // units should be updated to the equivalent height in the new units. For
  // example, if the Height object h has a value of 2 and units of "feet"
  // then after the function call h.ConvertUnits("inches"); h should have a
  // value of 24 and units of "inches"
  // If the argument sent to the function is not "feet" "inches" "meters"
  // or "centimeters" then the function should leave the object unchanged.
  // Please see testheight2.cc for more examples.


  // note: you are welcome to add any additional member functions you would
  //       like

};

// overload the stream insertion operator to display the height range in the
// format smallest height - largest height


// note: you are welcome to overload any other operators you would like

#endif
