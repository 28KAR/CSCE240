//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //

#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_

// write functions here
void RemoveValues(int* array, int size, int numRemove);

void ShiftArray(int* array, int size, int numMove);

bool IsAnagram(char const* a1, char const* a2, bool caseSensitive = false);

bool Replace1With2(char* array, int size, char replaceA, char replaceB);

void SwapRowsAndColumns(int** array, int rows, int cols);

#endif