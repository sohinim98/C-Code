#include <iostream>
using namespace std;
int fibonacci(int i) {

  if (i == 0)

    return 0;

  if (i == 1)

    return 1;

  return (fibonacci(i-1) + fibonacci(i-2));

}

int main(const int argc, const char* argv[]) {

  cout << "Fibonacci(" << atoi(argv[1]) << "): " << fibonacci(atoi(argv[1])) << endl;

}