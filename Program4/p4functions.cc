//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //

#include"p4functions.h"
#include"height.h"
// implement the SortHeights function (whose prototype is in p4functions.h)
// in this file

void SortHeights(Height * ptr, int num) {

  for (int i = 0; i < num - 1; i++) {
    for (int j = 0; j < num - i - 1; j++) {
      if (ptr[j + 1] <= ptr[j]) {
        Height temp = ptr[j];
        ptr[j] = ptr[j + 1];
        ptr[j + 1] = temp;
      }
    }
  }
  return;
}