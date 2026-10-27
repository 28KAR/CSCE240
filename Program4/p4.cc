// Copyright 2026 - started by Hipp, finished by ______
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include"height.h"
#include"p4functions.h"

int main() {
  int current_size = 5, current_position = 0;
  // ptr points to a block of dynamically allocated
  // memory - you will need to properly manage this
  // memory, allocating and deallocating as needed,
  // ensuring that there are no memory leaks
  Height * ptr = new Height[current_size];
  string another, height_unit;
  double height_value;

  // user enters a height value and unit (DON'T prompt/ask for this)
  cin >> height_value >> height_unit;

  ptr[current_position].SetValue(height_value);
  ptr[current_position].SetUnits(height_unit);

  // user enters "yes" if they'd like to enter another height
  // (DON'T prompt/ask for this)
  cin >> another;

  // continue to get heights while the user enters "yes"

  SortHeights(ptr, current_position);

  for ( int i = 0; i < current_position; ++i )
    cout << ptr[i] << (i < current_position - 1?", ":"");
  cout << endl;
  return 0;
}
