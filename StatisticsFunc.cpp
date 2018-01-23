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

bool statistics(const float dataset[], const int size, float& min, float& avg, float& max, float& popSD, float& smplSD, float& mdn);
float minimum(const float dataset[], const int size);
float average(const float dataset[], const int size);
float maximum(const float dataset[], const int size);
float popStdDev(const float dataset[], const int size);
float smplStdDev(const float dataset[], const int size);
float median(const float dataset[], const int size);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

bool statistics(const float dataset[], const int size, float& min, float& avg, float& max, float& popSD, float& smplSD, float& mdn) {
if(size <= 1)
return false;
else {
min = minimum(dataset, size);
avg = average(dataset, size);
max = maximum(dataset, size);
popSD = popStdDev(dataset, size);
smplSD = smplStdDev(dataset, size);
mdn = median(dataset, size);
if(popSD != popSD || smplSD != smplSD || smplSD == INFINITY || smplSD == -INFINITY)
return false;
else 
return true;
}
}

float minimum(const float dataset[], const int size) {
float min = dataset[0];
for(int i=0; i<size; i++)
{
if(min > dataset[i])
min = dataset[i];
}
return min;
}

float average(const float dataset[], const int size) {
float avg = 0.0;
for(int i = 0; i<size; i++)
{
avg = avg + dataset[i];
}
avg = avg/size;
return avg;
}

float maximum(const float dataset[], const int size) {
float max = dataset[0];
for(int i=0; i<size; i++)
{
if(max < dataset[i])
max = dataset[i];
}
return max;
}

float popStdDev(const float dataset[], const int size) {
float avg = 0.0;
for(int i = 0; i<size; i++)
{
avg = avg + dataset[i];
}
avg = avg/size;
float PSD = 0;
for( int i=0; i < size; i++)
{
PSD = PSD+(dataset[i]-avg)*(dataset[i]-avg);
}
if(PSD/(size)<0)
return std::numeric_limits<float>::quiet_NaN();
else {
PSD = sqrt(PSD/size);
return PSD;
}
}

float smplStdDev(const float dataset[], const int size) {
float avg = 0.0;
for(int i = 0; i<size; i++)
{
avg = avg + dataset[i];
}
avg = avg/size;
float SSD = 0;
for(int i=0;i<size;i++)
{
SSD = SSD+(dataset[i]-avg)*(dataset[i]-avg);
}
if(size-1 == 0)
return std::numeric_limits<float>::infinity();
if(SSD/(size-1)<0)
return std::numeric_limits<float>::quiet_NaN();
else{
SSD = sqrt(SSD/(size-1));
return SSD;
}
}
float median(const float dataset[], const int size) {
float temp=0.0;
float mdn = 0.0;
float numbers[size];
for(int i = 0; i < size; i++)
{
numbers[i] = dataset[i];
}
for(int i=0;i<size-1;i++)
{
int min = i;
for(int j=i+1;j<size;j++)
{
if(numbers[min]>numbers[j])
min = j;
}
temp = numbers[i];
numbers[i] = numbers[min];
numbers[min] = temp;
}
if(size%2 == 0)
mdn = (numbers[size/2]+numbers[(size-2)/2])/2;
else
mdn = numbers[size/2];
return mdn;
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
  int size = argc-1;
  float dataset[size];
  for(int i=0;i<size;i++)
  {
  dataset[i] = atof(argv[i+1]);
  }
  float min;
  float avg;
  float max;
  float popStDev;
  float smplStDev;
  float median;

  if (statistics(dataset, size, min, avg, max, popStDev, smplStDev, median)) {
    cout << "Minimum: " << min << endl
	 << "Average: " << avg << endl
	 << "Median:  " << median << endl
	 << "Maximum: " << max << endl
	 << "Population Standard Deviation: " << popStDev << endl
	 << "Sample Standard Deviation:     " << smplStDev << endl;
  }
  else
    cout << "Error: unable to compute statistics" << endl;

  return 0;
}

#endif
