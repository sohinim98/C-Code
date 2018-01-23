#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
float velocity;
float distance;
float maximum;
float deceleration;
float time;
float finalvel;
velocity = atof(argv[1]);
distance = atof(argv[2]);
maximum = atof(argv[3]);
if (velocity = 0)
	cout << "There is no possibility of collision because the car is at rest." << endl;
else if ((velocity < 0 && distance > 0) || (velocity > 0 && distance < 0))
	cout << "There is no possibility of collision because the car is traveling in the opposite direction."
else {
	deceleration = (velocity*velocity)/(2*distance);
	if ( deceleration <= maximum)
	{
		time = velocity/deceleration;
		cout << "Required deceleration rate: " << deceleration << "m/s/s" << endl;
		cout << "Time required to stop: " << time << "s" << endl;
	}
	else if (deceleration > maximum)
	{
		finalvel = sqrt(velocity*velocity-2*maximum*distance);
		time = -(final-velocity)/maximum;
		cout << "Crash will occur in << t << "seconds at velocity "<< finalvel << " m/s; deploying airbags.";
return 0;
}