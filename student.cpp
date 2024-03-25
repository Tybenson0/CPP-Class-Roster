#include "student.h"
#include "degree.h"
#include <iomanip>
#include <string>

Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
	DegreeProgram degreeprogram) {
	Id = studentID;
	First = firstName;
	Last = lastName;
	Email = emailAddress;
	Age = age;
	DaysInCourse[0] = daysInCourse1;
	DaysInCourse[1] = daysInCourse2;
	DaysInCourse[2] = daysInCourse3;
	Program = degreeprogram;
}

// setters and getter for ID
void Student::setId(string id) {
	Id = id;
}
string Student::getId() {
	return Id;
}

//setters and getters for first name
void Student::setFirstName(string first) {
	First = first;
}
string Student::getFirstName() {
	return First;
}

//setters and gettters for last name
void Student::setLastName(string last) {
	Last = last;
}
string Student::getLastName() {
	return Last;
}

//setters and getters for email
void Student::setEmail(string email) {
	Email = email;
}
string Student::getEmail() {
	return Email;
}

//setters and getters for age
void Student::setAge(int age) {
	Age = age;
}
int Student::getAge() {
	return Age;
}

//setters and getters for days in course
void Student::setDaysToComplete(int value, int index) {
	DaysInCourse[index] = value;
}
int Student::getDaysToComplete(int index) {
	return DaysInCourse[index];
}

//annoying setters and getters to set degree program
void Student::setDegree(DegreeProgram program) {
	this->Program = program;
}
DegreeProgram Student::getDegree() { 
	return this->Program;
}
// print for printing different parts of the student data
void Student::print(string request) {

	if (request == "Id" || request == "ID") {
		cout << Id;
	}
	else if (request == "First name" || request == "first name") {
		cout << First;
	}
	else if (request == "Last name" || request == "last name") {
		cout << Last;
	}
	else if (request == "Email" || request == "email") {
		cout << Email;
	}
	else if (request == "Age" || request == "age") {
		cout << Age;
	}
	else if (request == "Days in Course" || request == "days in course") {
		cout << "{" << setw(1) << DaysInCourse[0] << ","
			<< setw(2) << DaysInCourse[1] << ","
			<< setw(2) << DaysInCourse[2] << "}";
	}
	else if (request == "Degree Program" || request == "degree program") {
		cout << "";
	}

}
//prints all data
void Student::printAll() {

	string degree = "";
	if (this->Program == DegreeProgram::SOFTWARE) {
		degree = "SOFTWARE";
	} else if (this->Program == DegreeProgram::NETWORK) {
		degree = "NETWORK";
	} else {
		degree = "SECURITY";
	}

	cout << setw(2) << Id << "\t"
		<< setw(5) << First << "\t"
		<< setw(8) << Last << "\t"
		<< setw(25) << Email << "\t"
		<< setw(2) << "Age: " << Age << "\t"
		<< "DaysinCourse: " << "{" << setw(2) << DaysInCourse[0] << ","
		<< setw(2) << DaysInCourse[1] << ","
		<< setw(2) << DaysInCourse[2] << "}\t"
		<< "Degree: " << degree
		<< setw(10);

}