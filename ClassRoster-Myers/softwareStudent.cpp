#include <iostream>
#include <iomanip>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent()
{
   Student::Student();
   this->setDegreeType(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string studentID, string firstName, string lastName, 
   string emailAddress, int age, 
   int daysInCourse1, int daysInCourse2, int daysInCourse3) : 
   Student(studentID, firstName, lastName, emailAddress, age,
   daysInCourse1, daysInCourse2, daysInCourse3)
{
   this->setDegreeType(SOFTWARE);
}

SoftwareStudent::~SoftwareStudent()
{
}

Degree SoftwareStudent::getDegreeProgram() const
{
   return SOFTWARE;
}

void SoftwareStudent::print() const
{
   Student::print();
   cout << left <<  setw(DEGREE_W) << "Software" << endl;
}
