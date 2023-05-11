
#include <string>
#include "degree.h"


class Student {

private:

	std::string student_id;
	std::string first_name;
	std::string last_name;
	std::string email;
	int age;
	double daysToComplete[3];
	DegreeProgram degreeprogram;


public:

	//Empty constructor.
	Student();

	//Constructor with parameters.
	Student(std::string student_id,
		std::string first_name,
		std::string last_name,
		std::string email,
		int age,
		double day1, double day2, double day3,
		DegreeProgram degreeprogram);

	//Accessors.
	std::string getStudent_id();
	std::string getFirst_name();
	std::string getLast_name();
	std::string getEmail();
	int getAge();
	double* getDaysToComplete();
	DegreeProgram getDegree_program();

	//Mutators.
	void setStudent_id(std::string id);
	void setFirst_name(std::string first_name);
	void setLast_name(std::string last_name);
	void setEmail(std::string email);
	void setAge(int age);
	void setDaysToComplete(double day1, double day2, double day3);
	void setDegree_program(DegreeProgram degreeprogram);

	//Print specific data.
	void Print();

	//Destructor.
	~Student();


};

