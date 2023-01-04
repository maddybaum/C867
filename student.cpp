//
//  student.cpp
//  C867
//
//  Created by Madeline Baum on 1/2/23.
//

#include <iostream>
#include <iomanip>
#include <string>

#include "student.hpp"
#include "Degree.hpp"

using namespace std;

Student::Student()//Paramterless constructor sets all fields to the default values
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for(int i = 0; i < daysArrSize; i++) this ->days[i] = 0;
    this->degree = Degree::UNDECIDED;
}
    Student::Student(string studentID, string firstName, string lastName, string email, int age, double days[], Degree degree)
    {
        this->studentID = studentID;
        this->firstName = firstName;
        this->lastName = lastName;
        this->email = email;
        this->age = age;
        for(int i = 0; i < daysArrSize; i++) this->days[i] = days[i];
        this->degree = degree;
    }
    Student::~Student() {}
    
//getters
string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this-> age; }
const double* Student::getDays() { return this-> days; }
Degree Student::getDegree() { return this->degree; }

//setters
void Student::setStudentID(string ID) { this->studentID = ID; }
void Student::setFirstName(string stuFirstName) { this->firstName = stuFirstName; }
void Student::setLastName(string stuLastName) { this->lastName = stuLastName; }
void Student::setEmail(string stuEmail){ this->email = stuEmail; }
void Student::setAge(int stuAge) { this->age = stuAge; }
void Student::setDays(const double days[])
{
    for (int i = 0; i < daysArrSize; i++) this-> days[i] = days[i];
}
void Student::setDegree(Degree stuDegree) { this->degree = stuDegree; }

void Student::printHeader()
{
    cout << "ID\t";
    cout << "First Name\t";
    cout << "Last Name\t";
    cout << "Email\t";
    cout << "Age\t";
    cout << "Days\t";
    cout << "Degree\t";
    cout << endl;
}
void Student::print()
{
    cout << this->studentID << '\t';
    cout << this->firstName << '\t';
    cout << this->lastName << '\t';
    cout << this->email << '\t';
    cout << this->age << '\t';
    cout << this->days[0] << '\t';
    cout << this->days[1] << '\t';
    cout << this->days[2] << '\t';
    cout << degreeStrings[(int)this->degree];
    cout << endl;
}
