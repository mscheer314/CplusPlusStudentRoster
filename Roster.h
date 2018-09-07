//
// Created by Mark Scheer on 8/29/18.
//

#ifndef UNTITLED2_ROSTER_H
#define UNTITLED2_ROSTER_H

#include "Student.h"
#include <array>

class Roster {
public:
    Roster();

    virtual ~Roster();

    Student getClassRosterArray();

    Student setClassRosterArray();

    void add(string sID, string fn, string ln, string ea, int a, int d0, int d1, int d2, Degree);

    void remove(string studentID);

    void printAll();

    void printDaysInCourse(string);

    void printInvalidEmails();

    void printByDegreeProgram(int degreeProgram);


    int addIndex = 0;

private:
    Student *classRosterArray[5];
};

#endif //UNTITLED2_ROSTER_H
