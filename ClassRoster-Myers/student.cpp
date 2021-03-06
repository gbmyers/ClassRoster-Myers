#include <iostream>
#include <iomanip>
#include "student.h"


Student::Student()
{
   this->studentID = "";
   this->firstname = "";
   this->lastname = "";
   this->emailAddress = "";
   this->age = 0;
   this->daysPerClass[0] = 0;
   this->daysPerClass[1] = 0;
   this->daysPerClass[2] = 0;
}

Student::Student(string studentID, string firstName, string lastName,
   string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
   int daysInCourse3)
{
   this->studentID = studentID;
   this->firstname = firstName;
   this->lastname = lastName;
   this->emailAddress = emailAddress;
   this->age = age;
   this->daysPerClass[0] = daysInCourse1;
   this->daysPerClass[1] = daysInCourse2;
   this->daysPerClass[2] = daysInCourse3;
}

Student::~Student()
{
   cout << "Student object " << studentID << " deleted." << endl;
}



string Student::getStudentID() const
//return the studentID string
{
   return studentID;
}

string Student::getFirstname() const
//return the student's first name string
{
   return firstname;
}

string Student::getLastname() const
//return the student's last name string
{
   return lastname;
}

string Student::getEmailAddress() const
{
   return emailAddress;
}

int Student::getAge() const
//return the student's age int
{
   return age;
}

int * Student::getDaysPerClass() const
//create a new array with the days per class and return the pointer to it
{
   int* days = new int[3];
   for (int i = 0; i < 3; i++)
   {
      days[i] = daysPerClass[i];
   }
   return days;
}

Degree Student::getDegreeProgram() const
{
   return degreeProgram;
}

void Student::setStudentID(string new_studentID)
//set student ID to the given string
{
   this->studentID = new_studentID;
}

void Student::setFirstname(string new_firstname)
// sets the students first name to the given string
{
   this->firstname = new_firstname;
}

void Student::setLastname(string new_lastname)
// sets the student's last name to the given string
{
   this->lastname = new_lastname;
}

void Student::setEmailAddress(string new_emailAddress)
// sets the student's email address to the given string
{
   this->emailAddress = new_emailAddress;
}

void Student::setAge(int new_age)
// sets the student's age to the given int
{
   this->age = new_age;
}

void Student::setDaysPerClass(int class1, int class2, int class3)
// sets the student's days per class to the given values
{
   this->daysPerClass[0] = class1;
   this->daysPerClass[1] = class2;
   this->daysPerClass[2] = class3;
}


void Student::setDegreeType(Degree new_degree)
// sets the student's degree type to the given Degree
{
   this->degreeProgram = new_degree;
}

void Student::print() const
{
   cout << left << setw(NAME_W) << this->getLastname() + ", " + this->getFirstname()
      << setw(ID_W) << this->getStudentID()
      << setw(AGE_W) << this->getAge()
      << setw(EMAIL_W) << this->getEmailAddress()
      << setw(DAYPERCLASS_W) << this->averageDaysPerClass();
}

float Student::averageDaysPerClass() const
{
   float total = 0;
   for (int i = 0; i < NUMBER_OF_CLASSES; i++)
   {
      total = total + daysPerClass[i];
   }
   return total / NUMBER_OF_CLASSES;
}

bool Student::isEmailValid() const
//email is considered valid if it has an '@' and a '.' and does not have a space
{
   //check for the lack of a space
   bool noSpace = emailAddress.find(" ") == string::npos;

   //check that we do find an '@' symbol
   bool hasAt = emailAddress.find("@") != string::npos;

   //check that we do have a '.'
   bool hasDot = emailAddress.find(".") != string::npos;

   //email is valid if all of the above are true
   bool validEmail = noSpace && hasAt && hasDot;

   return validEmail;
}