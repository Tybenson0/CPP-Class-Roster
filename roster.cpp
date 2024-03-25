
#include "degree.h"
#include "student.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


class Roster{

	private:
		Student* classRosterArray[5];
		//tracks current index
		int currentIndex = 0;

		//keeps track of the current open index
		int currentOpen = -1;



	public:

		~Roster() {
			// Deallocate memory for each student object in the array
			for (int i = 0; i < getCurrentSize(); ++i) {
				delete classRosterArray[i];
			}
		}


	void parse(const string& data) {
		//initialize data variables to be parsed to the add method.
		string Id;
		string First;  
		string Last;
		string Email;
		int Age;
		int DaysToComplete[3];
		DegreeProgram Program;

		//create a stringstream object to capture each piece of data
		stringstream ss(data);
		

		getline(ss, Id, ',');
		getline(ss, First, ',');
		getline(ss, Last, ',');
		getline(ss, Email, ',');
		ss >> Age;
		ss.ignore(); 

		string day1, day2, day3;
		getline(ss, day1, ',');
		getline(ss, day2, ',');
		getline(ss, day3, ',');

		// Convert string days to integers, and append to array
		DaysToComplete[0] = stoi(day1);
		DaysToComplete[1] = stoi(day2);
		DaysToComplete[2] = stoi(day3);

		string programStr;
		getline(ss, programStr, ','); // Read the DegreeProgram from the string, and toggle which value is assigned.
		if (programStr == "SOFTWARE")
			Program = DegreeProgram::SOFTWARE;
		else if (programStr == "NETWORK")
			Program = DegreeProgram::NETWORK;
		else if (programStr == "SECURITY")
			Program = DegreeProgram::SECURITY;

		add(Id, First, Last, Email, Age, DaysToComplete[0], DaysToComplete[1], DaysToComplete[2], Program); 
	}
	

	//start of Add method
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {


		//create new student pointer 
		Student* newStudent = new Student(studentID, firstName, lastName, emailAddress,
			age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

		//checks if we have a currently open index
		if (currentOpen > -1) {
			classRosterArray[currentOpen] = newStudent;
			currentOpen = -1;
		}
		//if there we have not deleted any students yet, the array just fills
		else if (currentIndex < 5) { 
			// Add the new student to the array
			classRosterArray[currentIndex] = newStudent;
			currentIndex++; 
		}
		else {
			cout << "Array is full. Cannot add more students via add." << endl;
		}
	}
	void remove(const string& Id) {
		bool found = false; //checks if we found the Id

			//loops through the classrosterArray
		for (int i = 0; i < getCurrentSize(); i++) {
			if (classRosterArray[i] != nullptr && classRosterArray[i]->getId() == Id) {
				delete classRosterArray[i];
				cout << "Successfully removed the student with the ID: " << Id;
				cout << endl;
				// Shift remaining elements to fill the gap
				for (int j = i; j < getCurrentSize() - 1; ++j) { 
					classRosterArray[j] = classRosterArray[j + 1];
				}
				classRosterArray[4] = nullptr; // Set the last element to null pointer
				found = true;
				break;
			}
		}
		//sets the currently open position to the 4th index
		currentOpen = 4;
		if (!found) {
			cout << "Student with the Id: " << Id << " not found.\n";
		}
	}

	void printAverageDaysInCourse(string studentID) {
		string currentId; //tracks the current id in the array
		for (int i = 0; i < 5; i++) {
			currentId = classRosterArray[i]->getId(); 
			if (currentId == studentID) {

				int num1 = classRosterArray[i]->getDaysToComplete(0);
				int num2 = classRosterArray[i]->getDaysToComplete(1);
				int num3 = classRosterArray[i]->getDaysToComplete(2);

				cout << "The average days in a course for the user with the Id " << studentID << " is " << (num1 + num2 + num3) / 3 << endl;
				break;
			}
			
		}
		//catch case
		if (currentId != studentID) {
			cout << "Student with the Id: " << studentID << " not found. \n";
		}

	}
	//used to get the current index for the loop in the main
	string getId(int index) {
		string id = classRosterArray[index]->getId();
		return id;
	}


	//gets the current size of the array and returns it as an integer
	int getCurrentSize() {
		int size = 0;
		for (int i = 0; classRosterArray[i] != nullptr; i++) {
			size++;
			if (size > 4) {
				break;
			}
		}
		return size;
	}

	void printByDegreeProgram(DegreeProgram degreeProgram, int index) {
			DegreeProgram currentDegree = classRosterArray[index]->getDegree(); //gets the degree enum
			if (currentDegree == degreeProgram) { //compares each degree until it matches the supplied degreeProgram variable
				classRosterArray[index]->printAll(); // prints matches
				cout << endl;
			}
	}


	void print(string arg, int index) { // not used in the program but checks a specific data type from a student like their age, name, etc..
		
			classRosterArray[index]->print(arg);
	}
	void printAll() { 
		for (int i = 0; i < getCurrentSize(); i++) {
		 // Check if the pointer is not null
			if (classRosterArray[i] == nullptr) {
				continue;
			}
			//loops through all students and prints all data
				classRosterArray[i]->printAll();
				cout << endl;
			
		}
	}


	void printInvalidEmails() {
		cout << "These emails are invalid: \n \n ";
		for (int i = 0; i < getCurrentSize(); i++) {
			std::string currentEmail = classRosterArray[i]->getEmail();
			bool isValid = true; // Assume the email is valid until proven otherwise
			bool hasAtSymbol = false;
			bool hasPeriod = false;

			// Loop through each character in the email
			for (int j = 0; j < currentEmail.length(); j++) {
				// Check for spaces
				if (currentEmail[j] == ' ') {
					isValid = false; 
					break; 
				}
				// Check for '@' symbol
				else if (currentEmail[j] == '@') {
					hasAtSymbol = true;
				}
				// Check for '.' symbol
				else if (currentEmail[j] == '.') {
					hasPeriod = true;
				}
			}

			// If email is missing '@' or '.', it's invalid
			if (!hasAtSymbol || !hasPeriod) {
				isValid = false;
			}

			// Print invalid emails if false flag is raised
			if (!isValid) {
				std::cout << currentEmail << " is an invalid email address." << std::endl;
			}
		}
	}


	
	

};