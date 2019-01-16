#pragma once
#include <string>
#include "student.h"

class SecurityStudent :
   public Student
{
public:
   SecurityStudent();
   SecurityStudent(string studentID, string firstName, string lastName,
      string emailAddress, int age,
      int daysInCourse1, int daysInCourse2, int daysInCourse3);

   ~SecurityStudent();

   virtual Degree getDegreeProgram() const;
   virtual void print() const;
};

