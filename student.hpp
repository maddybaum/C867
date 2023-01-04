//
//  student.hpp
//  C867
//
//  Created by Madeline Baum on 1/2/23.
//

#ifndef student_hpp
#define student_hpp

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "Degree.hpp"
#endif /* student_hpp */

using std::string;
using std::cout;
using std::endl;
using std::left;
using std::setw;

class Student//What a student is and does
{
public: const static int daysArrSize = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    double days[daysArrSize];
    Degree degree;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, double days[], Degree degree);
    ~Student();
    
    //getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    const double* getDays(); //returns a pointer because cannot return an array
    Degree getDegree();
    
    //setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string email);
    void setAge(int age);
    void setDays(const double days[]);
    void setDegree(Degree degree);
    
    static void printHeader();
    
    void print();
};
