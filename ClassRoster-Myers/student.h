#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:
	Student(string studentID, string firstName, string lastName, 
      string emailAddress, int age, 
      int daysInCourse1, int daysInCourse2, int daysInCourse3);
	~Student();

   //accessors
   string getStudentID() const;
   string getFirstname() const;
   string getLastname() const;
   string getEmailAddress() const;
   int getAge() const;
   int* getDaysPerClass() const;
   virtual Degree getDegreeProgram() const;
   virtual void print() const;
   
   //mutators
   void set_studentID(string new_studentID);
   void set_first_name(string new_first_name);
   void set_last_name(string new_last_name);
   void set_email_address(string new_email_address);
   void set_age(int new_age);
   void set_days_per_class(int* new_days_per_class);
   void set_degree_type(Degree new_degree);

private:
   string studentID;
   string firstname;
   string lastname;
   string emailAddress;
   int age;
   int daysPerClass[3];
   Degree degreeProgram;
};

