//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;


// Sample function for which you need to find the root

float f(const float x) {
  return 3.2*x*x*x - 2.1*x - 23.0;
}

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

float bisectionHelper(const float left, const float right,
		      const float precision, const float minIntervalSize,int lim);
float bisection(const float left, const float right,
		const float precision, const float minIntervalSize);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

float bisectionHelper(const float left, const float right, const float precision, const float minIntervalSize, int lim) {
if((left>right) || (f(left)*f(right)>0) || (precision<0.0) || (minIntervalSize<=0.0) ||  isNaN(left) || isNaN(right) || isNaN(f(right)) || isNaN(f(left)) )
return std::numeric_limits<float>::quiet_NaN();
if(lim == 0)
return std::numeric_limits<float>::quiet_NaN();
float midpoint = (left+right)/2.0;
if(fabs(f(midpoint)-0)<=precision || right-left < minIntervalSize) {
return midpoint;
}
if(f(midpoint)*f(left)>0)
return bisectionHelper(midpoint,right,precision,minIntervalSize,--lim);
else
return bisectionHelper(left,midpoint,precision,minIntervalSize,--lim);
}

float bisection(const float left, const float right, const float precision, const float minIntervalSize) {
return bisectionHelper(left,right,precision,minIntervalSize,1000);
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
cout << bisection(0,20,0.002,0.0001)<<endl;
return 0;
}

#endif
