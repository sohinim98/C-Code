//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//
#include <math.h>
#include <float.h>
#include <fstream>
#include <stdlib.h>
#include <limits.h>
//////////////////////////////////////////////////////////////
//
// #includes for local testing only
//


#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// Enums and structs for use in assignment 

#ifndef MARMOSET_TESTING
enum COURSE
{
	CHE102,
	MATH115,
	MATH117,
	ECE105,
	ECE150,
	ECE190,
	Null
};

struct Assignment
{
	COURSE course;       
	int    assnNum;      // Assignment number
	int    dueMonth;     // 1-12
	int    dueDay;       // 1-31
	char*  description;  // Assignment description
};


#endif


//////////////////////////////////////////////////////////////
//
// Class declaration; modify but do not remove
struct HWQ
{
	Assignment* assn;
	HWQ* nextInQueue;
};		
bool check(const Assignment& assignment1, const Assignment& assignment2)
{
	if(assignment1.dueMonth < assignment2.dueMonth) {
		return true;
	}
	else if(assignment1.dueMonth == assignment2.dueMonth) {
		if(assignment1.dueDay <= assignment2.dueDay)
			return true;
		else
			return false;
	}
	else
		return false;
}					 
class HomeworkQueue 
{
public:
	//bool check(const Assignment& assignment1, const Assignment& assignment2);
    bool                enqueue(const Assignment& assignment);
    const Assignment*   dequeue();
    int                 daysTillDue(const COURSE course);
    const Assignment*   dueIn(const int numDays);


    HomeworkQueue();    //constructor
    ~HomeworkQueue();   //destructor
private:
HWQ* q = NULL;  
	
};


//////////////////////////////////////////////////////////////
//
// Your code here ...
//  

bool HomeworkQueue::enqueue(const Assignment& assignment)
{
	int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	if(assignment.course < 0 || assignment.course > 5 || assignment.assnNum < 0 || assignment.dueMonth < 1 || assignment.dueMonth > 12 || assignment.dueDay < 1 || assignment.dueDay > days[assignment.dueMonth] || assignment.description == NULL || assignment.description[0] == '\0')
	return false;
	if(q->assn == NULL) {
		q->assn = new Assignment;
		*q->assn = assignment;
		q->nextInQueue = NULL;
		return true;
	}
	HWQ* curr = q; //storing the value of head in curr
	
	if(!check(*curr->assn,assignment)) {
		HWQ* node = new HWQ;
		node->assn = new Assignment;
		*node->assn = assignment;
		node->nextInQueue = curr;
		q = node;
		node = NULL;
		return true;
	}
	else {
		while(curr->nextInQueue != NULL && check(*curr->nextInQueue->assn,assignment)) {
			curr = curr->nextInQueue;
		}
		if(curr->nextInQueue == NULL) {
			HWQ* node = new HWQ;
			node->assn = new Assignment;
			*node->assn = assignment;
			curr->nextInQueue= new HWQ;
			curr->nextInQueue = node;
			node = NULL;
			return true;
		}
		
		HWQ* node = new HWQ;
		node->assn = new Assignment;
		*node->assn = assignment;
		node->nextInQueue = curr->nextInQueue;
		curr->nextInQueue = node;
		node = NULL;
		return true;
	}
}

const Assignment* HomeworkQueue::dequeue()
{
	if(q != NULL) {
		Assignment* ass = new Assignment;
		ass = q->assn;
		q->assn = NULL;
		q = q->nextInQueue;
		return ass;
	}
}

int HomeworkQueue::daysTillDue(const COURSE course)
{
	if(q == NULL) {
		return INT_MAX;
	}
		struct tm *theTime;
		time_t tim;
		time(&tim);
		theTime = localtime(&tim);
		int currentMonth = theTime->tm_mon + 1;
		int currentDay = theTime->tm_mday;
		
		HWQ que = *q;
		HWQ* curr = &que;
		while(curr != NULL) {
			while(curr != NULL && curr->assn->course != course) {
				curr = curr->nextInQueue;
			}
			if(curr == NULL)
				return INT_MAX;
			int months = curr->assn->dueMonth - currentMonth;
			int days = 0;
			months *= 30;
			days += curr->assn->dueDay - currentDay + months;
			return days;
		}
	return INT_MAX;
}

const Assignment* HomeworkQueue::dueIn(const int numDays)
{
	
	if(q == NULL) {
		Assignment* ass = new Assignment;
		ass->course = Null;
		return ass;
	}
	int len = 1;
	int c=0;
	Assignment* list = new Assignment[len];
	
	struct tm *theTime;
	time_t tim;
	time(&tim);
	theTime = localtime(&tim);
	int currentMonth = theTime ->tm_mon+1;
	int currentDay = theTime ->tm_mday;
	
	HWQ que = *q;
	HWQ* curr = &que;
	
	while(curr != NULL) {
		int months = curr->assn->dueMonth - currentMonth;
		int days;
		months *= 30;
			days = curr->assn->dueDay - currentDay;
			
			if(days <= numDays) {
				if(c == 0){
					list[0] = *curr->assn;
					c++;
				}
				else {
					Assignment* copy = new Assignment[len];
					for(int i=0;i<len;i++) {
						copy[i] = list[i];
					}
					list = new Assignment[len+1];
					for(int i=0; i<len;i++) {
						list[i] = copy[i];
					}
					list[len] = *curr->assn;
					len++;
				}
			}
			curr = curr->nextInQueue;
	}
	Assignment* ass = new Assignment[1];
	ass->course = Null;
	if(curr == NULL && c == 0) {
		return ass;
	}
	Assignment *temp = new Assignment[len];
	for(int i=0;i<len;i++) {
		temp[i] = list[i];
	}
	list = new Assignment[len+1];
	for(int i=0;i<len;i++) {
		list[i] = temp[i];
	}
	list[len] = ass[0];
	return list;
	
}

HomeworkQueue::HomeworkQueue()
{

}

HomeworkQueue::~HomeworkQueue()
{
	
    HWQ* clean = q;
    HWQ* tmp = q;
    while(tmp != NULL){
        tmp = clean->nextInQueue;
        delete clean;
        clean = tmp;
    }
}



		

#ifndef MARMOSET_TESTING
int main(const int argc, const char* const args[]) 
{
	//formatting
	std::cout << std::endl;

	HomeworkQueue hwq;

	char boring[] = "Something something solubility something something gases something";

	Assignment someAssignment = 
	{
		.course = CHE102,
		.assnNum = 1000000,
		.dueMonth = 12,
		.dueDay = 4,
		.description = boring
	};

	if(!hwq.enqueue(someAssignment))
	{
		std::cout << "enqueue() unsuccessful" << std::endl;
	}
	else
	{
		std::cout << "enqueue() successful" << std::endl;
	}

	const Assignment* assnInTheQueue = hwq.dequeue();

	if (!assnInTheQueue)
	{
		std::cout << "dequeue() unsuccessful" << std::endl;

	}
	else 
	{
		std::cout << "dequeue() successful" << std::endl;
	}

	//formatting
	std::cout << std::endl;

    return 0;
}
#endif
