// Copyright 2026 bhipp
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"height.h"
#include"p4functions.h"

int main() {
  Height h[] = { Height(100, "feet"), Height(200, "inches"),
                 Height(150, "meters"), Height(100, "centimeters"),
                 Height(0.5, "meters"), Height(100, "inches"),
                 Height(10), Height(0.5) };
  const Height correct[] = { Height(0.5), Height(0.5, "meters"),
                             Height(100, "centimeters"), Height(100, "inches"),
                             Height(10), Height(200, "inches"),
                             Height(100), Height(150, "meters") };

  SortHeights(h, 8);

  bool all_correct = true;
  for ( int i = 0; all_correct && i < 8; ++i )
    all_correct = (h[i].GetValue() == correct[i].GetValue() &&
                   h[i].GetUnits() == correct[i].GetUnits());

  if ( all_correct ) {
    cout << "Passed sample SortHeights test!" << endl;
  } else {
    cout << "Failed sample SortHeights test\nResults of your sort:\n";
    for ( int i = 0; i < 8; ++i )
      cout << h[i] << (i < 7 ? ", " : "");
    cout << endl;
  }
  return 0;
}
