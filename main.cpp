/*
 * Thomas Kim
 * 2405924
 * chukim@chapman.edu
 * CPSC-350-01
 * PA5
 * main for the Database Project
 * handles the case statements
 * allows for the user to work with the database*/
#include <iostream>
#include "Faculty.h"
#include "Student.h"
#include "ScapegoatST.h"
#include "DblList.h"
#include <fstream>
using namespace std;


int main() {

    int decision;
    //two Scapegoat instances one that holds a student* and another that holds a Faculty*
    ScapegoatST<Student *> *StudentDatabase = new ScapegoatST<Student *>();
    ScapegoatST<Faculty *> *FacultyDatabase = new ScapegoatST<Faculty *>();








    while (decision != 11) {
        cout << "1.Print all students and their information (sorted by ascending id #)\n"
                "2.Print all faculty and their information (sorted by ascending id #)\n"
                "3.Find and display student information given the students id\n"
                "4.Find and display faculty information given the faculty id\n"
                "5.Add a new student\n" //works
                "6.Delete a student given the id\n"
                "7.Add a new faculty member\n"
                "8.Delete a faculty member given the id.\n"
                "9.Change a student’s advisor given the student id and the new faculty id.\n"
                "10.Remove an advisee from a faculty member given the ids\n"
                "11.Exit" << endl;
        cout << "Option: ";
        cin >> decision;
        cout << "You chose option " << decision << endl;
        //case statement that checks for input
        switch (decision) {

            //if user wants to print students it prints the student tree in ascending order
            case 1: {
                if (StudentDatabase->getSize() == 0) {
                    cout << "No students were found" << endl;
                }
                cout << "Student IDS: ";
                StudentDatabase->printTreeInOrder();

                continue;
            }
            //if user wants to print faculty information it prints the faculty tree in ascending order
            case 2: {
                if (FacultyDatabase->getSize() == 0) {
                    cout << "No students were found" << endl;
                }
                FacultyDatabase->printTreeInOrder();
                continue;
            }
            //given the student's ID number the student's information is then printed
            case 3: {

                int studentID;
                cout << "Give student ID: ";
                Student *temp = new Student();
                cin >> studentID;
                temp->setID(studentID);
                if (StudentDatabase->contains(temp)) {
                    Student *found = StudentDatabase->findPerson(temp);
                        cout << *found << endl;

                } else {
                    cout << "Student ID does not exist" << endl;
                }
                continue;

            }
            //given the Faculty's ID number the information of that Faculty is printed
            case 4: {
                int facultyID;
                cout << "Give Faculty ID: ";
                Faculty *temp = new Faculty();
                cin >> facultyID;
                temp->setID(facultyID);
                if (FacultyDatabase->contains(temp)) {
                    Faculty *found = FacultyDatabase->findPerson(temp);
                    cout << *found;

//

                } else {
                    cout << "Faculty ID does not exist" << endl;
                }
                continue;

            }
            //this case helps to create a student object
                //at the end inserts the Student object into the StudentDatabase
            case 5: {
                string name;
                int ID;
                string major;
                string grade;
                double gpa;
                int advisorID;
                Student *s1 = new Student();

                cout << "NAME: ";
                cin >> name;
                cout << "ID: ";
                cin >> ID;
                cout << "Major: ";
                cin >> major;
                cout << "GPA: ";
                cin >> gpa;
                cout << "Advisor ID: ";
                cin >> advisorID;
                cout << "Grade level: ";
                cin >> grade;

                s1->setName(name);
                s1->setID(ID);
                s1->setMajor(major);
                s1->setGrade(grade);
                s1->setGPA(gpa);
                s1->setAdvisorID(advisorID);
                Faculty *temp = new Faculty();
                temp->setID(advisorID);
                if (FacultyDatabase->contains(temp)) {
                    Faculty *x = FacultyDatabase->findPerson(temp);
                    x->addStudent(ID);
                } else {
                    cout << "Faculty does not exist" << endl;
                }
                StudentDatabase->insert(s1);
                continue;
            }
            //this case removes a student from the StudentDatabase

            case 6: {
                int studentID;
                cout << "Give student ID: ";
                Student *temp = new Student();
                cin >> studentID;
                temp->setID(studentID);
                if (StudentDatabase->contains(temp)) {
                    StudentDatabase->remove(temp);

                } else {
                    cout << "Student ID does not exist" << endl;
                }
                continue;

            }
            //creates a Faculty object
            //at the end inserts the Faculty object into the FacultyDatabase
            case 7: {
                string name;
                int ID;
                string department;
                string level;
                Faculty *f1 = new Faculty;
                cout << "NAME: ";
                cin >> name;
                cout << "ID: ";
                cin >> ID;
                cout << "Department: ";
                cin >> department;
                cout << "level: ";
                cin >> level;
                f1->setName(name);
                f1->setID(ID);
                f1->setDepartment(department);
                f1->setLevel(level);
                FacultyDatabase->insert(f1);
                continue;
            }
            //given a Faculty's ID number the faculty is deleted
            //if the Faculty has advisees another faculty is chosen to take the students
            case 8: {
                int facID;
                cout << "Give faculty ID: ";
                Faculty *temp = new Faculty();
                cin >> facID;
                temp->setID(facID);
                if (FacultyDatabase->contains(temp)) {

                    int newFacID;
                    Faculty* Fac = FacultyDatabase->findPerson(temp);
                    DblList<int> oldFacStudent = Fac->getFacultyStudentReferences();
                    FacultyDatabase->remove(temp);
                    if(oldFacStudent.size() > 0){
                        cout << "Must choose a new faculty" << endl;
                        int newFacID;
                        cout << "New faculty ID: " << endl;
                        cin >> newFacID;
                        Faculty* tempNew = new Faculty();
                        tempNew->setID(newFacID);
                        if(FacultyDatabase->contains(tempNew)){
                            Faculty* New = FacultyDatabase->findPerson(tempNew);
                            New->addAdvisee(oldFacStudent);
                        }
                        else{
                            cout << "No faculty was found!" << endl;
                        }
                    }






                }
                else {
                    cout << "Faculty ID does not exist" << endl;
                }

                    continue;



            }


            //given a student and faculty id the student is placed into the new Faculty's advisee roster
            case 9: {
                int studentID;
                int newFacID;
                cout << "Student ID: ";
                cin >> studentID;
                cout << "New Faculty ID: ";
                cin >> newFacID;

                Student* tempoldStudent = new Student();
                Faculty* tempNewFac = new Faculty();
                tempNewFac->setID(newFacID);
                tempoldStudent->setID(studentID);

                Student* oldStudent = StudentDatabase->findPerson(tempoldStudent);





                Faculty* newFaculuty = FacultyDatabase->findPerson(tempNewFac);



                newFaculuty->addStudent(studentID);
                int oldFac = oldStudent->getAdvisorID();
                Faculty* tempOldFac = new Faculty();
                tempOldFac->setID(oldFac);

                Faculty* oldFacMem = FacultyDatabase->findPerson(tempOldFac);


                DblList<int> oldStudents = oldFacMem->getFacultyStudentReferences();

                DblList<int> updatedStudents;
                while(!oldStudents.isEmpty()){

                    if(oldStudents.peekFront() != studentID){
                        updatedStudents.addFront(oldStudents.peekFront());
                        oldStudents.removeFront();

                    }
                    else{
                        oldStudents.removeFront();

                    }
                }
                newFaculuty->addAdvisee(updatedStudents);
                oldStudent->setAdvisorID(newFacID);
                oldFacMem->updateAdvisees(updatedStudents);




                continue;
            }
            //removes an advisee from a faculty member given the id
            case 10: {
                int StuID;
                cout << "Student ID: ";
                cin >> StuID;
                int FacID;
                Student* tempStudent = new Student();
                Faculty* tempFac = new Faculty();
                tempStudent->setID(StuID);
                if(StudentDatabase->contains(tempStudent)) {
                    Student *Stu = StudentDatabase->findPerson(tempStudent);
                    FacID = Stu->getAdvisorID();
                    tempFac->setID(FacID);

                    Faculty *Fac = FacultyDatabase->findPerson(tempFac);

                    DblList<int> oldStudents = Fac->getFacultyStudentReferences();
                    DblList<int> updatedStudents;
                    while (!oldStudents.isEmpty()) {

                        if (oldStudents.peekFront() != StuID) {
                            updatedStudents.addFront(oldStudents.peekFront());
                            oldStudents.removeFront();

                        } else {
                            oldStudents.removeFront();

                        }
                    }
                    Fac->updateAdvisees(updatedStudents);

                }
                else{
                    cout << "Student does not exist" << endl;
                }
                continue;







            }
            //when 11 is chosen the database breaks
            //the studentDatabase information and FacultyDatabase information is printed to "RunLog.txt" file
            case 11: {
                cout << "Ending program" << endl;
                ofstream outFile("RunLog.txt");
                StudentDatabase->logTree(outFile);
                FacultyDatabase->logTree(outFile);


                break;
            }
            //default case in case that a user chooses a number not between 1-11
            default:{
                cout << "Choice is invalid! Choose a number between 1-11" << endl;
                continue;
            }

        }


        return 0;
    }
}

