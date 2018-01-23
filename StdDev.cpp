#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
if(argc <= 1)
cerr << "Error: Unable to compute statistics over data set because no number has been entered." << endl;
else {
float numbers[argc-1];
int i = 0;
while(i < argc-1)
{
numbers[i]= atof(argv[i+1]);
i++;
}
for(i=0;i<argc-2;i++)
{
for(int j=i+1;j<argc-1;j++)
{
if(numbers[i]>numbers[j])
{
float temp = numbers[i];
numbers[i] = numbers[j];
numbers[j] = temp;
}
}
}
float minimum = numbers[0];
float maximum = numbers[argc-2];
float average = 0;
for(i=0;i<argc-1;i++)
{
average = average+numbers[i];

}
average = average/(argc-1);
float PSD = 0;
float SSD = 0;
int flag = 0;
for(i=0;i<argc-1;i++)
{
PSD = PSD+(numbers[i]-average)*(numbers[i]-average);
SSD = SSD+(numbers[i]-average)*(numbers[i]-average);
}
if(PSD/(argc-1)<0)
PSD = -1;
else
PSD = sqrt(PSD/(argc-1));
if(argc-2 == 0)
flag = 1;
else
{
if(SSD/(argc-2)<0)
SSD = -1;
else
SSD = sqrt(SSD/(argc-2));
}
cout << "Number of floating-point numbers: " << (argc-1) << endl;
cout << "Minimum floating-point number: " << minimum << endl;
cout << "Average floating-point number: " << average << endl;
cout << "Maximum floating-point number: " << maximum << endl;
if(PSD == -1)
cerr << "Error: Population Standard Deviation could not be computed since it was the sqaure root of a negative number." << endl;
else
cout << "Population standard deviation: " << PSD << endl;
if(flag == 1)
cout << "Sample standard deviation: infinity" << endl;
else
{
if(SSD == -1)
cerr << "Error: Sample Standard Deviation could not be computed since it was the sqaure root of a negative number." << endl;
else
cout << "Sample standard deviation: " << SSD << endl;
}
}
}
