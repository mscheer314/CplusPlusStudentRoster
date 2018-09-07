//
// Created by Mark Scheer on 8/29/18.
//

#include <iostream>
#include "SecurityStudent.h"

SecurityStudent::SecurityStudent() {}

SecurityStudent::SecurityStudent(string sID, string fn, string ln, string ea, int a,
                                 int *daysInC, Degree deg) : Student(sID, fn, ln, ea, a, daysInC) {
    degree = deg;
}

Degree SecurityStudent::getDegreeProgram() {
    //Student::getDegreeProgram();   this work before
    return degree;
}

void SecurityStudent::print() {
    cout << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
         << "\t Email: " << getEmailAddress() << "daysInCourse: {";
    cout << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} \t";
    cout << "Security" << '\n';
}