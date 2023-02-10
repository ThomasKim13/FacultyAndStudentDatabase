/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * Student h file for the Database Project
 * helps to create a student object*/

#ifndef PA5_STUDENTRECORD_H
#define PA5_STUDENTRECORD_H
#include <iostream>
#include <string>
using namespace std;
class Student {
    //public methods
public:
    Student();
    Student(int ID, string name, string grade, string major, double gpa, int advisorID);
    ~Student();
    void setID(int ID);
    void setName(string name);
    void setGrade(string grade);
    void setMajor(string major);
    void setGPA(double gpa);
    void setAdvisorID(int advisorID);
    int getID();
    void print();
    string getName();
    string getGrad();
    string getMajor();
    double getGPA();
    int getAdvisorID();
    //overloaded constructor for ==
    bool operator ==(const Student& s1){
        return this->getID() == s1.m_ID;
    }
    //overloaded constructor for >
    bool operator >(const Student& s1){
        return this->getID() > s1.m_ID;
    }
    //overloaded constructor for <
    bool operator <(const Student& s1){
        return this->getID() < s1.m_ID;
    }
    //overloaded constructor for !=
    bool operator !=(const Student& s1){
        return this->getID() != s1.m_ID;
    }
    bool operator >=(const Student* s1){
        return this->getID() >= s1->m_ID;
    }
    bool operator <=(const Student* s1){
        return this->getID() <= s1->m_ID;
    }
    //overloaded constructor that allows to print memory location information
    friend ostream& operator<<(ostream& os, const Student& dt);
    int m_ID;
    string m_name;
    string m_grade;
    string m_major;
    double m_gpa;
    int m_advisorID;
};


#endif //PA5_STUDENTRECORD_H
