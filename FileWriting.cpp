//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <fstream>
#include <float.h>
#include <math.h>

//////////////////////////////////////////////////////////////
//
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif
int maxNumErrors = 10;
//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING
struct Student{
	int studentID;
	int grade;
};

struct Dataset{
	int numStudents;
	Student* students;
};

struct Rejects{
	int numRejects;
	int* rejects;
};

struct Mode{
	int numModes;
	int* modes;
};

struct Statistics{
	int   minimum;
	float average;
	int   maximum;
	float popStdDev;
	float smplStdDev;
	Mode  mode;
	int   histogram[10];
};
#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//
int readCSV(const char filename[],const int minAcceptableID, 
				const int maxAcceptableID,Dataset& data, 
				Rejects& rejects);

int computeStatistics(Dataset& data, Statistics& stats);

int writeCSV(const char filename[], const Statistics& stats);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//
int readCSV(const char filename[],const int minAcceptableID, 
				const int maxAcceptableID,Dataset& data, 
				Rejects& rejects){
	if(minAcceptableID > maxAcceptableID || filename[0] == '\0' || filename == NULL)
		return -1;
	char name[100];
	int i=0;
	while(filename[i] != '\0' && filename[i] != '.'){
		name[i] = filename[i];
		i++;
	}
	name[i++] = '.';
	name[i++] = 'c';
	name[i++] = 's';
	name[i++] = 'v';
	name[i++] = '\0';
	std::ifstream infile;
	infile.open(name);
	if (!infile.is_open())
	  return -1;  
	int numData = 0;
	int numRejects = 0;
	rejects.rejects = new int[maxNumErrors];
    if(rejects.rejects == NULL){
      return -2;
    }
    data.students = new Student[100];
	const int maxLineLength = 100;
	char line[maxLineLength];
	bool done = false;
	int fileLineNumber = 0;
	while (!done) {  
	  ++fileLineNumber;
	  if (!infile.getline(line, maxLineLength)){
	    if (infile.eof()) {
	      done = true;
	      break;
	    }
	    else{
	      return -3;
	    }
	  }
	  long ID = 0;
      int j = 0;
      while(line[j] == ' ' || line[j] == '\t'){
        if(line[j] == '\0'){
          if(numRejects == maxNumErrors){
            return -4;
          }
          numRejects++;
          rejects.rejects[numRejects++] = fileLineNumber;
          continue;
        }
        j++;
      }
      if(line[j] == ','){
      	if(numRejects == maxNumErrors){
      	  return -16;
      	}
      	rejects.rejects[numRejects++] = fileLineNumber;
      	continue;
      }
      while(line[j] != ','){
        if(line[j] >= '0' && line[j] <= '9')
          ID = ID*10+(int)(line[j]) - 48;
        else{
        	if(numRejects == maxNumErrors){
        	  return -26;
        	}
        	rejects.rejects[numRejects++] = fileLineNumber;
        	break;
        }
        j++;
      }
      if(rejects.rejects[numRejects-1] == fileLineNumber)
      	continue;
      if(ID < minAcceptableID || ID > maxAcceptableID){
        if(numRejects == maxNumErrors){
          return -36;
        }
        rejects.rejects[numRejects++] = fileLineNumber;
        continue;
      }
      int marks = 0;
      j++;
      while(line[j] == ' ' || line[j] == '\t'){
        j++;
      } 
      if(line[j] == '-'){
        if(numRejects == maxNumErrors){
          return -7;
        }
        rejects.rejects[numRejects++] = fileLineNumber;
        continue;
      }
      else if(line[j] == ',' || line[j] == '\0'){
      		if(numRejects == maxNumErrors)
      	 	 	return -46;
      		rejects.rejects[numRejects++] = fileLineNumber;
      		continue;
      }
      while(line[j] != '\0'){
        if(line[j] >= '0' && line[j] <= '9')
          marks = marks*10+(int)(line[j]) - 48;
        else if(line[j] != '\r'){
        	if(numRejects == maxNumErrors)
         	 	return -56;
        	rejects.rejects[numRejects++] = fileLineNumber;
        	break;
        }
        j++;
      }
      if(rejects.rejects[numRejects-1] == fileLineNumber)
      	continue;      
      data.students[numData].studentID = ID;
      data.students[numData].grade = marks;
      numData++;
    }
    data.numStudents = numData;
    rejects.numRejects = numRejects; 
    return numRejects;
}

int computeStatistics(Dataset& data, Statistics& stats){
	if(data.numStudents <= 1)
		return -1;
	float min = FLT_MAX;
	float max = FLT_MIN;
	float sum = 0;
	for(int i=0; i<10; i++){
	  stats.histogram[i] = 0;
	}
	for(int i = 0; i < data.numStudents; i++){
	  if(data.students[i].grade < min){
	    min = data.students[i].grade;
	  }
	  if(data.students[i].grade > max){
	    max = data.students[i].grade;
	  }
	  sum += data.students[i].grade;
	  int bucket = data.students[i].grade/10;
	  if(data.students[i].grade == 100)
	    bucket = 9;
	  stats.histogram[bucket] += 1;
	}
	float avg = sum/data.numStudents;
	
	float sum1 = 0;
	for(int i = 0; i < data.numStudents; i++){
	  sum1 += (data.students[i].grade - avg) * (data.students[i].grade - avg);
	}
	float psd = sqrt(sum1 / (data.numStudents));
	float ssd = sqrt(sum1 / (data.numStudents - 1));

	for(int i=0; i< data.numStudents; i++){
		for(int j=0; j<data.numStudents-i-1; j++){
			if(data.students[j].grade > data.students[j+1].grade){
				Student std = data.students[j];
				data.students[j] = data.students[j+1];
				data.students[j+1] = std;
			}
		}
	}
	
	int arr[100]; 
	stats.mode.modes = new int[100];
	for(int i = 0; i < data.numStudents; i++){
		arr[i] = data.students[i].grade;
	}

	int size = data.numStudents;
	int maxFreq = 0;
	int freq[100];
	for(int i=0; i<size; i++){
	  freq[i] = 1;
	}
	int a = 0;
	int j = 0;
	int distinct[size];
	for(int i = 0; i < size;){
	  distinct[a] = arr[i];
	  j = i+1;
	  for(; j < size; j++){
	    if(arr[j] == arr[i]){
	      freq[a]++;
	    }
	    else
	      break;
	  }
	  a++;
	  i=j;
	}
	for(int i = 0; i < a; i++){
	  if(maxFreq < freq[i])
	    maxFreq = freq[i];
	}
	int x = 0;
	for(int i = 0 ; i < a; i++){
	  if(maxFreq == freq[i]){
	    stats.mode.modes[x++] = distinct[i];
	  }
	}

	stats.minimum = min;
	stats.maximum = max;
	stats.average = avg;
	stats.popStdDev = psd;
	stats.smplStdDev = ssd;
	stats.mode.numModes = x;
	return 0;
}

int writeCSV(const char filename[], const Statistics& stats){
	std::ofstream outfile; 
	char name[100];
	int i = 0;
	while(filename[i] != '\0' && filename[i] != '.'){
		name[i] = filename[i];
		i++;
	}
	name[i++] = '.';
	name[i++] = 's';
	name[i++] = 't';
	name[i++] = 'a';
	name[i++] = 't';
	name[i++] = '\0';
	outfile.open(name);
	if (!outfile.is_open())
		return -1;
	outfile << "Minimum: " << stats.minimum << std::endl;
	outfile << "Average: " << stats.average << std::endl;
	outfile << "Maximum: " << stats.maximum << std::endl;
	outfile << "Population Standard Deviation: " << stats.popStdDev << std::endl;
	outfile << "Sample Standard Deviation: " << stats.smplStdDev << std::endl;
	outfile << "Modes: ";

	for(int i = 0; i < stats.mode.numModes; i++)
	{
		if(i == stats.mode.numModes -1)
		{
			outfile << stats.mode.modes[i] << std::endl;
		}

		else
		{
			outfile << stats.mode.modes[i] << ", ";
		}
		
	}

	outfile << "Histogram:" << std::endl;
	outfile << "[0-9]: " << stats.histogram[0] << std::endl;
	outfile << "[10-19]: " << stats.histogram[1] << std::endl;
	outfile << "[20-29]: " << stats.histogram[2] << std::endl;
	outfile << "[30-39]: " << stats.histogram[3] << std::endl;
	outfile << "[40-49]: " << stats.histogram[4] << std::endl;
	outfile << "[50-59]: " << stats.histogram[5] << std::endl;
	outfile << "[60-69]: " << stats.histogram[6] << std::endl;
	outfile << "[70-79]: " << stats.histogram[7] << std::endl;
	outfile << "[80-89]: " << stats.histogram[8] << std::endl;
	outfile << "[90-100]: " << stats.histogram[9] << std::endl;
	return 0;
}
//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

#define isNaN(X) (X != X)  // NaN is the only float that is not equal to itself

int main(const int argc, const char* const argv[]) {
  	
	// Some test driver code here ....
	int minAcceptableID = 0;
	int maxAcceptableID = 200000000;

	Dataset data = {0};
	Rejects rejects = {0};
	Statistics stats = {0};

	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;
	std::cout << readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) << std::endl;
	if(readCSV(argv[1], minAcceptableID, maxAcceptableID, data, rejects) < 0)
	{
		std::cout << ".csv file could not be read" << std::endl;
	}
	else{
		std::cout << "rejects : " << rejects.numRejects << std::endl;
	}

	if (computeStatistics(data, stats) < 0)
	{
		std::cout << "Stats could not be computed" << std::endl;
	}

	if (writeCSV(argv[1], stats) < 0)
	{
		std::cout << ".stat file could not be written" << std::endl;
	}

	std::cout << "Average: " << stats.average << std::endl;
	std::cout << "Minimum: " << stats.minimum << std::endl;
	std::cout << "Maximum: " << stats.maximum << std::endl;
	std::cout << "Population standard deviation: " << stats.popStdDev << std::endl;
	std::cout << "Sample standard deviation: " << stats.smplStdDev << std::endl;
	
	
	for (unsigned char i = 0; i < stats.mode.numModes; i++)
	{
		std::cout << "Mode: " << stats.mode.modes[i] << std::endl;
	}

	for (unsigned char i = 0; i < 10; i++)
	{
		std::cout << "Histogram bin [" << (i*10) << ", " << ((((i+1)*10) - 1) + i/9) << "]: " << stats.histogram[i] << std::endl;
	}
	

	return 0;
}

#endif
