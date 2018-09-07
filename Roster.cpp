#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include "Student.h"
#include "SecurityStudent.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "Roster.h"
#include "Degree.h"

using namespace std;


Roster::Roster() {}

Roster::~Roster() {}

void Roster::add(string sID, string fn, string ln, string ea, int a, int d0, int d1, int d2, Degree degree) {
    int daysInC[] = {d0, d1, d2};
    if (degree == Degree::SOFTWARE) {
        classRosterArray[addIndex++] = new SoftwareStudent(sID, fn, ln, ea, a, daysInC, degree);
    }
    if (degree == Degree::SECURITY) {
        classRosterArray[addIndex++] = new SecurityStudent(sID, fn, ln, ea, a, daysInC, degree);
    }
    if (degree == Degree::NETWORKING) {
        classRosterArray[addIndex++] = new NetworkStudent(sID, fn, ln, ea, a, daysInC, degree);
    }
}

void Roster::remove(string studentID) {
    bool removed = false;
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != NULL) {
            if (studentID == classRosterArray[i]->getStudentID()) {
                classRosterArray[i] = nullptr;
                removed = true;
            }
        }
    }
    if (!removed) {
        cout << "This student was not found." << '\n';
    }
}

void Roster::printAll() {
    cout << "Printing the roster." << '\n';
    for (int i = 0; i < 5; i++) {
        classRosterArray[i]->print();
    }
    cout << '\n';
}

void Roster::printDaysInCourse(string studentID) {
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            int avg = 0;
            avg = (classRosterArray[i]->getDaysInCourse()[0] + classRosterArray[i]->getDaysInCourse()[1]
                   + classRosterArray[i]->getDaysInCourse()[2]) / 3;
            cout << "Average days in course for " << studentID << ": " << avg << '\n';
        }
    }
    cout << '\n';
}

void Roster::printInvalidEmails() {
    cout << "Printing invalid emails." << '\n';
    for (int i = 0; i < 5; i++) {
        bool hasAtSign = false;
        bool hasSpace = false;
        bool hasPeriod = false;
        string email = "";
        email = classRosterArray[i]->getEmailAddress();
        for (char &c : email) {
            if (c == '@') {
                hasAtSign = true;
            }
            if (c == '.') {
                hasPeriod = true;
            }
            if (c == ' ') {
                hasSpace = true;
            }
        }
        if (hasAtSign == false || hasPeriod == false || hasSpace == true) {
            cout << classRosterArray[i]->getEmailAddress() << '\n';
        }
    }
    cout << '\n';
}

void Roster::printByDegreeProgram(int degreeProgram) {
    cout << "Printing by degree program." << '\n';

    Degree testDeg = Degree::SOFTWARE;
    if (degreeProgram == 0) {
        testDeg = Degree::SECURITY;
    }
    if (degreeProgram == 1) {
        testDeg = Degree::NETWORKING;
    }
    if (degreeProgram == 2) {
        testDeg = Degree::SOFTWARE;
    }
    for (int i = 0; i < 5; i++) {
        if (testDeg == classRosterArray[i]->getDegreeProgram()) {
            classRosterArray[i]->print();
        }
    }
    cout << '\n';
}


int main() {
    const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                  "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                  "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                  "A5,Mark,Scheer,mscheer@wgu.edu,33,30,30,45,SOFTWARE"};

    Roster roster;
/*
    cout << "testing the string array prints" << endl;
    for (int i = 0; i < 5; i++) {                 //   TESTING THE STRING ARRAY PRINTS
        cout << studentData[i] << endl;
    }


    stringstream ss(studentData[0]);
    vector<string> result;

    while (ss.good()) {
        string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }

    cout << endl << "testing the string parsing" << endl;
    for (int i = 0; i < 9; i++) {                    // TESTING THE STRING PARSING
        cout << result.at(i) << "\t";
    }
    cout << endl << endl << endl;

    cout
            << "testing creating a Student object, setting attributes with setters and "
               "printing with getters. ex. setFirstName and getFirstname" << endl;
    Student stu1;                                   //  TESTING Student object creation and getter/setter.
    stu1.setStudentID("A1");
    cout << stu1.getStudentID() << "\t";

    stu1.setFirstName("John");
    cout << stu1.getFirstName() << "\t";

    stu1.setLastName("Smith");
    cout << stu1.getLastName() << "\t";

    stu1.setEmailAddress("John1989@gm ail.com");
    cout << stu1.getEmailAddress() << "\t";

    stu1.setAge(20);
    cout << stu1.getAge() << "\t";

    stu1.setDaysInCourse(30, 35, 40);
    for (int i = 0; i < 3; i++) {
        cout << *(stu1.getDaysInCourse() + i) << "\t";
    }

    stu1.setDegree(Degree::SECURITY);
    if (stu1.getDegreeProgram() == Degree::SECURITY) {
        cout << "SECURITY";
    }
    cout << endl << endl << endl;

    cout
            << "testing creating a SecurityStudent object and using setters and then getters to print. "
               "ex. setFirstName getFirstName"
            << endl;


    SecurityStudent secStu1;    // I changed this from SecurityStudent secStu1; to test it.
    // it doesn't work......



    // TESTING SecurityStudent object creation and functions

    secStu1.setStudentID("A1");
    cout << stu1.getStudentID() << "\t";

    secStu1.setFirstName("John");
    cout << stu1.getFirstName() << "\t";

    secStu1.setLastName("Smith");
    cout << stu1.getLastName() << "\t";

    secStu1.setEmailAddress("John1989@gm ail.com");
    cout << stu1.getEmailAddress() << "\t";

    secStu1.setAge(20);
    cout << stu1.getAge() << "\t";

    secStu1.setDaysInCourse(30, 35, 40);
    for (int i = 0; i < 3; i++) {
        cout << *(stu1.getDaysInCourse() + i) << "\t";
    }

    secStu1.setDegree(Degree::SECURITY);
    if (secStu1.getDegreeProgram() == Degree::SECURITY) {
        cout << "SECURITY";
    }

    cout << endl << endl << endl;
*/
    //SecurityStudent secStu1;
    //cout << "testing SecurityStudent::print()" << endl;
    //secStu1.print();                       // TESTING student.print()

    Degree degree1;
    for (int i = 0; i < 5; i++) {
        stringstream ss(studentData[i]);     // TESTING roster.add() and roster.print() with 1 element

        vector<string> result;

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }
        if (result[8] == "SECURITY") {
            degree1 = Degree::SECURITY;
        }
        if (result[8] == "SOFTWARE") {
            degree1 = Degree::SOFTWARE;
        }
        if (result[8] == "NETWORK") {
            degree1 = Degree::NETWORKING;
        }
        roster.add(result[0], result[1], result[2], result[3], stoi(result[4]), stoi(result[5]),
                   stoi(result[6]), stoi(result[7]), degree1);
    }


    roster.printAll();
    roster.printInvalidEmails();
    roster.printDaysInCourse("A1");
    roster.printByDegreeProgram(2);
    roster.remove("A3");
    roster.remove("A3");

    return 0;


}