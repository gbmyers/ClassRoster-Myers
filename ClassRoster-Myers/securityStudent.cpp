#include <iostream>
#include <iomanip>
#include "SecurityStudent.h"

using namespace std;

SecurityStudent::SecurityStudent()
{
   Student::Student();
   this->setDegreeType(SECURITY);
}

SecurityStudent::SecurityStudent(string studentID, string firstName, string lastName,
   string emailAddress, int age,
   int daysInCourse1, int daysInCourse2, int daysInCourse3) :
   Student(studentID, firstName, lastName, emailAddress, age,
      daysInCourse1, daysInCourse2, daysInCourse3)
{
   this->setDegreeType(SECURITY);
}

SecurityStudent::~SecurityStudent()
{
}

Degree SecurityStudent::getDegreeProgram() const
{
   return SECURITY;
}

void SecurityStudent::print() const
{
   Student::print();
   cout << left << setw(DEGREE_W) << "Security" << endl;
}


/*
int main()
{
   SecurityStudent test1("AAA1", "Geoff", "Myres", "myers.geoffrey@gmail.com", 38, 10, 20, 30);
   test1.print();
   test1.setStudentID("BBB2");
   test1.setFirstname("Geoffrey");
   test1.setLastname("Myers");
   test1.setDaysPerClass(5, 10, 20);
   test1.setAge(39);
   test1.print();
}
*/
