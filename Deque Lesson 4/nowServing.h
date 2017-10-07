/***********************************************************************
 * Header:
 *    NOW SERVING
 * Summary:
 *    This will contain just the prototype for nowServing(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Mark Baldwin
 ************************************************************************/

#ifndef NOW_SERVING_H
#define NOW_SERVING_H

// All includes
#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"     // for DEQUE


//All using
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;


// the interactive nowServing program
class nowServing
{
public:
	nowServing();
	
	//Display methods
	void display(std::string classID, std::string StudentID, int timeLeft);
	void displayEmergency(std::string classID, std::string studentID, int timeLeft);

	//Getters and Setters
	void getUserInfo(int requestCount);
	std :: string getClassID();
	void setClassID();
	std :: string getStudentID();
	void setStudentID();
	int getTimeLeft();
	void setTimeLeft();
	bool getPanic();
	void setPanic();

private:
	// All the deques
	deque<std::string> studentClassIdDeque;
	deque<std::string> studentIdDeque;
	deque<bool> studentPanicDeque;
	deque<int> studentTimeNeededDeque;
	
	//All variables
	std::string userInfo;
	bool panic;
	std::string classID;
	std::string studentID;
	int timeNeeded;
	int timeLeft;
	int requestCount;

};
#endif // NOW_SERVING_H

