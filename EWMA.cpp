#include <iostream>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
if(argc <= 3 || atof(argv[2]) <= 0 || atof(argv[2]) != atoi(argv[2]) || atof(argv[1]) <= 0 || atof (argv[1]) >= 1)
{
if(argc <= 3)
cerr << "Error: Unable to compute statistics over data set because no number has been entered." << endl;
if(atof(argv[2]) <= 0 || atof(argv[2]) != atoi(argv[2]))
cerr << "Error: Invalid age limit; the age limit cannot be <= zero or a fraction." << endl;
if(atof(argv[1]) <= 0 || atof (argv[1]) >= 1)
cerr << "Error: The value of alpha must be greater than 0 and less than 1." << endl;
}
else {
int i = 3;
int ifinal;
int counter1 = 0;
int counter2 = 0;
float alpha = atof(argv[1]);
int agelim = atoi(argv[2]);
float minimum = atof(argv[3]);
float maximum = atof(argv[3]);
float average;
float average0 = atof(argv[3]);
cout << "Sample		Value		Minimum		EWMA		Maximum" << endl;
while(argv[i] != NULL) {
if(counter1 == agelim)
{
minimum = atof(argv[i]);
counter1 = 0;
}
if(counter1 != agelim)
{
if(minimum > atof(argv[i]))
{
minimum = atof(argv[i]);
counter1 = 1;
}
else
counter1++;
}
if(counter2 == agelim)
{
maximum = atof(argv[i]);
counter2 = 1;
}
if(counter2 != agelim)
{
if(maximum < atof(argv[i]))
{
maximum = atof(argv[i]);
counter2 = 1;
}
else
counter2++;
}
average = alpha*atof(argv[i])+(1-alpha)*average0;
average0=average;
cout << i-2 << "		" << argv[i] << "		" << minimum << "		" << average << "		" << maximum << endl;
i++;
}
}
}