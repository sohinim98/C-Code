#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;
int main(const int argc, const char* const argv[]) {
if(argc <= 2)
cerr << "Error: Unable to compute GCD and/or LCM because of insufficient arguments." << endl;
else {
if(argc > 3)
cerr << "Warning: Expecting three command-line arguments; received four; ignoring extraneous arguments." << endl;
int num1 = atoi(argv[1]);
int num2 = atoi(argv[2]);
int copy1 = num1;
int copy2 = num2;
if(num1 <= 0 || num2<= 0)
cerr << "Error: Unable to compute GCD and/or LCM because of non-positive integer inputs." << endl;
else {
int num3;
if(num1 < num2)
{
num3 = num1;
num1 = num2;
num2 = num3;
}
int GCD;
int LCM;
while(true) {
num3 = num1 % num2;
if(num3 == 0)
break;
num1 = num2;
num2 = num3;
}
GCD = num2;
cout << (copy1 / GCD) << " " << copy2 << endl;
LCM = (copy1 * copy2) / GCD;
cout << "GCD(" << copy1 << ", " << copy2 << ") = " << GCD << endl;
cout << "LCM(" << copy1 << ", " << copy2 << ") = " << LCM << endl;
return 0;
}
}
}