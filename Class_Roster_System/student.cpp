
#include "student.h"
#include <iostream>
#include <iomanip>


//Empty constructor.
Student::Student() {

	//Intializing variables to default values.
	student_id = "";
	first_name = "";
	last_name = "";
	email = "";
	age = 0;
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = 0;
	}

}

//Constructor with parameters.
Student::Student(std::string student_id,
	std::string first_name,
	std::string last_name,
	std::string email,
	int age,
	double day1, double day2, double day3,
	DegreeProgram degreeprogram) {

	setStudent_id(student_id);
	setFirst_name(first_name);
	setLast_name(last_name);
	setEmail(email);
	setAge(age);
	setDaysToComplete(day1, day2, day3);
	setDegree_program(degreeprogram);

}

//Accessors.
std::string Student::getStudent_id() {
	return this->student_id;
}

std::string Student::getFirst_name() {
	return this->first_name;
}

std::string Student::getLast_name() {
	return this->last_name;
}

std::string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

double* Student::getDaysToComplete() {
	return this->daysToComplete;
}

DegreeProgram Student::getDegree_program() {
	return degreeprogram;
}


//Mutators.
void Student::setStudent_id(std::string student_id) {
	this->student_id = student_id;
}

void Student::setFirst_name(std::string first_name) {
	this->first_name = first_name;
}

void Student::setLast_name(std::string last_name) {
	this->last_name = last_name;
}

void Student::setEmail(std::string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToComplete(double day1, double day2, double day3) {
	this->daysToComplete[0] = day1;
	this->daysToComplete[1] = day2;
	this->daysToComplete[2] = day3;
}

void Student::setDegree_program(DegreeProgram degreeprogram) {
	this->degreeprogram = degreeprogram;
}

//Print specific data.
void Student::Print() {

	//Printing each set of data.
	std::cout << "\n" << getStudent_id() << "	";
	std::cout << "First Name: " << getFirst_name() << "   ";
	std::cout << "Last Name: " << getLast_name() << "   ";
	std::cout << "Age: " << getAge() << "	";
	std::cout << "{";

	//Adding days to complete to array.
	for (int i = 0; i < 3; i++) {

		std::cout << daysToComplete[i];

		if (i < 2) {
			std::cout << ", ";
		}

	}
	std::cout << "}	";

	//Degree Program.
	switch (degreeprogram)
	{
	case DegreeProgram::BUSINESS:
		std::cout << "BUSINESS" << std::endl;
		break;
	case DegreeProgram::CYBERSECURITY:
		std::cout << "CYBERSECURITY" << std::endl;
		break;
	case DegreeProgram::COMPUTERSCIENCE:
		std::cout << "COMPUTERSCIENCE" << std::endl;
		break;
	case DegreeProgram::UNDEFINED:
		std::cout << "UNDEFINED" << std::endl;
		break;
	}

}

//destructor
Student::~Student() {};
