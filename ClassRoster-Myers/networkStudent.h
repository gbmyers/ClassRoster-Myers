#pragma once
#include <string>
#include "student.h"

class NetworkStudent :
   public Student
{
public:
   NetworkStudent();
   NetworkStudent(string studentID, string firstName, string lastName,
      string emailAddress, int age,
      int daysInCourse1, int daysInCourse2, int daysInCourse3);

   ~NetworkStudent();

   virtual Degree getDegreeProgram() const;
   virtual void print() const;
};

