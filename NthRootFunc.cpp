//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

float NthRoot(const float S, const int N, const float precision);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the Nth root of S with
// precision.
//

float NthRoot(const float S, const int N, const float precision) {
if ((S < 0 && N%2 == 0) || N < 2 || precision <=0)
return std::numeric_limits<float>::quiet_NaN();
else {
float ans= S/N;
float tmp = 1.0;
for(int i=1;i<=N;i++)
{
tmp=tmp*ans;
}
float calculated_precision = (S-tmp)/S; 
if (calculated_precision < 0) 
calculated_precision = -1*calculated_precision;
int count = 0; 
while (calculated_precision > precision) 
{
tmp = 1.0;
for(int i=1;i<=N-1;i++)
{
tmp = tmp*ans;
}
ans = ans*(N-1)/N + S/(N*tmp);
float tmp1 = 1.0;
for(int i=1;i<=N;i++)
{
tmp1 = tmp1*ans;
}
if(calculated_precision == (S - tmp1)/S)
break;
calculated_precision = (S - tmp1)/S;
if (calculated_precision < 0) 
calculated_precision = -1*calculated_precision;
count ++;
}
return ans;
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  if (argc < 4) {
    cerr << "Error: Usage: " << argv[0] << " <number> <root> <precision>; exiting" << endl;
    return -1;
  }

  float root = NthRoot(atof(argv[1]),atoi(argv[2]),atof(argv[3]));
  if (isNaN(root))
    cerr << "Unable to compute " << argv[2] << "th root of " << argv[1] << " with precision " << argv[3] << endl;
  else
    cout << "Root(" << argv[1] << "," << argv[2] << ") = " << root << endl
	 << "(with precision " << argv[3] << ")" << endl; 

  return 0;
}

#endif
