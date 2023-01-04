//
//  roster.cpp
//  C867
//
//  Created by Madeline Baum on 1/2/23.
//

#include "roster.hpp"

using namespace std;

Student**Roster::getStudents()
{
    return Roster::students;
}

void Roster::parse(string studentData)
{
    Degree d = Degree::UNDECIDED;
    if(studentData.back() == 'Y') d = Degree::SECURITY;
    else if (studentData.back() == 'K') d = Degree::NETWORK;
    else if (studentData.back() == 'E') d = Degree::SOFTWARE;
    
    int rhs = studentData.find(",");
    string sID = studentData.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string email = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int days0 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int days1 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int days2 = stoi(studentData.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);

    add(sID, firstName, lastName, email, age, days0, days1, days2, d);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, double day1, double day2, double day3, Degree degree)
{
    double daysArr[3] = { day1, day2, day3 }; //put the values back into an array
    students[++lastIndex] = new Student(studentID, firstName, lastName, email, age, daysArr, degree);
    cout << "Student added to roster at row " << lastIndex + 1 << endl;
}

void Roster::printAll()
{
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++) Roster::students[i]-> print();
}

void Roster::printByDegreeProgram(Degree chosenDegree)
{
    Student::printHeader();
    for(int i = 0; i <= Roster::lastIndex; i++)
        if(Roster::students[i]->getDegree() == chosenDegree) students[i]->print();
}
void Roster::printInvalidEmails()
{
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        string email = Roster::getStudents()[i]->getEmail();
        if(email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos)
            cout << email << " is invalid " << endl;
    }
}
void Roster::printAverageDaysInCourse(string studentID)
{
    for(int i = 0; i <= Roster::lastIndex; i++)
    {
        if (students[i]-> getStudentID() == studentID)
        {
            cout << studentID << ":";
            cout << (students[i]->getDays()[0] +
                     students[i]->getDays()[1] +
                     students[i]->getDays()[2]) / 3.0 << endl;
        }
    }
}
void Roster::remove(string idToDelete)
{
    bool success = false;
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
        if(students[i]->getStudentID() == idToDelete){
            success = true;
            Student* tempStudent = students[i];
            students[i] = students[numStudents - 1];
            students[numStudents - 1]= tempStudent;
            Roster::lastIndex--;
        }
    }
    if(success)
    {
        cout << "Student " << idToDelete << " removed." << endl;
        printAll();
    }
    else cout << "Student " << idToDelete << " not found." << endl;
}
Roster::~Roster()
{
    for(int i = 0; i < 5; i++)
    {
        cout << "Destructor called for " << students[i]->getStudentID() << endl;
        delete students[i];
        students[i] = nullptr;
    }
}
