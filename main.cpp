// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "student.h"
#include "roster.cpp"



using namespace std;



int main()
{
    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
      "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
      "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
      "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
      "A5,Tyler,Benson,Tbens75@wgu.edu,22,3,5,7,SOFTWARE"
    };
    

    cout << "Language: C++\nName: Tyler Benson\n\n" <<
        "-------------------------------------------\n\n";
    
            Roster classRoster;

            for (int i = 0; i < 5; i++) {
                classRoster.parse(studentData[i]);
            }

    
            classRoster.printAll();


    cout << "\n\n-----------------------------------------------------------------------------------\n\n";


    classRoster.printInvalidEmails();


    cout << "\n\n-----------------------------------------------------------------------------------\n\n";
    

            cout << "Average days in course for the student roster:\n \n";
            for (int i = 0; i < classRoster.getCurrentSize(); i++) {
                string currentId = classRoster.getId(i);
                classRoster.printAverageDaysInCourse(currentId);
                cout << endl;
            }

    cout << "\n\n-----------------------------------------------------------------------------------\n\n";


            cout << "Students who are in the Software program\n";
            for (int i = 0; i < classRoster.getCurrentSize(); i++) {
        
                classRoster.printByDegreeProgram(SOFTWARE, i);
            }

    cout << "\n\n-----------------------------------------------------------------------------------\n\n";
   

            classRoster.remove("A3");

            cout << endl << "The remaining students in the class are: " << endl << endl;

            classRoster.printAll();

            cout << endl << endl;

            classRoster.remove("A3");

    cout << "\n\n-----------------------------------------------------------------------------------\n\n";



    return 0;

    
}

