//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2025  //
//  -------------------------------------  //

#include"program2functions.h"
#include<iostream>
#include<cmath>
using std::cout;
using std::min;
using std::max;

int ToClosestPrime(int n) {

  if (isPrime(n))
    return 0;
  
  for (int i = 1; true ; i++) {
    if (isPrime(n + i))
      return i;
    if (isPrime(n - i))
      return 0 - i;
  }

}

bool isPrime(int n) {

  // Exludes negative, zero, and even numbers, except for 2, which is prime
  if (n <= 1 || ((n > 2) && (n%2 == 0)))
    return false;
  if (n == 2) 
    return true;

  // Checks for any factors of n
  int cnt = 0;
  for (int i=3; i*i <= n; i += 2)
    if (n % i == 0)
      return false;
  
  return true;

}

void PrintPrimesBetween(int lowerBound, int upperBound, bool inputsIncluded) {

  int primeFound = false;
  if (inputsIncluded && isPrime(lowerBound)) {
    cout << lowerBound; primeFound = true;
  }
  for (int i = lowerBound + 1; i < upperBound; i++)
    if (isPrime(i))
      if (primeFound) 
        cout << ", "<< i;
      else {
        cout << i; primeFound = true;
      }
  if (inputsIncluded && isPrime(upperBound))
    if (primeFound) 
      cout << ", "<< upperBound;
    else
      cout << upperBound;
    
}

int LargestPrimeSequence(int arg) {

  if (isPrime(arg))
    return arg;
  if (arg % 10 == arg)
    return -1;

  int leftHalf = arg / 10;
  int rightHalf =
    (arg %static_cast<int>(pow(10, static_cast<int>(log10(arg)))));

  return (max(LargestPrimeSequence(leftHalf), LargestPrimeSequence(rightHalf)));

}

void PrintAsDollarsAndCents(int arg) {

  cout << "$" << arg / 100 << "." << (arg % 100) / 10 << arg % 10;

}

class Bills {
  public:
    int value;
    int& count;
};

bool MakePurchase(int cost, int& twenties, int& tens, int& fives, int& ones,
  int& quarters, int& dimes, int& nickels, int& pennies) {

  // Checks if purchase is too expensive
  if (cost > (twenties*2000 + tens*1000 + fives*500 + ones*100 +
    quarters*25 + dimes*10 + nickels*5 + pennies))
    return false;

  // Converts money into an array of Bill objects for easier manipulation
  Bills bills[8] = {{2000, twenties}, {1000, tens}, {500, fives}, {100, ones},
    {25, quarters}, {10, dimes}, {5, nickels}, {1, pennies}};

  for (int i = 0; i < 8 && cost > 0; i++) {

    // Checks for the smallest bill that can pay the cost
    if (cost <= 2000 && twenties >= 1)
      i = 0;
    if (cost <= 1000 && tens >= 1)
      i = 1;
    if (cost <= 500 && fives >= 1)
      i = 2;
    if (cost <= 100 && ones >= 1)
      i = 3;
    if (cost <= 25 && quarters >= 1)
      i = 4;
    if (cost <= 10 && dimes >= 1)
      i = 5;
    if (cost <= 5 && nickels >= 1)
      i = 6;
    if (cost <= 1 && pennies >= 1)
      i = 7;

    // Pays as many of the current bill as possible, then rechecks
    if (bills[i].count > 0) {
      int numBills =
        max(1,min(static_cast<int>(cost / bills[i].value), bills[i].count));
      cost -= numBills * bills[i].value;
      bills[i].count -= numBills;
    }
  }

  if (cost == 0)
    return true;
  
  // If the cost is negative, gives change
  cost *= -1;
  for (int i = 0; i < 8 && cost > 0; i++) {

    // Pays back as many of the current bill as possible, then rechecks
    if (cost >= bills[i].value) {
      int numBills = static_cast<int>(cost / bills[i].value);
      cost -= numBills * bills[i].value;
      bills[i].count += numBills;
    }
  }

  return true;

}