#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include <iomanip>

using namespace std; 

class Student {
	
	private:
		string Id;
		string First;
		string Last;
		string Email;
		int Age;
		int DaysInCourse[3];
		DegreeProgram Program;

	public:

		Student(string studentID, string firstName, string lastName, string emailAddress,
			int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
			DegreeProgram degreeprogram);


		void setId(string id);
		string getId();

		void setFirstName(string first);
		string getFirstName();

		void setLastName(string last);
		string getLastName();

		void setEmail(string email);
		string getEmail();

		void setAge(int age);
		int getAge();

		void setDaysToComplete(int value, int index);
		int getDaysToComplete(int index);
		
		
		void setDegree(DegreeProgram program);
		DegreeProgram getDegree();

		void print(string request);
		void printAll();
		
};