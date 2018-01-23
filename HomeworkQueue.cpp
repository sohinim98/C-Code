//////////////////////////////////////////////////////////////
//
// Your #includes here; make sure you are allowed them ...
//

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
	if(assignment.course < 0 || assignment.course > 5 || assignment.assnNum < 0 || assignment.dueMonth < 1 || assignment.dueMonth > 12 || assignment.dueDay < 1 || assignment.dueDay > days[assignment.dueMonth])
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
		delete node;
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
			delete node;
			return true;
		}
		
		HomeworkQueue* node = new HomeworkQueue;
		node->assn = new Assignment;
		*node->assn = assignment;
		node->nextInQueue = curr->nextInQueue;
		curr->nextInQueue = node;
		delete node;
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
	return NULL;
}
int daysTillDue(const HomeworkQueue* q, const COURSE course)
{
	return -1;
}
const Assignment* dueIn(const HomeworkQueue* q, const int numDays)
{
	return NULL;
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
