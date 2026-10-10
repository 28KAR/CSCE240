//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //

#include"program3functions.h"
#include<iostream>
#include <cstring>
using std::cout;

//  Removes all instances of an integer, replacing them with -999,
//  and pushing them to the back of the array.
void RemoveValues(int* array, int size, int numRemove) {

  //  Error check for invalid inputs
  if (size <= 0 || numRemove == -999) {
    return;
  }

  //  Checks and replaces all numRemove with -999
  for (int i = 0; i < size; i++) {
    if (array[i] == numRemove) {
      array[i] = -999;

      //  Shifts -999 to the back of the array
      for (int j = i; j < size - 1; j++) {
        if (array[j + 1] != -999) {
          array[j] = array[j + 1];
          array[j + 1] = -999;
        }
      }
    }
  }
  return;

}

//  Shifts values in an array a set number of positions,
//  left for positive, right for negative.
void ShiftArray(int* array, int size, int numMove) {

  //  Error check for invalid inputs
  if (size <= 0 || numMove == 0) {
    return;
  }

  //  Shifts left for positive, right for negative
  for (int i = 0; i < abs(numMove); i++) {
    if (numMove > 0) {
      int temp = array[0];
      for (int j = 0; j < size - 1; j++)
        array[j] = array[j + 1];
      array[size - 1] = temp;
    } else {
      int temp = array[size - 1];
      for (int j = size - 1; j > 0; j--)
        array[j] = array[j - 1];
      array[0] = temp;
    }
  }

}

//  Returns if two c-strings contain the exact same characters,
//  this does not require them to be in the same order.
bool IsAnagram(char const* a1, char const* a2, bool caseSensitive) {

  //  Converts constants into sortable arrays
  char* array1 = strdup(a1);
  char* array2 = strdup(a2);

  //  Converts chars to lowercase if not case sensitive
  if (!caseSensitive) {
    for (int i = 0; array1[i] != '\0'; i++) {
      if (array1[i] >= 'A' && array1[i] <= 'Z')
        array1[i] += 32;
      if (array2[i] >= 'A' && array2[i] <= 'Z')
        array2[i] += 32;
    }
  }

  //  Loops until both arrays are sorted
  bool exit = false;
  while (!exit) {
    exit = true;
    for (int i = 0; array1[i+1] != '\0'; i++) {
      if (array1[i] > array1[i + 1]) {
        char temp = array1[i];
        array1[i] = array1[i + 1];
        array1[i + 1] = temp;
      }
      if (array2[i] > array2[i + 1]) {
        char temp = array2[i];
        array2[i] = array2[i + 1];
        array2[i + 1] = temp;
      }
      cout << array1 << ", " << array2 << "\n";
    }
    for (int i = 0; array1[i+1] != '\0'; i++) {
      if (array1[i] > array1[i + 1] || array2[i] > array2[i + 1]) {
        exit = false;
      }
    }
  }

  return strcmp(array1, array2) == 0;

}

//  Replaces a specified array with two characters,
//  returns false and leaves unchanged if array too small.
bool Replace1With2(char* array, int size, char replaceA, char replaceB) {

  return true;

}

//  Swaps the values of the rows and columns.
void SwapRowsAndColumns(int** array, int rows, int cols) {

  return;

}