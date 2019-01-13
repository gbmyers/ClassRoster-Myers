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
   // Student object constructor

	~Student();
   // student object destructor

   /*  Accessors  */
   string getStudentID() const;
   // returns the student's ID as a string

   string getFirstname() const;
   // returns the student's first name as a string 

   string getLastname() const;
   // returns the student's last name as a string

   string getEmailAddress() const;
   // returns the student's email address

   int getAge() const;
   // returns the student's age as an integer 

   int* getDaysPerClass() const;
   // returns a pointer to a new int[3] array containing the students days in courses

   virtual Degree getDegreeProgram() const;
   // returns the student's degree program as a Degree enum

   /*  Output methods  */
   virtual void print() const;
   // prints the student object to cout
   
   /*  Mutators  */
   void set_studentID(string new_studentID);
   // takes a string and sets it to the student's ID

   void set_first_name(string new_first_name);
   // takes a string and sets it to the student's first name

   void set_last_name(string new_last_name);
   // takes a string and sets it to the student's last name

   void set_email_address(string new_email_address);
   // takes a string and sets it to the student's email address

   void set_age(int new_age);
   // takes an int and sets it to the student's age

   void set_days_per_class(int* new_days_per_class);
   // takes a pointer to an int[3] array, and sets the student's days in classes

   void set_degree_type(Degree new_degree);
   // takes in a Degree enum and sets it to the student's degree program

private:
   string studentID;
   string firstname;
   string lastname;
   string emailAddress;
   int age;
   int daysPerClass[3];
   Degree degreeProgram;
};

