
#include "student.h"
#include <string>


class Roster {

public:

	//Variables for roster.cpp.
	int lastIndex;
	int maxNumStudents;

	//Constructor and deconstructor.
	Roster();
	Roster(int maxNumStudents);
	~Roster();

	//Array of pointers.
	Student** classRosterArray;

	//Parse for each data set in studentData table.
	void parser(std::string set);

	//Sets the instance variables and updates roster.
	void add(std::string studentID,
		std::string firstName,
		std::string lastName,
		std::string emailAddress,
		int age,
		double daysInCourse1,
		double daysInCourse2,
		double daysInCourse3,
		DegreeProgram degreeprogram);

	//Removes the student from the roster by studentID.
	void remove(std::string studentID);

	//Prints a comma-seperated list of all student data.
	void printAll();

	//Prints the average number of days in all three courses.
	void printAverageDaysInCourse(std::string studentID);

	//Finds and displays invalid emails to user.
	void printInvalidEmails();

	//Prints out student information for a degree program using enum type.
	void printByDegreeProgram(DegreeProgram degreeProgram);

};

