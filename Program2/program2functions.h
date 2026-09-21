//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //

#ifndef _MY_FUNCTIONS_H_
#define _MY_FUNCTIONS_H_
// write functions here

int ToClosestPrime(int n);

bool isPrime(int n);

void PrintPrimesBetween(int lowerBound, int upperBound, bool inputsIncluded = false);

int LargestPrimeSequence(int arg);

void PrintAsDollarsAndCents(int arg);


bool MakePurchase(int purchaseCost, int& twenties, int& tens, int& fives, int& ones,
  int& quarters, int& dimes, int& nickels, int& pennies);

#endif