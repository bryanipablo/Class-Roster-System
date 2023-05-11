
#include "roster.h"
#include <iostream>


int main() {

	std::cout << "------------------------------" << std::endl;
	std::cout << "	Class Roster Management System			" << std::endl;
	std::cout << "	Language: C++			" << std::endl;
	std::cout << "	By Bryan Pablo			" << std::endl;
	std::cout << "	May 2023			" << std::endl;
	std::cout << "------------------------------" << std::endl;


	const std::string studentData[] = {
		"A1,Gerald,Smith,Gerald1972@gm ail.com,20,30,35,40,CYBERSECURITY",
		"A2,Emily,Wong,emilywong@gmail.com,21,45,32,38,BUSINESS",
		"A3,Michael,Jones,mjones@yahoo com,20,25,50,30,COMPUTERSCIENCE",
		"A4,Lisa,Chen,lisachen@comcast.net,23,55,62,42,CYBERSECURITY",
		"A5,David,Nguyen,davidnguyen smc.edu,22,30,45,50,COMPUTERSCIENCE"
	};

	const int numStudents = sizeof(studentData) / sizeof(studentData[0]);

	//Setting up instance.
	Roster classRoster(numStudents);

	//Parse each row.
	for (int i = 0; i < numStudents; i++) {
		classRoster.parser(studentData[i]);
	}

	std::cout << "\nWelcome to Class Roster Management System!" << std::endl;

	classRoster.printAll();

	classRoster.printInvalidEmails();

	//loop through classRosterArray and for each element:

	std::cout << "\nDisplaying Average Days for Each Student: " << std::endl;
	std::cout << "\n";

	for (int i = 0; i < 5; i++) {

		std::string tempStudentID = classRoster.classRosterArray[i]->getStudent_id();

		classRoster.printAverageDaysInCourse(tempStudentID);

	}

	classRoster.printByDegreeProgram(DegreeProgram::COMPUTERSCIENCE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	//expected: the above line should print a message saying such a student with this ID was not found.


}