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
// local #includes and function declarations; do not remove
//

#ifndef MARMOSET_TESTING
#include <iostream>
#endif

//////////////////////////////////////////////////////////////
//
// struct definitions 
//
#ifndef MARMOSET_TESTING

enum COURSE {CHE102, MATH115, MATH117, ECE105, ECE150, ECE190, Null};

struct Assignment 
{
	COURSE course; // CHE102, MATH117, etc.
	int assnNum; // Assignment Number
	int dueMonth; // Month due (1-12)
	int dueDay; // Day due (1-31)
	char* description; // Assignment description
};

struct HomeworkQueue
{
	Assignment* assn;
	HomeworkQueue* nextInQueue;
};

#endif

//////////////////////////////////////////////////////////////
//
// Function declarations; do not remove
//

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment);
const Assignment* dequeue(HomeworkQueue*& queue);
int daysTillDue(const HomeworkQueue* q, const COURSE course);
const Assignment* dueIn(const HomeworkQueue* q, const int numDays);
bool check(const Assignment& assignment1, const Assignment& assignment2);

//////////////////////////////////////////////////////////////
//
// Function definitions. PLEASE USE HELPER FUNCTIONS
//

bool enqueue(HomeworkQueue*& queue, const Assignment& assignment)
{
	int days[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
	if(assignment.course < 0 || assignment.course > 5 || assignment.assnNum < 0 || assignment.dueMonth < 1 || assignment.dueMonth > 12 || assignment.dueDay < 1 || assignment.dueDay > days[assignment.dueMonth] || assignment.description == NULL || assignment.description[0] == '\0')
	return false;
	if(queue->assn == NULL) {
		queue->assn = new Assignment;
		*queue->assn = assignment;
		queue->nextInQueue = NULL;
		return true;
	}
	HomeworkQueue* curr = queue; //storing the value of head in curr
	
	if(!check(*curr->assn,assignment)) {
		HomeworkQueue* node = new HomeworkQueue;
		node->assn = new Assignment;
		*node->assn = assignment;
		node->nextInQueue = curr;
		queue = node;
		node = NULL;
		return true;
	}
	else {
		while(curr->nextInQueue != NULL && check(*curr->nextInQueue->assn,assignment)) {
			curr = curr->nextInQueue;
		}
		if(curr->nextInQueue == NULL) {
			HomeworkQueue* node = new HomeworkQueue;
			node->assn = new Assignment;
			*node->assn = assignment;
			curr->nextInQueue= new HomeworkQueue;
			curr->nextInQueue = node;
			node = NULL;
			return true;
		}
		
		HomeworkQueue* node = new HomeworkQueue;
		node->assn = new Assignment;
		*node->assn = assignment;
		node->nextInQueue = curr->nextInQueue;
		curr->nextInQueue = node;
		node = NULL;
		return true;
	}
}
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
const Assignment* dequeue(HomeworkQueue*& queue)
{
	if(queue != NULL) {
		Assignment* ass = new Assignment;
		ass = queue->assn;
		queue->assn = NULL;
		queue = queue->nextInQueue;
		return ass;
	}
}
int daysTillDue(const HomeworkQueue* q, const COURSE course)
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
		
		HomeworkQueue que = *q;
		HomeworkQueue* curr = &que;
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
const Assignment* dueIn(const HomeworkQueue* q, const int numDays)
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
	
	HomeworkQueue que = *q;
	HomeworkQueue* curr = &que;
	
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

//////////////////////////////////////////////////////////////
//
// Test Driver
//
// Do not remove the #ifndef and its associated #endif
//

#ifndef MARMOSET_TESTING

int main(const int argc, const char* const argv[]) {
  		// Some test driver code here ....
	std::cout << std::endl << "Implement some more appropriate tests in main()" << std::endl << std::endl;

	HomeworkQueue* p_queue = new HomeworkQueue;
	p_queue->nextInQueue = NULL;
	p_queue->assn = NULL;

	char sampleDescription[] = "Sequential Execution";
	Assignment assn1 = 
	{
		.course = ECE150,
		.assnNum = 0,
		.dueMonth = 9,
		.dueDay = 15,
		.description = sampleDescription
	};
	
	bool enqueueSuccess = enqueue(p_queue, assn1);

	if(enqueueSuccess)
	{
		std::cout << "assn1 enqueued successfully" << std::endl << std::endl;

	}
	else
	{
		std::cout << "enqueue() failed" << std::endl << std::endl; 
	}

	const Assignment* p_firstAssignmentInQueue = dequeue(p_queue);
	
	if (p_firstAssignmentInQueue)
	{
		std::cout << "Dequeue successful..." << std::endl;
		std::cout << "Course: " << p_firstAssignmentInQueue->course << std::endl;
		std::cout << "Assignment #: " << p_firstAssignmentInQueue->assnNum << std::endl;
		std::cout << "Day due: " << p_firstAssignmentInQueue->dueDay << std::endl;
		std::cout << "Month due: " << p_firstAssignmentInQueue->dueMonth << std::endl;
		std::cout << "Description: " << p_firstAssignmentInQueue->description << std::endl;
	}
	else
	{
		std::cout << "dequeue() failed" << std::endl;
	}

	delete p_queue;

	return 0;
}

#endif
