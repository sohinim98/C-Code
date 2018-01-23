//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


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

int range(const int dataset[], const int size);
int mode(const int dataset[], const int size, int mode[]);
bool sort(int dataset[], const int size);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  Return -1 if there there are any problems with the dataset.
//

int range(const int dataset[], const int size){
if(size<=0)
return -1;
int arr[size];
for(int i=0;i<size;i++)
{
arr[i]=dataset[i];
}
sort(arr,size);
int rng = arr[size-1]-arr[0];
return rng;
}
int mode(const int dataset[], const int size, int mode[]){
if(size <= 0){
return -1;
}
int arr[size];
for(int i = 0; i < size; i++){
arr[i] = dataset[i];
}
sort(arr,size);
int maxFreq = 0;
int freq[size];
for(int i=0;i<size;i++){
freq[i] = 1;
}
int a = 0;
int j = 0;
int distinct[size]; //storing each distinct value once
for(int i = 0; i < size;){
distinct[a] = arr[i];
for(j=i+1; j < size; j++){
if(arr[j] == arr[i]){
freq[a]++;
}
else
break;
}
a++;
i=j;
}
for(int i = 0; i < a; i++){
if(maxFreq < freq[i])
maxFreq = freq[i];
}
int k = 0;
for(int i = 0;i<a;i++){
if(maxFreq == freq[i]){
mode[k++] = distinct[i];
}
}
return k;
}
bool selection(int dataset[], const int size){
int maxIndex=0, temp=0, index=0;
int n = size;
for(index = maxIndex; index<n;index++) {
if(dataset[index]>dataset[maxIndex]) {
maxIndex = index;
}
}
temp = dataset[n-1];
dataset[n-1] = dataset[maxIndex];
dataset[maxIndex] = temp;
if(n>1)
selection(dataset, --n);
return true;
}
bool sort(int dataset[], const int size){
selection(dataset,size);
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
  
  // Some test driver code here ....
  int data[] = {1,1,2 ,3,3,4};
  int size = 6;
  //change this to however many modes you expect to find
  int modeArray[6]={0};
  int rng = range(data, size);
  int modes = mode(data, size, modeArray);
  cout << "range: " << rng << " number of Modes: " << modes << " Modes are this: ";
  for(int i = 0; i<modes;i++){
  	cout<< modeArray[i];
  	if(i<modes-1){
  		cout << ", ";
  	}
  }
  cout<<endl;
  return 0;
}

#endif