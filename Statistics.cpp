#include <iostream>
#include <stdlib.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
if(argc <= 1)
cerr << "Error: Unable to compute statistics over data set because no number has been entered." << endl;
else {
int i = 1;
float minimum = atof(argv[1]);
float maximum = atof(argv[1]);
float sum = 0;
float average;
while(argv[i] != NULL) {
if(minimum > atof(argv[i]))
minimum = atof(argv[i]);
if (maximum < atof(argv[i]))
maximum = atof(argv[i]);
sum = sum + atof(argv[i]);
i++;
}
i--;
cout << i;
average = sum/i;
cout << "Number of floating-point numbers: " << i << endl;
cout << "Minimum floating-point number: " << minimum << endl;
cout << "Average floating-point number: " << average << endl;
cout << "Maximum floating-point number: " << maximum << endl;
}
}
