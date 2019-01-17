#include <iostream>
#include <iomanip>
#include "NetworkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent()
{
   Student::Student();
   this->setDegreeType(NETWORK);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,
   string emailAddress, int age,
   int daysInCourse1, int daysInCourse2, int daysInCourse3) :
   Student(studentID, firstName, lastName, emailAddress, age,
      daysInCourse1, daysInCourse2, daysInCourse3)
{
   this->setDegreeType(NETWORK);
}

NetworkStudent::~NetworkStudent()
{
}

Degree NetworkStudent::getDegreeProgram() const
{
   return NETWORK;
}

void NetworkStudent::print() const
{
   Student::print();
   cout << left << setw(DEGREE_W) << "Networking" << endl;
}
