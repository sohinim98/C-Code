//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return std::numeric_limits<float>::quiet_NaN() (comes from
// <limits>) if cannot compute the root for some reason
//

bool projectileDestination(const float h, const float v, const float m,
                           const float theta, const float d,
                           const float t, const float b, const float w,
                           float& destX, float& destY) {
if(v < 0.0 || h < 0.0 || t < 0.0 || d < 0.0 || b < 0.0 || w < 0.0)
return false;
float angle = (theta * M_PI)/180.0;
float x = 0.0, y = 0.0;
float g = 9.8;
float vx = v*cos(angle), vy = v*sin(angle);
float time = ((2*vy)+sqrt(4*vy*vy + 8*g*h))/(2*g);
x = vx*time;
if(v == 0.0 || theta == 90.0){
destY = h;
destX = x;
return true;
}
else {
if(theta > 90.0 || x < b){
destY = 0;
destX = x;
return true;
}
y = b*tan(angle) - g*b*b/(2*vx*vx);
if(fabs(y+h) <= t){
destX = b;
destY = h+y;
return true;
}
x = (tan(angle) + sqrt(tan(angle)*tan(angle) - 4*t*g*x*x/(2*vx*vx)))/(2*g*x*x/(2*vx*vx));
if(x < b+w){
destY = t;
destX = x;
return true;
}
else {
destY = 0.0;
destX = vx*time;;
return true;
}
}
return true;
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
  
  // Some test driver code here ....

  float h = 10;
  float v = 10;
  float m = 10;
  float theta = 45;        // Angle in degrees; will need to be converted by function
  float d = 100;
  float t = 5;
  float b = 97;
  float w = 5;

  float hitsAtX;
  float hitsAtY;

  if (projectileDestination(h,v,m,theta,d,t,b,w,hitsAtX,hitsAtY))
    cout << "Projectile hit at (" << hitsAtX << ", " << hitsAtY << ")" <<endl;
  else
    cout << "Unable to calculate where projectile hits." << endl;
  return 0;
}

#endif
