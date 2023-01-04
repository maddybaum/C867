//
//  main.cpp
//  C867
//
//  Created by Madeline Baum on 1/2/23.
//

#include <iostream>
#include "roster.hpp"

int main(int argc, const char * argv[]) {
    
    cout << " =============================" << std::endl;
    cout << "C867 Scripting and Programming Applications" << std::endl;
    cout << "C++" << std::endl;
    cout << "Madeline Baum" << std::endl;
    cout << "Student ID: 010476624"<< std::endl;
    cout << " =============================" << std::endl;

        // insert code here...
    const string classRoster[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Madeline,Baum,mbaum46@wgu.edu,28,5,5,45,SOFTWARE"
        };
    
    const int numOfStudents = 5;
    
    Roster newRoster;
    
    for(int i = 0; i < numOfStudents; i++){
        newRoster.parse(classRoster[i]);
    }
    cout << "Displaying all students:" << endl;
    newRoster.printAll();
    
    
    cout << "Displaying by SOFTWARE DEGREE:" << endl;
    newRoster.printByDegreeProgram(Degree::SOFTWARE);
    
    cout << "Displaying students with invalid emails: " << endl;
    newRoster.printInvalidEmails();
    
    cout << "Displaying average number of days to complete a course" << endl;
    for(int i = 0; i < numOfStudents; i++) newRoster.printAverageDaysInCourse(newRoster.getStudents()[i]->getStudentID());
    
    cout << "Removing student with ID A3" << endl;
    newRoster.remove("A3");
    
    cout << "Displaying updated roster" << endl;
    newRoster.printAll();
    
    cout << "Deleting A3 again" << endl;
    newRoster.remove("A3");
    
    cout << "Complete" << endl;
    
    return 0;
}
