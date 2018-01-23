//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int greatestCommonDenominator(const int, const int);
int leastCommonMultiple(const int, const int);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//

int greatestCommonDenominator(const int a, const int b) {
if(a<=0 || b<=0)
return -1;
else {
int max = (a>b)? a : b;
int min = (a<b)? a : b;
int gcd = min;
while(max%min != 0)
{
gcd = max%min;
max = min;
min = gcd;
}
return gcd;
}
}

int leastCommonMultiple (const int a, const int b) {
if(a<=0 || b<=0)
return -1;
else {
int max = (a>b)? a : b;
int min = (a<b)? a : b;
int gcd = min;
while(max%min != 0)
{
gcd = max%min;
max = min;
min = gcd;
}
if (gcd < 0)
return -1;
else {
int lcm = (a/gcd)*b;
if (long(a)/gcd*b != lcm)
return -2;
else
return lcm;
} 
}
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
// This is required so that when you submit your code,
// this test driver will be ignored by Marmoset
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {

  if (argc < 3 || atoi(argv[1])!=atof(argv[1]) || atoi(argv[2])!=atof(argv[2])) {
    cerr << "Error: Usage: " << argv[0] << "<num1> <num2>; exiting" << endl;
    return -1;
  }

  int gcd = greatestCommonDenominator(atoi(argv[1]),atoi(argv[2]));
  if (gcd < 0)
    cerr << "Unable to compute GCD(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "GCD(" << argv[1] << "," << argv[2] << ") = " << gcd << endl;

  int lcm = leastCommonMultiple(atoi(argv[1]),atoi(argv[2]));
  if (lcm < 0)
    cerr << "Unable to compute LCM(" << argv[1] << "," << argv[2] << ")" << endl;
  else
    cout << "LCM(" << argv[1] << "," << argv[2] << ") = " << lcm << endl;


  return 0;
}

#endif
