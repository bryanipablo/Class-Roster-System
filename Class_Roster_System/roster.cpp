
#include "roster.h"
#include <iostream>
#include <regex>


//Constructor.
Roster::Roster() {
	this->maxNumStudents = 0;
	this->lastIndex = 0;
	this->classRosterArray = NULL;
}

Roster::Roster(int maxNumStudents) {
	this->maxNumStudents = maxNumStudents;
	this->lastIndex = 0;
	this->classRosterArray = new Student * [maxNumStudents];
	for (int i = 0; i < maxNumStudents; ++i) {
		this->classRosterArray[i] = NULL;
	}
}

//Parse for each data set in studentData table then populate table.
void Roster::parser(std::string set) {

	//Finding studentID.
	size_t rhs = set.find(",");
	std::string tempStudentID = set.substr(0, rhs);

	//Finding firstName.
	size_t lhs = rhs + 1;
	rhs = set.find(",", lhs);
	std::string tempFirstName = set.substr(lhs, rhs - lhs);

	//Finding lastName.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	std::string tempLastName = set.substr(lhs, rhs - lhs);

	//Finding emailAddress.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	std::string tempEmailAddress = set.substr(lhs, rhs - lhs);

	//Finding age.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	int tempAge = std::stoi(set.substr(lhs, rhs - lhs));

	//Finding day1.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	double tempDay1 = std::stod(set.substr(lhs, rhs - lhs));

	//Finding day2.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	double tempDay2 = std::stod(set.substr(lhs, rhs - lhs));

	//Finding day3.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	double tempDay3 = std::stod(set.substr(lhs, rhs - lhs));

	//Finding degree program.
	lhs = rhs + 1;
	rhs = set.find(",", lhs);
	std::string tempDegreeProgram = set.substr(lhs, rhs - lhs);


	//Choosing degree based on parse.
	DegreeProgram degreeProgram = DegreeProgram::UNDEFINED;

	if (tempDegreeProgram == "CYBERSECURITY") {
		degreeProgram = DegreeProgram::CYBERSECURITY;
	}

	else if (tempDegreeProgram == "COMPUTERSCIENCE") {
		degreeProgram = DegreeProgram::COMPUTERSCIENCE;
	}

	else if (tempDegreeProgram == "BUSINESS") {
		degreeProgram = DegreeProgram::BUSINESS;
	}

	else {
		degreeProgram = DegreeProgram::UNDEFINED;
	}

	add(tempStudentID, tempFirstName, tempLastName, tempEmailAddress, tempAge, tempDay1, tempDay2, tempDay3, degreeProgram);

}

//Sets the instance variables and updates roster.
void Roster::add(std::string studentID,
	std::string firstName,
	std::string lastName,
	std::string emailAddress,
	int age,
	double daysInCourse1,
	double daysInCourse2,
	double daysInCourse3,
	DegreeProgram degreeprogram) {

	lastIndex++;
	classRosterArray[lastIndex - 1] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);

}

//Removes the student from the roster by studentID.
void Roster::remove(std::string studentID) {

	bool studentFound = false;
	for (int i = 0; i < lastIndex; i++) {

		//If both conditions are met, bool statement will turn true.
		if (classRosterArray[i] != NULL && classRosterArray[i]->getStudent_id() == studentID) {

			studentFound = true;
			delete classRosterArray[i];
			classRosterArray[i] = NULL;

		}
	}

	//Once the loop is done, if the bool statement is still false, meaning the ID was never found, 
	//the invalid student ID will be displayed.
	if (!studentFound) {
		std::cout << "\nStudent " << studentID << " was not found... " << std::endl;
	}

	else {
		std::cout << "\nStudent " << studentID << " was deleted from roster! " << std::endl;
	}

}

//Prints a comma-seperated list of all student data.
void Roster::printAll() {

	//Printing each student as long as the index isn't null.
	for (int i = 0; i < maxNumStudents; i++) {
		if (classRosterArray[i] != NULL) {
			classRosterArray[i]->Print();
		}
	}

}

//Prints the average number of days in all three courses.
void Roster::printAverageDaysInCourse(std::string studentID) {

	double sum = 0.0;
	double avg = 0.0;

	for (int i = 0; i < lastIndex; i++) {
		if (classRosterArray[i]->getStudent_id() == studentID) {

			//Finding the days for the student and then computes the sum.
			double* days = (classRosterArray[i]->getDaysToComplete());

			sum += days[0] + days[1] + days[2];

		}
	}

	avg = sum / 3;

	std::cout << "Student ID: " << studentID << ", average days in course is: " << avg << std::endl;

}

//Finds and displays invalid emails to user.
void Roster::printInvalidEmails() {

	std::string invalidEmails[5];
	bool isInvalid = false;
	std::string inputEmail;

	const std::regex emailPattern(("(\\S+)(\\.|_)?(\\S*)@(\\S+)(\\.(\\S+))+"));

	for (int i = 0; i < maxNumStudents; i++) {

		//Finds the email for each student, then compares it to the regex pattern given
		//if it's invalid, add the email to the invalidEmail array which is then 
		//displayed to the user.
		inputEmail = classRosterArray[i]->getEmail();

		if (!std::regex_match(inputEmail, emailPattern)) {

			isInvalid = true;
			invalidEmails[i] = inputEmail;

		}
	}

	std::cout << "\nDisplaying Invalid Emails: " << std::endl;
	std::cout << "\n";

	if (isInvalid) {

		for (int i = 0; i < maxNumStudents; i++) {
			if (!invalidEmails[i].empty()) {
				std::cout << invalidEmails[i] << "-- is invalid." << std::endl;
			}
		}

	}

	else {
		std::cout << "No invalid emails found" << std::endl;
	}

}

//Prints out student information for a degree program using enum type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {


	switch (degreeProgram)
	{
	case DegreeProgram::CYBERSECURITY:
		std::cout << "\n" << "Showing Students in Degree Program: CYBERSECURITY" << std::endl;
		break;
	case DegreeProgram::BUSINESS:
		std::cout << "\n" << "Showing Students in Degree Program: BUSINESS" << std::endl;
		break;
	case DegreeProgram::COMPUTERSCIENCE:
		std::cout << "\n" << "Showing Students in Degree Program: COMPUTERSCIENCE" << std::endl;
		break;
	case DegreeProgram::UNDEFINED:
		std::cout << "\n" << "Showing Students in Degree Program: UNDEFINED" << std::endl;
		break;
	}



	//Loops through the students and finds each students with the matching degree program.
	for (int i = 0; i < lastIndex; i++) {
		if (classRosterArray[i]->getDegree_program() == degreeProgram) {
			classRosterArray[i]->Print();
		}
	}

}

//Destructor
Roster::~Roster() {

	for (int i = 0; i < lastIndex; i++) {
		delete classRosterArray[i];
	}
	delete[] classRosterArray;

}

