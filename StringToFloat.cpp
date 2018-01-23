//////////////////////////////////////////////////////////////
//
#include <iostream>
#include <float.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif

using namespace std;

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove

bool stringToFloat(const char input[], float& value);

//////////////////////////////////////////////////////////////
//
// Your code here ...

bool stringToFloat(const char input[], float& value) 
{
    bool negative = false;
    bool exponent = false;
    float number = 0.0;
    float decimal = 0.0;
    float power = 0.0;
    bool negativePower = false;

    int i = 0;

    if(input[0] == '+' ||  input[0] == '-')
    {
        i = 1;
        if(input[0] == '-')
        {
            negative = true;
        }
    }

    while(input[i] != '.')
    {
        int digit = input[i];
        if(digit >= '0' && digit <= '9')
        {
            digit = digit-48;
            number = (float)number * 10 + digit;
        }

        else if(input[i] == '\0')
        {
            
            break;
        }

        else if(digit == 'e' || digit == 'E')
        {
            exponent = true;
            i++;
            break;
        }

        else
        {
            return false;
        }

        i++;
    }

    if(input[i] == '.')
    {
        if(input[i + 1] > '9' || input[i + 1] < '0')
        {
            return false;
        }
    }

    if(exponent)
    {
        if(input[i] == '+' || input[i] == '-')
        {
            if(input[i] == '-')
            {
                negativePower = true;
            }
            i++;
        }

        else if(input[i] == '\0')//EAtTheEnd
        {
            return false;
        }

        while(input[i] != '\0')
        {
            int digit = input[i];
            if(digit >= '0' && digit <= '9')
            {
                digit = digit-48;
                power = power*10 + digit;
            }

            else
            {
                return false;
            } 

            i++;

        }
    }


    

    int j = 0; //from here

    while(input[i] != '\0')
    {
        int dig = input[i];
        if(dig >= '0' && dig <= '9')
        {
            dig = dig - 48;
            decimal = decimal * 10 + dig;
            j++;
        }

        else if(dig == 'e' || dig == 'E')
        {
            exponent = true;
            i++;
            break;
        }

        else if(dig != '.')
        {
            return false;
        }

        if(input[i + 1] == '.')
        {
            return false;
        }

        i++;
    }

    if(exponent)
    {
        if(input[i] == '+' || input[i] == '-')
        {
            if(input[i] == '-')
            {
                negativePower = true;
            }


            i++;
        }

        else if(input[i] == '\0')
        {
            return false;
        }


        while(input[i] != '\0')
        {
            int digit = input[i];
            if(digit >= '0' && digit <= '9')
            {
                digit = digit-48;
                power = power*10 + digit;
            }

            else
            {
                return false;
            } 

            i++;
        }
    }

    decimal = decimal * pow(10, -1 * j);
    value = number + decimal;
    if(negative)
    {
        value = value * -1;
    }

    if(exponent)
    {
        if(negativePower)
        {
            value = 1.0 / pow(10,power);
        }

        else
        {
            value = value * pow(10,power);
        }
        
    }
    return true;
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
  float argv1;

  if (argc < 2) {
    cerr << "Error: Usage: " << argv[0] << " <float>" << endl;
    return -1;
  }

  if (stringToFloat(argv[1],argv1)) 
    cout << "argv[1] is a float with value: " << argv1 <<endl;
  else
    cout << "argv[1] is not a float. argv[1]: " <<argv[1] << endl;
  return 0;
}

#endif
