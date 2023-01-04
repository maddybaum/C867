//
//  roster.hpp
//  C867
//
//  Created by Madeline Baum on 1/2/23.
//
#pragma once

#ifndef roster_hpp
#define roster_hpp

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "student.hpp"
#include "Degree.hpp"

class Roster
{
private:
    int lastIndex = -1;
    const static int numStudents = 5;
    
    Student* students[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr }; //no students yet so array has nullptrs
public:
//    Roster();
    ~Roster();
    Student** getStudents();
    //double star because 2 references needed to get to specific student
    void parse(string row);
    
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, double daysInCourse1, double daysInCourse2, double daysInCourse3, Degree degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(Degree degree);
};
#endif /* roster_hpp */
 
