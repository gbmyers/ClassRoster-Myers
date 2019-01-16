#include <iostream>
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
   cout << "Degree Program: Software" << endl;
}



int main()
{
   SoftwareStudent test1("AAA1", "Geoff", "Myres", "myers.geoffrey@gmail.com", 38, 10, 20, 30);
   test1.print();
   test1.setStudentID("BBB2");
   test1.setFirstname("Geoffrey");
   test1.setLastname("Myers");
   test1.setDaysPerClass(5, 10, 20);
   test1.setAge(39);
   test1.print();
}