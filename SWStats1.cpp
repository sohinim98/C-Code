#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
if(argc <= 2)
cerr << "Error: Unable to compute statistics over data set because no number has been entered." << endl;
else if(atof(argv[1])!= atoi(argv[1]) || atoi(argv[1]) <= 0)
cerr << "Error: Unable to compute statistics over data set because the window size has to be a positive integer." << endl;
else {
int size;
if(atoi(argv[1]) <= (argc-1))
{
size = argc-1;
}
else
{
size = atoi(argv[1]);
}
float numbers[size];
if(size == argc-1)
{
for(int i=0;i<size;i++)
{
numbers[i]=atof(argv[i+1]);
}
}
else {
int counter = 0;
int j= 2;
while(argv[j] != NULL)
{
counter++;
}
int i=size-1;
while(i>= atoi(argv[1])-counter)
{
numbers[i]= atof(argv[i+1]);
i--;
}
for(int i=0; i<size-argc-2; i++)
{
numbers[i] = atof(argv[2]);
}
}
int window = atoi(argv[1]);
cout << "Window Size: " << window << endl;
cout << "Sample		Value		SWMinimum		SWAverage		SWMaximum" << endl;
float windowarray[window];
for(int k=0;k<=size-window;k++)
{
for(int q=0;q<window;q++)
{
windowarray[q]=numbers[q+k];
}
for(int t=0;t<window-1;t++)
{
for(int p=t+1;p<window;p++)
{
if(windowarray[t]>windowarray[p])
{
float temp = windowarray[t];
windowarray[t]=windowarray[p];
windowarray[p]=temp;
}
}
}
float SWMinimum = windowarray[0];
float SWMaximum = windowarray[window-1];
float average=0;
for(int t=0;t<window;t++)
{
average = average+windowarray[t];
}
average=average/window;
cout << (k+1) << "		" << numbers[k] << "		" << SWMinimum << "		" << average << "		" << SWMaximum << endl;
}
}
}
