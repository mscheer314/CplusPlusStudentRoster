//
// Created by Mark Scheer on 8/29/18.
//

#ifndef UNTITLED2_SOFTWARESTUDENT_H
#define UNTITLED2_SOFTWARESTUDENT_H

#include "Student.h"

class SoftwareStudent : public Student {
public:
    SoftwareStudent();

    SoftwareStudent(string sID, string fn, string ln, string ea, int a, int *daysInC, Degree);

    Degree getDegreeProgram() override;

    void print() override;

private:
    Degree degree;
};

#endif //UNTITLED2_SOFTWARESTUDENT_H
