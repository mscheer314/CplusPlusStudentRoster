//
// Created by Mark Scheer on 8/28/18.
//

#include <iostream>
#include "Student.h"
#include "Degree.h"

Student::Student(string sID, string fn, string ln, string ea, int a, int *daysInC) {
    studentID = sID;
    firstName = fn;
    lastName = ln;
    emailAddress = ea;
    age = a;
    daysInCourse[0] = daysInC[0];
    daysInCourse[1] = daysInC[1];
    daysInCourse[2] = daysInC[2];
}

string Student::getFirstName() {
    return firstName;
}

void Student::setFirstName(string firstName) {
    Student::firstName = firstName;
}

string Student::getLastName() {
    return lastName;
}

void Student::setLastName(string lastName) {
    Student::lastName = lastName;
}

string Student::getEmailAddress() {
    return emailAddress;
}

void Student::setEmailAddress(string emailAddress) {
    Student::emailAddress = emailAddress;
}

int Student::getAge() {
    return age;
}

void Student::setAge(int age) {
    Student::age = age;
}

string Student::getStudentID() {
    return studentID;
}

void Student::setStudentID(string studentID) {
    Student::studentID = studentID;
}

int *Student::getDaysInCourse() {
    return daysInCourse;
}

void Student::setDaysInCourse(int d0, int d1, int d2) {
    Student::daysInCourse[0] = d0;
    Student::daysInCourse[1] = d1;
    Student::daysInCourse[2] = d2;
}

Student::Student() {}

Degree Student::getDegreeProgram() {
    return Degree::NETWORKING;
}

void Student::print() {}

Student::~Student() {}

