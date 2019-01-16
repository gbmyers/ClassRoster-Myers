#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:
   Student();
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
   
   /*  Mutators  */
   void setStudentID(string new_studentID);
   // takes a string and sets it to the student's ID

   void setFirstname(string new_firstname);
   // takes a string and sets it to the student's first name

   void setLastname(string new_lastname);
   // takes a string and sets it to the student's last name

   void setEmailAddress(string new_emailAddress);
   // takes a string and sets it to the student's email address

   void setAge(int new_age);
   // takes an int and sets it to the student's age

   void setDaysPerClass(int class1, int class2, int class3);
   // sets the student's days in class to the given ints

   void setDegreeType(Degree new_degree);
   // takes in a Degree enum and sets it to the student's degree program

   /*  Other methods  */
   virtual void print() const;
   // prints the student object to cout

   float averageDaysPerClass() const;
   // returns the average number of days the student has been in class

   //column widths for printing
   static const int NAME_W = 30;
   static const int ID_W = 4;
   static const int EMAIL_W = 30;
   static const int AGE_W = 4;
   static const int DAYPERCLASS_W = 10;
   static const int DEGREE_W = 12;


private:
   static const int NUMBER_OF_CLASSES = 3;

   string studentID;
   string firstname;
   string lastname;
   string emailAddress;
   int age;
   int daysPerClass[NUMBER_OF_CLASSES];
   Degree degreeProgram;
};

