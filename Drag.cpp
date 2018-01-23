//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

	#include <stdlib.h>
	#include <limits>
	#include <math.h>
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

bool hitTargetGivenAngle (const float h, const float m, const float theta,
const float d, const float step, const float k,
const float t, const float b, const float w, float& v);
int  calcDist(const float h, const float m, const float theta,
const float d, const float step, const float k,
const float t, const float b, const float w, float& v);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//




bool hitTargetGivenAngle (const float h, const float m, const float theta,
const float d, const float step, const float k,
const float t, const float b, const float w, float& v)
{

	if(k < 0 || h < 0 || theta > 90 || theta < 0 || d < 0 || w < 0 || m <= 0 || step <= 0 || b < 0)
		return false;
	float l = 0;
	float u = 100;
	float mid;
	float dist = 0;
	int i = 0;
	bool done = false;

	while(done != true)
	{
		mid = (l+u)/2;
		dist = calcDist(h,m,theta,d,step,k,t,b,w,mid);
		if(mid == -1)
			return false;

		if(dist < d)
			l = mid;
		if(dist>d)
			u = mid;
		i++;
		if(i == 10000)
		{

			v = mid;
			return true;
		}
	}

	return false;

}

int calcDist(const float h, const float m, const float theta,
const float d, const float step, const float k,
const float t, const float b, const float w, float& v)
{
	bool done = false;
	float vx = v*cos((theta*M_PI)/180);
	float vy = v*sin((theta*M_PI)/180);
	float v2;
	float dx=0;
	float dy=h;
	for (int i=0; i<=10000; i++)
	{
		v2 = sqrt((pow(vx,2)) + (pow(vy,2)));
		dx = dx + vx*step;
		vx = vx - (((k*vx*v2)/m)*step);
		dy = dy + vy*step;
		vy = vy - (((9.8) + ((k*vy*v2)/m))*step);
		if(t < 0 && dy <= 0 && dx <= b)
			done = true;
		if(dy <= t && vy < 0)
			return dx;
	}

	return dx;

}


	#ifndef MARMOSET_TESTING
int main()
{

	// Some test driver code here ....
	float h = 50;
	float d = 60;
	float b = 40;
	float t = 0;
	float w = 30;
	float m = 0.5;
	float step = 0.001;
	float k = 0.00819;
	float theta = 45;                  // Angle in degrees;
	float v = 25;
	cout << endl << "Given angle: " << theta << endl;
	cout << "Target at (" << d << "," << t << ")" << endl;
	if (hitTargetGivenAngle (h, m, theta, d, step, k, t, b, w, v))
	{
		cout << "required initial velocity: " << v << endl << endl;
	}
	else
	{
		cout << "cannot calculate the velocity" << endl << endl;
	}
	return 0;
}
	#endif
