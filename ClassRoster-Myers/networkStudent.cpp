#include <iostream>
#include "NetworkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent()
{
   Student::Student();
   this->setDegreeType(NETWORKING);
}

NetworkStudent::NetworkStudent(string studentID, string firstName, string lastName,
   string emailAddress, int age,
   int daysInCourse1, int daysInCourse2, int daysInCourse3) :
   Student(studentID, firstName, lastName, emailAddress, age,
      daysInCourse1, daysInCourse2, daysInCourse3)
{
   this->setDegreeType(NETWORKING);
}

NetworkStudent::~NetworkStudent()
{
}

Degree NetworkStudent::getDegreeProgram() const
{
   return NETWORKING;
}

void NetworkStudent::print() const
{
   Student::print();
   cout << "Degree Program: Networking" << endl;
}


/*
int main()
{
   NetworkStudent test1("AAA1", "Geoff", "Myres", "myers.geoffrey@gmail.com", 38, 10, 20, 30);
   test1.print();
   test1.setStudentID("BBB2");
   test1.setFirstname("Geoffrey");
   test1.setLastname("Myers");
   test1.setDaysPerClass(5, 10, 20);
   test1.setAge(39);
   test1.print();
}
*/