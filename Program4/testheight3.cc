// Copyright 2026 bhipp
// Initial <= tests for the Height class
#include<iostream>
using std::cout;
using std::endl;
#include"height.h"

int main() {
  const Height kHeight1(2, "feet"), kHeight2(25, "inches"),
        kHeight3(24, "inches");

  if ( kHeight1 <= kHeight2 ) {
    cout << "Passed <= test 1" << endl;
  } else {
    cout << "Failed <= test 1."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  if ( !(kHeight2 <= kHeight1) ) {
    cout << "Passed <= test 2" << endl;
  } else {
    cout << "Failed <= test 2."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  if ( kHeight1 <= kHeight3 ) {
    cout << "Passed <= test 3" << endl;
  } else {
    cout << "Failed <= test 3."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  if ( kHeight3 <= kHeight1 ) {
    cout << "Passed <= test 4" << endl;
  } else {
    cout << "Failed <= test 4."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  const Height kHeight4(300, "centimeters"), kHeight5(5, "meters"),
        kHeight6(3, "meters");

  if ( kHeight4 <= kHeight5 ) {
    cout << "Passed <= test 5" << endl;
  } else {
    cout << "Failed <= test 5."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  if ( !(kHeight5 <= kHeight4) ) {
    cout << "Passed <= test 6" << endl;
  } else {
    cout << "Failed <= test 6."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  if ( kHeight4 <= kHeight6 ) {
    cout << "Passed <= test 7" << endl;
  } else {
    cout << "Failed <= test 7."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  if ( kHeight6 <= kHeight4 ) {
    cout << "Passed <= test 8" << endl;
  } else {
    cout << "Failed <= test 8."
         << "Read code in testheight3.cc to view the comparison." << endl;
  }

  return 0;
}

