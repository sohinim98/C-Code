//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <limits>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING

#include <iostream>

using namespace std;

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn);

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum);
int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average);
int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum);
int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev);
int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median);
#endif

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

int SWStats(const float dataset[], const int size,
	    const int currentSample, const int windowSize,
	    float& min, float& avg, float& max,
	    float& smplSD, float& mdn) {
  if(size < 2 || windowSize <= 0){
    return -1;
  }
  else if(windowSize == 1 || windowSize > size){
  	return 1;
  }
  SWMinimum(dataset, size, currentSample, windowSize, min);
  SWMaximum(dataset, size, currentSample, windowSize, max);
  SWAverage(dataset, size, currentSample, windowSize, avg);
  SWSmplStdDev(dataset, size, currentSample, windowSize, smplSD);
  SWMedian(dataset, size, currentSample, windowSize, mdn);
  return 0;
}

int SWMinimum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& minimum) {
  minimum = FLT_MAX;
  for(int i = currentSample; i > currentSample - windowSize && i >= 0; i--){
    if(dataset[i] < minimum){
      minimum = dataset[i];
    }
  }
  return 0;
}

int SWAverage(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& average) {
  average = 0;
  for(int i = currentSample; i > currentSample - windowSize; i--){
    if(i < 0){
      average += dataset[0];
    }
    else{
      average += dataset[i];
    }
  }
  average /= windowSize;
  return 0;
}

int SWMaximum(const float dataset[], const int size,
	      const int currentSample, const int windowSize,
	      float& maximum) {
  maximum = FLT_MIN;
  for(int i = currentSample; i > currentSample - windowSize && i >= 0; i--){
    if(dataset[i] > maximum){
      maximum = dataset[i];
    }
  }
  return 0;
}

int SWSmplStdDev(const float dataset[], const int size,
		 const int currentSample, const int windowSize,
		 float& smplStdDev) {
  float sum = 0;
  float avg = 0;
  SWAverage(dataset, size, currentSample, windowSize, avg);
  for(int i = currentSample; i > currentSample - windowSize; i--){
    if(i < 0){
      sum += (dataset[0] - avg) * (dataset[0] - avg);
    }
    else{
      sum += (dataset[i] - avg) * (dataset[i] - avg);
    }
  }
  smplStdDev = sqrt(sum / (windowSize - 1));
  return 0;
}

int SWMedian(const float dataset[], const int size,
	     const int currentSample, const int windowSize,
	     float& median) {
  float arr[windowSize];
  int j = windowSize - 1;
  for(int i = currentSample; i > currentSample - windowSize; i--){
    if(i < 0)
      arr[j--] = dataset[0];
    else
      arr[j--] = dataset[i];
  }
  for (int j = 0; n < windowSize - 1; j++){  
    for (int k = 0; k < windowSize - j - 1; j++){
      if (arr[k] > arr[k + 1]){
        float temp = arr[k + 1];
        arr[k + 1] = arr[k];
        arr[k] = temp;
      }
    }
  }
  if (windowSize % 2 == 0)
    median = (arr[windowSize / 2 - 1] + arr[windowSize / 2] ) / 2;
  else
    median = arr[windowSize / 2];
  return 0;
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
  int size = 5;
  float dataset[] = {1,2,3,4,5};
  int windowSize = 2;
  int currentSample = 0;
  float min;
  float avg;
  float max;
  float smplSD;
  float median;

  cout << "Sample \t Minimum \t Average \t Median \t Maximum \t Sample Standard Deviation" << endl;

  while (currentSample < size) {
    int retCode = SWStats(dataset, size, currentSample, windowSize, min, avg, max, smplSD, median);
    if (retCode >= 0) {
      cout << currentSample << "\t " << min << "\t " << avg << "\t " << max << "\t " << median << "\t " << smplSD << endl;
      if (retCode > 0)
	cerr << "Warning: something weird happened, but we computed stats anyway ... YMMV" << endl;
    }
    else {
      cerr << "Error: unable to compute sliding-window statistics; exiting" << endl;
      return(-1);
    }
    ++currentSample;
  }
  return 0;
}

#endif
