#include <iostream>
 
#include <stdlib.h>
 
#include <limits.h>
 
#include <float.h>
 
using namespace std;
 
int main( const int argc, const char* const argv[])
{
                int x;
               
                unsigned int y;
               
                x = atoi(argv[1]);
               
                y = x;
 
                int sig1 = (x >> (sizeof(x)*8-1));
               
                int sig2 = (y >> (sizeof(y)*8-1));
               
                cout << "The value of x is " << x << "." << endl;
               
                cout << "The value of y is " << y << "." << endl;
               
                cout << "The most significant bit of x is " << sig1 << "." << endl;
               
                cout << "The most significant bit of y is " << sig2 << "." << endl;
               
                char v1;
               
                short int v2;
               
                int v3;
               
                long int v4;
               
                long long int v5;
 
                float v6;
 
                double v7;
               
                long double v8;
 
                unsigned char v9;
 
                unsigned short int v10;
 
                unsigned int v11;
 
                unsigned long int v12;
 
                unsigned long long int v13 ;
               
                cout << "Type: " << "\"signed char\";" << " Size: " << sizeof(v1) << " bytes;" << " Minimum value: " << CHAR_MIN << " ;" << " Maximum value: " << CHAR_MAX << ";" << endl;
               
                cout << "Type: " << "\"short int\";" << " Size: " << sizeof(v2) << " bytes;" << " Minimum value: " << SHRT_MIN << " ;" << " Maximum value: " << SHRT_MAX << ";" << endl;
               
                cout << "Type: " << "\"int\";" << " Size: " << sizeof(v3) << " bytes;" << " Minimum value: " << INT_MIN << " ;" << " Maximum value: " << INT_MAX << ";" << endl;
               
                cout << "Type: " << "\"long int\";" << " Size: " << sizeof(v4) << " bytes;" << " Minimum value: " << LONG_MIN << " ;" << " Maximum value: " << LONG_MAX << ";" << endl;
               
                cout << "Type: " << "\"long long int\";" << " Size: " << sizeof(v5) << " bytes;" << " Minimum value: " << LLONG_MIN << " ;" << " Maximum value: " << LLONG_MAX << ";" << endl;
               
                cout << "Type: " << "\"float\";" << " Size: " << sizeof(v6) << " bytes;" << " Minimum value: " << FLT_MIN << " ;" << " Maximum value: " << FLT_MAX << ";" << endl;
               
                cout << "Type: " << "\"double\";" << " Size: " << sizeof(v7) << " bytes;" << " Minimum value: " << DBL_MIN << " ;" << " Maximum value: " << DBL_MAX << ";" << endl;
               
                cout << "Type: " << "\"long double\";" << " Size: " << sizeof(v8) << " bytes;" << " Minimum value: " << LDBL_MIN << " ;" << " Maximum value: " << LDBL_MAX << ";" << endl;
               
                cout << "Type: " << "\"unsigned char\";" << " Size: " << sizeof(v9) << " bytes;" << " Minimum value: " << 0 << " ;" << " Maximum value: " << UCHAR_MAX << ";" << endl;
               
                cout << "Type: " << "\"unsigned short int\";" << " Size: " << sizeof(v10) << " bytes;" << " Minimum value: " << 0 << " ;" << " Maximum value: " << USHRT_MAX << ";" << endl;
               
                cout << "Type: " << "\"unsigned int\";" << " Size: " << sizeof(v11) << " bytes;" << " Minimum value: " << 0 << " ;" << " Maximum value: " << UINT_MAX << ";" << endl;
               
                cout << "Type: " << "\"unsigned long int\";" << " Size: " << sizeof(v12) << " bytes;" << " Minimum value: " << 0 << " ;" << " Maximum value: " << ULONG_MAX << ";" << endl;
                                                                                                                                                                                                                                                                                                                                               
                cout << "Type: " << "\"unsigned long long int\";" << " Size: " << sizeof(v13) << " bytes;" << " Minimum value: " << 0 << " ;" << " Maximum value: " << ULLONG_MAX << ";" << endl;
               
                return 0;
               
}