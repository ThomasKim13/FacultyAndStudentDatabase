/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * Faculty h file for the Database Project
 * H file for Faculty class
 * Helps to create a Faculty object*/

#ifndef PA5_FACULTYRECORD_H
#define PA5_FACULTYRECORD_H
#include<iostream>
#include<string>
#include "DblList.h"
using namespace std;

class Faculty {
    //public methods and variables
public:
    Faculty();
    ~Faculty();
    Faculty(int ID, string name, string level, string department, int* studentIDArr);
    void setID(int ID);
    void setName(string name);
    void setLevel(string level);
    void setDepartment(string department);
    int getID();
    string getName();
    string getLevel();
    string getDepartment();
    void addAdvisee(DblList<int> inList);
    void addStudent(int studentReference);
    void printInfo();
    void printStudentID(int ID);
    DblList<int> getFacultyStudentReferences();
    //overloaded constructor for ==
    bool operator ==(const Faculty& s1){
        return this->getID() == s1.m_ID;
    }
    //overloaded constructor for >
    bool operator >(const Faculty& s1){
        return this->getID() > s1.m_ID;
    }
    //overloaded constructor for <
    bool operator <(const Faculty& s1){
        return this->getID() < s1.m_ID;
    }
    bool operator !=(const Faculty& s1){
        return this->getID() != s1.m_ID;
    }
    //overloaded constructor for << in order to access and print the information of the Faculty
    friend ostream& operator<<(ostream& os, const Faculty &dt);
    int m_ID;
    DblList<int> studentAdvisees;
    void updateAdvisees(DblList<int> inList);


    string m_name;
    string m_level;
    string m_department;

};


#endif //PA5_FACULTYRECORD_H
