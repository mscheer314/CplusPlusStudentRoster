//
// Created by Mark Scheer on 8/29/18.
//

#ifndef UNTITLED2_SECURITYSTUDENT_H
#define UNTITLED2_SECURITYSTUDENT_H


#include "Student.h"

class SecurityStudent : public Student {
public:
    SecurityStudent();

    SecurityStudent(string sID, string fn, string ln, string ea, int a, int *daysInC, Degree);

    Degree getDegreeProgram() override;

    void print() override;
private:
    Degree degree;
};


#endif //UNTITLED2_SECURITYSTUDENT_H
