#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
if(argc<=3)
cerr << "Error: Insufficient arguments; expecting three command-line arguments." << endl;
else 
{
if(argc>4)
cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
float velocity;
float distance;
float maximum;
float deceleration;
float time;
float finalvel;
velocity = atof(argv[1]);
distance = atof(argv[2]);
maximum = atof(argv[3]);
if (velocity == 0)
cout << "There is no possibility of collision because the car is at rest." << endl;
else if ((velocity < 0 && distance > 0) || (velocity > 0 && distance < 0))
cout << "There is no possibility of collision because the car is traveling in the opposite direction." << endl;
else {
if(velocity < 0 && distance < 0)
{
velocity = -1 * velocity;
distance = -1 * distance;
}
deceleration = (velocity*velocity)/(2*distance);
if ( deceleration < maximum) {
time = velocity/deceleration;
cout << "Initial car velocity: " << velocity << "m/s" << endl;
cout << "Distance to obstacle: " << distance << "m" << endl;
cout << "Minimum deceleration: " << deceleration << "m/s/s." << endl;
cout << "Maximum stopping time: " << time << "s" << endl;
}
if (deceleration > maximum)
{
finalvel = sqrt(velocity*velocity-2*maximum*distance);
time = -(finalvel - velocity)/maximum;
cout << "Crash will occur in " << time << " seconds at velocity "<< finalvel << " m/s; deploying airbags." << endl;
}
}
}
return 0;
}