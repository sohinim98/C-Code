//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//


#include <fstream>

//////////////////////////////////////////////////////////////
//
// #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
using namespace std;
#endif
#ifdef MARMOSET_TESTING
int maxNumErrors = 10;
#endif
//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
// Replace "..." in bisectionHelper() with any parameter(s)
// you need to ensure termination when precision and
// minIntervalSize are too tightly specified.
//

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects);

//////////////////////////////////////////////////////////////
//
// Your code here ...
//  
// Return -1 if you cannot compute the histogram for any
// reason;
// Return 0 if the histogram is correct and there are no
// rejections;
// Return the number of rejects if there are rejected
// records from the file
//

int histogram(const char filename[], int histogram[10], 
              const int minAcceptableID, const int maxAcceptableID,
              int*& rejects) {
if(minAcceptableID>maxAcceptableID)
return -1;
const int maxLineLength = 100;
char line[maxLineLength];
std::ifstream infile; //declare the file object
infile.open(filename); //open the file
if(!infile.is_open())
return -1; //unable to open file
bool done = false;
int fileLineNumber = 0;
rejects = new int[maxNumErrors];
int k=0;
for(int j=0;j<10;j++)
{
histogram[j]=0;
}
while(!done) {
++fileLineNumber;
if(!infile.getline(line, maxLineLength)) { //Get the next line
if(infile.eof()) //end of file
done = true;
else
return -1;
}
int dig=0; int number=0;
int markdig=0; int marks=0;
int i=0;
while(line[i] != ',')
{
if(line[i]>='0' && line[i]<='9')
{
dig=(int)(line[i])-48;
number=number*10+dig;
}
else if(line[i]!=' ')
return -1;
i++;
}
if((number < minAcceptableID) || (number > maxAcceptableID))
{
if(k==maxNumErrors)
return -1;
rejects[k++]=fileLineNumber;
continue;
}
i++;
while(line[i]!='\0')
{
if(line[i]>='0' && line[i]<='9')
{
markdig= (int)(line[i])-48;
marks=marks*10+markdig;
}
else if(line[i]!=' ')
return -1;
i++;
}
if((marks<0)||(marks>100)) {
if(k==maxNumErrors)
return -1;
rejects[k++]=fileLineNumber;
}
int bucket = marks/10;
if(marks == 100)
histogram[9]+=1;
else
histogram[bucket]+=1;
}
return k;
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

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  
  // Some test driver code here ....
  if (argc < 2) {

  }
  const int numBuckets = 10;
  const int bucketRange = 100/numBuckets;
  int  buckets[numBuckets];
  int* rejectedRecords;
  int retCode = histogram(argv[1], buckets, 22200000, 22299999, rejectedRecords);
  if (retCode < 0) {
      cout << "Unable to compute histogram." << endl;
  }
  else {
    for (int i = 0; i < numBuckets; ++i)
      if (i != numBuckets-1)
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)-1) << "]: " << buckets[i] << endl;
      else
	cout << "Number [" << i*bucketRange << "," << (((i+1)*bucketRange)) << "]: " << buckets[i] << endl;
    if (retCode > 0) {
      cout << "Number of rejected records: " << retCode << endl;
      cout << "Rejected records are:";
      for (int i = 0; i < retCode; ++i)
	cout << " " << rejectedRecords[i];
      cout << endl;
      delete[] rejectedRecords;
    }
  }

  return 0;
}

#endif
