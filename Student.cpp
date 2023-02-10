/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * Student class for the Database Project
 * helps to create atrributes for a student object*/

#include "Student.h"
#include <iostream>
#include <string>
using namespace std;
//default constructor
Student::Student() {}
//overloaded constructor
Student::Student(int ID, std::string name, std::string grade, std::string major, double gpa, int advisorID) {
    m_ID = ID;
    m_name = name;
    m_grade = grade;
    m_major = major;
    m_gpa = gpa;
    m_advisorID = advisorID;
}
Student::~Student() {
}
//sets the name for the student
void Student::setName(string name) {
    m_name = name;
}
//sets the advisorID
void Student::setAdvisorID(int advisorID) {
    m_advisorID = advisorID;
}
//sets the student's gpa
void Student::setGPA(double gpa) {
    m_gpa = gpa;
}
//sets what grade level the student is
void Student::setGrade(std::string grade) {
    m_grade = grade;
}
//sets the ID for the student
void Student::setID(int ID) {
    m_ID = ID;
}
//sets the Major for the student
void Student::setMajor(std::string major) {
    m_major = major;
}
//gets the ID for the student
int Student::getID() {
    return m_ID;
}
//gets the advisorID for the student
int Student::getAdvisorID() {
    return m_advisorID;
}
//gets the name of the student
string Student::getName() {
    return m_name;
}
//gets the grade level for the student
string Student::getGrad() {
    return m_grade;
}
//gets the major for the student
string Student::getMajor() {
    return m_major;
}
//gets the GPA for the student
double Student::getGPA() {
    return m_gpa;
}




//print the information of the student based on the memory address.
ostream& operator <<(ostream& os, const Student& dt){
    os << "Student name: " << dt.m_name << endl;
    os << "Student ID: " << dt.m_ID << endl;
    os << "Student GPA: " << dt.m_gpa << endl;
    os << "Student grade level: " << dt.m_grade << endl;
    os << "Student major: " << dt.m_major << endl;
    os << "Student advisor ID: " << dt.m_advisorID << endl;
    return os;
}



