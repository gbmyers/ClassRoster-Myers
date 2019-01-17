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
   void add(string studentString);
   void remove(string studentID);

   void printAll() const;

   void printAverageDaysInCourse(string studentID) const;

   void printInvalidEmails() const;

   void printByDegreeProgram(Degree degreeProgram) const;

   vector<string> getListOfStudentIDs();

private:
   vector<Student*> classRosterArray;

   static void printHeader();
};

