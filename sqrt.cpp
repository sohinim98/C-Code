#include <iostream> 
# include <stdlib.h> 
using namespace std; 

int main(const int argc, const char* const argv[]) 
{ 
	if (argc < 4)
	{
		cerr << "Error: Unable to compute the square root because of insufficient arguments. Expected at least 3." << endl; 
		return -1; 
	}		
	
	 if (argc > 4) 
	{
		cerr << "Warning: received extra inputs; ignored extraneous arguments." << endl; 
		return -1; 
	}
	
	if (atof (argv[2]) != 2) 
	{
		cerr << "Error: program is designed to only take the square root." << endl; 
		return -1; 
	}
	
	if (atof (argv[1]) < 0) 
	{
		cerr << "Error. Cannot take the square root of negative numbers." << endl; 
		return -1; 
	}
	
	float number = atof (argv[1]); 
	int root = atoi (argv[2]); 
	float precision = atof (argv[3]); 
	float calculated_precision = precision + 1; 
	float answer = 1; 
	
	int count = 0; 
	while (calculated_precision > precision && count < 1000) 
	{
		answer = (answer + number/answer)/2; 
		calculated_precision = (number - answer*answer)/(number); 

		if (calculated_precision < 0) 
		{ 
			calculated_precision = -1*calculated_precision; 
		}
			
		count ++; 	
	}
	
	cout << "Root (" << number << ", " << root << ") = " << answer << endl; 
	cout << "(with precision " << precision << ")" << endl; 
	
	
}