//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <cmath>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//


#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

#define NaN std::numeric_limits<float>::quiet_NaN() 
#define isNaN(X) (X != X) // NaN is the only float that is not equal to itself

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b, 
							 const float w, float& theta);
							 
bool hitTargetGivenAngle (const float h, const float m, const float theta, 
							const float d, const float t, const float b, 
							const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

bool hitTargetGivenVelocity (const float h, const float v, const float m,
							 const float d, const float t, const float b, 
							 const float w, float& theta) {
 if(h < 0 || m < 0 || v == 0 || d < 0 || b < 0 || w < 0){
return false;
}
if(isNaN(h) || isNaN(v) || isNaN(d) || isNaN(m) || isNaN(t) || isNaN(b) || isNaN(w)){
return false;
}
float g = 9.8;
float mp = M_PI/4;
float vx = v*cos(mp);
float x = (tan(mp) + sqrt(tan(mp)*tan(mp) + 4*(h-t)*g/(2*vx*vx)))/(2*g/(2*vx*vx));
float prev = 0;
float left = 0;
float right = M_PI/2;
while(x != d){
if(x < d){
right = mp;
mp = (right + left)/2;
}
else{
left = mp;
mp = (left + right)/2;
}
prev = x;
vx = v*cos(mp);
x = (tan(mp) + sqrt(tan(mp)*tan(mp) + 4*(h-t)*g/(2*vx*vx)))/(2*g/(2*vx*vx));
if(prev == x)
break;
}
theta = mp * 180 / M_PI;
return true;
}

bool hitTargetGivenAngle (const float h, const float m, const float theta, 
							const float d, const float t, const float b, 
							const float w, float& v) {
if(h < 0 || m < 0 || theta == 0 || d < 0 || b < 0 || w < 0){
return false;
}
if(isNaN(h) || isNaN(theta) || isNaN(d) || isNaN(m) || isNaN(t) || isNaN(b) || isNaN(w)){
return false;
}
float g = 9.8;
float angle = theta * M_PI / 180;
v = sqrt(g*d*d/(2*cos(angle)*cos(angle)*(d*tan(angle)-(t-h))));
return true;
}
		

#ifndef MARMOSET_TESTING
int main() {
	
  // Some test driver code here ....
  
  float h = 50;
  float d = 60;
  float b = 40;
  float t = 30;
  float w = 30;
  float m = 1;

  float theta = 45; // Angle in degrees;
  float v = 25;	

  cout << "Given angle: " << theta << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenAngle (h, m, theta, d, t, b, w, v)) {
    cout << "required initial velocity: " << v << endl << endl;
  }
  else {
    cout << "cannot calculate the velocity\n\n";
  }

  cout << "Given initial velocity: " << v << endl;
  cout << "Target at (" << d << "," << t << ")" << endl;
  if (hitTargetGivenVelocity (h, v, m, d, t, b, w, theta)) {
    cout << "required angle: " << theta << endl << endl;
  }
  else {
    cout << "cannot calculate the angle\n\n";  
  }
    
  return 0;
}
#endif
