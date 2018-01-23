#include <iostream> 
#include <stdlib.h> 
using namespace std; 
int main(const int argc, const char* const argv[]) 
{
if (argc < 4)
cerr << "Error: Unable to compute Nth root because of insufficient arguments." << endl;	
else if((atoi(argv[1]) < 0 && atoi(argv[2])==2) || atoi(argv[2]) < 2 || atoi(argv[2])!= atof(argv[2]) || atof(argv[3])<=0)
cerr << "Error: Unable to compute Nth root because the entered number has to be a positive floating-point number, the power has to be an integer >=2 and the precision has to be >0." << endl;
else
{
if (argc > 4) 
cerr << "Warning: received extra inputs; ignored extraneous arguments." << endl;
float num = atof (argv[1]); 
int root = atoi (argv[2]); 
float precision = atof (argv[3]); 
float calculated_precision = precision + 1; 
float ans= 1.0;
int count = 0; 
while (calculated_precision > precision && count < 1000) 
{
float tmp = 1.0;
for(int i=1;i<=root-1;i++)
{
tmp = tmp*ans;
}
ans = ans*(root-1)/root + num/(root*tmp);
float tmp1 = 1.0;
for(int i=1;i<=root;i++)
{
tmp1 = tmp1*ans;
}
calculated_precision = (num - tmp1)/num;
if (calculated_precision < 0) 
calculated_precision = -1*calculated_precision;
count ++;
}
cout << "Root (" << num << "," << root << ") = " << ans << endl; 
cout << "(with precision " << calculated_precision << ")" << endl;
}
}