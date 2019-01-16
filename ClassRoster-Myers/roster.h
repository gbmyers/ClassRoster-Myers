#pragma once
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <vector>


class Roster
{
public:
	Roster();
	~Roster();

   void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program);
   void remove(string studentID);

   void printAll();

   void printDaysInCourse(string studentID);

   void printInvalidEmails();

   void printByDegreeProgram(int degreeProgram);

private:
   vector<Student*> classRoster;
};

