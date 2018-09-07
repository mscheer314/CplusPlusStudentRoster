//
// Created by Mark Scheer on 8/29/18.
//

#include <iostream>
#include "NetworkStudent.h"

NetworkStudent::NetworkStudent() {}

NetworkStudent::NetworkStudent(string sID, string fn, string ln, string ea, int a,
                               int *daysInC, Degree deg) : Student(sID, fn, ln, ea, a, daysInC) {
    degree = deg;
}

Degree NetworkStudent::getDegreeProgram() {
    //Student::getDegreeProgram();     this worked up to this point
    return degree;
}

void NetworkStudent::print() {
    cout << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
         << "\t Email: " << getEmailAddress() << "daysInCourse: {";
    cout << getDaysInCourse()[0] << ", " << getDaysInCourse()[1] << ", " << getDaysInCourse()[2] << "} \t";
    cout << "Networking" << '\n';
}


