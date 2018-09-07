//
// Created by Mark Scheer on 8/29/18.
//

#ifndef UNTITLED2_NETWORKSTUDENT_H
#define UNTITLED2_NETWORKSTUDENT_H


#include "Student.h"

class NetworkStudent : public Student {
public:
    NetworkStudent();

    NetworkStudent(string sID, string fn, string ln, string ea, int a, int *daysInC, Degree);

    Degree getDegreeProgram() override;

    void print() override;

private:
    Degree degree;
};


#endif //UNTITLED2_NETWORKSTUDENT_H
