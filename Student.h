//
// Created by Mark Scheer on 8/28/18.
//

#ifndef UNTITLED2_STUDENT_H
#define UNTITLED2_STUDENT_H

#include <string>
#include "Degree.h"

using namespace std;

class Student {
public:
    Student();

    Student(string sID, string fn, string ln, string ea, int a, int* daysInC);

    ~Student();

    string getFirstName();

    void setFirstName(string firstName);

    string getLastName();

    void setLastName(string lastName);

    string getEmailAddress();

    void setEmailAddress(string emailAddress);

    int getAge();

    void setAge(int age);

    string getStudentID();

    void setStudentID(string studentID);

    int *getDaysInCourse();

    void setDaysInCourse(int d0, int d1, int d2);

    virtual void print();

    void setDegree(string degree);

    virtual Degree getDegreeProgram();

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];


};


#endif //UNTITLED2_STUDENT_H
