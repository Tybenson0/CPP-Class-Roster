#pragma once

#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


class Roster {

private:
	Student* classRosterArray[5];
	int currentIndex;
	int currentOpen;



public:

	~Roster();


	void parse(const string& data);


	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void remove(const string& Id);

	void printAverageDaysInCourse(string studentID);
	
	string getId(int index);

	int getCurrentSize();

	void printByDegreeProgram(DegreeProgram degreeProgram, int index);


	void print(string arg, int index);
	void printAll();





};