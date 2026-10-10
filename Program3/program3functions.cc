//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //

#include "program3functions.h"
#include "p3compares.h"
#include <iostream>
using std::equal;
using std::begin;
using std::end;

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

  //  Makes character counting arrays
  int arr1[50] = {0}, arr2[50] = {0};

  //  Counts each instance of each character in both strings
  if (caseSensitive) {
    for (int i = 0; a1[i] != '\0'; i++) {
      if (a1[i] >= 65 && a1[i] <= 90)
        arr1[a1[i] - 65]++;
      if (a1[i] >= 97 && a1[i] <= 122)
        arr1[a1[i] - 72]++;
    }
    for (int i = 0; a2[i] != '\0'; i++) {
      if (a2[i] >= 65 && a2[i] <= 90)
        arr2[a2[i] - 65]++;
      if (a2[i] >= 97 && a2[i] <= 122)
        arr2[a2[i] - 72]++;
    }
  } else {
    for (int i = 0; a1[i] != '\0'; i++) {
      if (a1[i] >= 65 && a1[i] <= 90)
        arr1[a1[i] - 65]++;
      if (a1[i] >= 97 && a1[i] <= 122)
        arr1[a1[i] - 97]++;
    }
    for (int i = 0; a2[i] != '\0'; i++) {
      if (a2[i] >= 65 && a2[i] <= 90)
        arr2[a2[i] - 65]++;
      if (a2[i] >= 97 && a2[i] <= 122)
        arr2[a2[i] - 97]++;
    }
  }

  //  Compares final character counts
  return equal(begin(arr1), end(arr1), begin(arr2));

}
//  Replaces a specified array with two characters,
//  returns false and leaves unchanged if array too small.
bool Replace1With2(char* array, int size, char find, char replaceA, char replaceB) {

  //  Tests if the size is large enough for the replacement
  int replaceCount = 0;
  int emptyCount = 0;

  for (int i = 0; i < size; i++) {
    if (array[i] == find) {
      replaceCount++;
    }
    if (array[i] == '\0') {
      emptyCount++;
    }
  }
  
  if (replaceCount >= emptyCount)
    return false;
 
  //  Replaces the character, shifts the remaining array, then replaces the second character
  for (int i = 0; i < size; i++) {
    if (array[i] == find) {
      array[i] = replaceA;
      int temp = array[i + 1];
      for (int j = i+2; j < (size - 1); j++) {
        int temp2 = array[j];
        array[j] = temp;
        temp = temp2;
      }
      array[i + 1] = replaceB;
    }
  }

  return true;

}

//  Swaps the values of the rows and columns.
void SwapRowsAndColumns(int array[kSquareSize][kSquareSize]) {

  int temp[kSquareSize][kSquareSize];

  for (int i = 0; i < kSquareSize; i++) {  
    for (int j = 0; j < kSquareSize; j++) {
      temp[j][i] = array[i][j];
    }
  }
  for (int i = 0; i < kSquareSize; i++) {  
    for (int j = 0; j < kSquareSize; j++) {
      array[i][j] = temp[i][j];
    }
  }

  return;

}