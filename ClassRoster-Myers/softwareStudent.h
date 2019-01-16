#pragma once
#include <string>
#include "student.h"

class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent();
   SoftwareStudent(string studentID, string firstName, string lastName,
      string emailAddress, int age,
      int daysInCourse1, int daysInCourse2, int daysInCourse3);

	~SoftwareStudent();

   virtual Degree getDegreeProgram() const;
   virtual void print() const;
};

