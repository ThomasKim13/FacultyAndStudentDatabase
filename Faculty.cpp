/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * Faculty for the Database Project
 * creates and adds attributes of a Faculty member*/

#include "Faculty.h"
#include "DblList.h"
#include <iostream>
#include <string>
using namespace std;
//default constructor
Faculty::Faculty() {}
//deconstructor
Faculty::~Faculty() {}
//gets the ID for the faculty
void Faculty::setID(int ID) {
    m_ID = ID;
}
//sets the name for the faculty
void Faculty::setName(std::string name) {
    m_name = name;
}
//sets the department for the faculty
void Faculty::setDepartment(std::string department) {
    m_department = department;
}
//sets the professor level for the faculty
void Faculty::setLevel(std::string level) {
    m_level = level;
}
//gets the ID for the faculty
int Faculty::getID() {
    return m_ID;
}
//gets the name for the faculty
string Faculty::getName() {
    return m_department;
}
string Faculty::getDepartment() {
    return m_department;
}
string Faculty::getLevel() {
    return m_level;
}
//overloaded operator that helps to print the information for the faculty
ostream& operator<<(ostream& os, const Faculty& dt){
    os << "Faculty name: " << dt.m_name << endl;
    os << "Faculty ID: " << dt.m_ID << endl;
    os << "Faculty department: " << dt.m_department << endl;
    os << "Faculty level: " << dt.m_level << endl;
    os << "Faculty advisee IDs: " << endl;
    DblList<int> students = dt.studentAdvisees;
    students.out(os);
    os << endl;
    return os;

}
//adds students to a DblList
//If there is already students this method just adds to the DblList
void Faculty::addAdvisee(DblList<int> inList) {
    while(!inList.isEmpty()){
        studentAdvisees.addFront(inList.peekFront());
        inList.removeFront();
    }
}
//method that adds a student's id to the front the DblList
void Faculty::addStudent(int ID) {
    studentAdvisees.addFront(ID);
}
//returns the DblList holding student ID
DblList<int> Faculty::getFacultyStudentReferences() {
    return studentAdvisees;
}
//makes the current studentAdvisee DblList equal to the method that is being passed through
//helps when deleting and updating faculty
void Faculty::updateAdvisees(DblList<int> inList){
    studentAdvisees = inList;
}

