#include <iostream>

using namespace std;

int main( const int argc, const char* const argv[])
{
    cout << "Welcome to UW Engineering, " << argv[1] << endl;
    // A line of code to output the second command-line argument (argv[2])
    cout << "Your University of Waterloo E-mail address is: " << argv[2] << "@uwaterloo.ca" << endl;
    // A line of code to output the content of argc	
   cout << "The value stored in argc is " << argc << endl;
    // A line of code to explain what is stored in argc
    cout << "The variable \"argc\" contains the number of command-line arguments including the name of the program" << endl;
    


    return 0;
}
