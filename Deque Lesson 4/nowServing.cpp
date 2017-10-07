/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Mark Baldwin
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
 nowServing:: nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";

   // your code here
   classID = "EMPTY";
requestCount = 0;
timeLeft = 0;


do {

	getUserInfo(requestCount);
	
	
	if (timeLeft > 0)
	{
		
		if (classID != "EMPTY" && panic != true)
		{
			display(classID, studentID, timeLeft);
		}
		else if (classID != "EMPTY" && timeLeft > 0)
		{
			displayEmergency(classID, studentID, timeLeft);
		}
		this->timeLeft--;
	}
	else if (!studentTimeNeededDeque.empty())
	{
		setClassID();
		setStudentID();
		setTimeLeft();
		setPanic();

		if (classID != "EMPTY" && panic != true)
		{
			display(classID, studentID, timeLeft);
		}
		else if (classID != "EMPTY" && timeLeft > 0)
		{
			displayEmergency(classID, studentID, timeLeft);
		}
		this->timeLeft--;
	}

} 
while(userInfo != "finished");

   // end
   std::cout << "End of simulation\n";
}

 /*******************************************
 * NOWSERVING :: GET USER INFO METHOD
 *******************************************/
void nowServing::getUserInfo(int requestCount)
{
	
	string tempClassID;
	string tempStudentID;
	bool tempPanic;
	int tempTimeNeeded;


		std::cout << "<" << requestCount << "> ";
		std::cin >> userInfo;

		if (userInfo != "none" && userInfo != "finished" && userInfo != "!!")
		{
			//Break input string up and store in temp locations
			tempClassID = userInfo;
			std::cin >> tempStudentID;
			std::cin.ignore();
			std::cin >> tempTimeNeeded;
			std::cin.ignore();
			
			tempPanic = false;

			//push info onto the back of deque
			studentClassIdDeque.push_back(tempClassID);
			studentIdDeque.push_back(tempStudentID);
			studentTimeNeededDeque.push_back(tempTimeNeeded);
			studentPanicDeque.push_back(tempPanic);


		}
		else if (userInfo != "none" && userInfo != "finished")
		{
			//Break input string up and store in temp locations
			string holder;
			holder = userInfo;              //Give the "!!" somewhere to go and then continue
			std::cin >> tempClassID;
			std::cin.ignore();
			std::cin >> tempStudentID;
			std::cin.ignore();
			std::cin >> tempTimeNeeded;
			std::cin.ignore();

			tempPanic = true;

			//push info onto the front of deque
			studentClassIdDeque.push_front(tempClassID);
			studentIdDeque.push_front(tempStudentID);
			studentTimeNeededDeque.push_front(tempTimeNeeded);
			studentPanicDeque.push_front(tempPanic);

		}
		this->requestCount++;

		return;

}


/*******************************************
* NOWSERVING :: DISPLAY METHOD
*******************************************/
void nowServing:: display(std::string classID, std::string studentID, int timeLeft)
{
	std::cout << "\tCurrently serving " << studentID << " for class " << classID << "."
		<< " Time left: " << getTimeLeft() << "\n";
}

/*******************************************
* NOWSERVING :: EMERGENCY DISPLAY METHOD
*******************************************/
void nowServing::displayEmergency(std::string classID, std::string studentID, int timeLeft)
{
	std::cout << "\tEmergency for " << studentID << " for class " << classID << "."
		<< " Time left: " << getTimeLeft() << "\n";
}

/*******************************************
* NOWSERVING :: GET CLASS ID METHOD
*******************************************/
std:: string nowServing::getClassID()
{
	return classID;
}

/*******************************************
* NOWSERVING :: SET CLASS ID METHOD
*******************************************/
void nowServing::setClassID()
{
	this->classID = studentClassIdDeque.front();
	if (!studentClassIdDeque.empty())
	{
		studentClassIdDeque.pop_front();

	}
}

/*******************************************
* NOWSERVING :: GET STUDENT ID METHOD
*******************************************/
std ::string nowServing::getStudentID()
{
	return studentID;
}

/*******************************************
* NOWSERVING :: SET STUDENT ID METHOD
*******************************************/
void nowServing::setStudentID()
{
	this->studentID = studentIdDeque.front();
	if (!studentIdDeque.empty())
	{
		studentIdDeque.pop_front();
	}
}

/*******************************************
* NOWSERVING :: GET TIME LEFT METHOD
*******************************************/
int nowServing::getTimeLeft()
{
	return timeLeft;
}

/*******************************************
* NOWSERVING :: SET TIME LEFT METHOD
*******************************************/
void nowServing::setTimeLeft()
{
	this->timeLeft = studentTimeNeededDeque.front();
	if (!studentTimeNeededDeque.empty())
	{
		studentTimeNeededDeque.pop_front();
	}
}

/*******************************************
* NOWSERVING :: GET PANIC METHOD
*******************************************/
bool nowServing::getPanic()
{
	return panic;
}

/*******************************************
* NOWSERVING :: SET PANIC METHOD
*******************************************/
void nowServing::setPanic()
{
	this->panic = studentPanicDeque.front();
	if (!studentPanicDeque.empty())
	{
		studentPanicDeque.pop_front();
	}

}


