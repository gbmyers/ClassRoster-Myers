#include "roster.h"
#include <iostream>

using namespace std;

Roster::Roster()
{
}


Roster::~Roster()
// free up the memory used by the class roster
{
   //loop over the class roster and delete the student objects
   for (Student* student : classRoster)
   {
      delete student;
   }

   //found these very useful functions in the reference at cppreference.com
   classRoster.clear();          //remove all items from the class roster array
   classRoster.shrink_to_fit();  //this is probably superfluous since the object is about to be deleted
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree program)
//Add a new student to the class roster based on the type of student.
{
   //create a null pointer for the new student object
   Student* newStudent = nullptr;

   //Create the appropriate new student object based on the degree program
   switch (program) {
   case SECURITY:
      newStudent = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
      break;
   case NETWORKING:
      newStudent = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
      break;
   case SOFTWARE:
      newStudent = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
      break;
   }
   
   //if we successfully created a new object, add it to the class roster
   if (newStudent != nullptr)
   {
      classRoster.push_back(newStudent);
   }
   else
   {  //if for some reason we can't create the student object, let the user know
      cout << "Unable to add student to roster with student ID " << studentID << endl;
   }

}

void Roster::remove(string studentID)
//removes the given student ID from the class roster if it exists
{
   //create a new, empty class roster
   vector<Student*> newRoster;

   //loop over the class roster looking for the given student ID
   for (Student* student : classRoster)
   {
      if (student->getStudentID() == studentID) {
         //if we find a match, delete the student object
         delete student;
      }
      else {
         //if not a match, add the new, updated class roster 
         newRoster.push_back(student);
      }
   }

   if (newRoster.size() == classRoster.size())
   //if both arrays are the same size, we didn't find the student ID to delete 
   {
      cout << "Student ID " << studentID << " was not found." << endl;
   }
   else
   //if the arrays are not the same size, we must have deleted the given student ID
   {
      classRoster = newRoster;
   }
   
}

void Roster::printAll() const
{
   for (Student* student : classRoster)
   {
      student->print();
   }
}

void Roster::printByDegreeProgram(Degree degreeProgram) const
//prints each student that matches the given degree program
{
   //loop over the class roster, print each student that matches the given degree program
   for (Student* student : classRoster)
   {
      if (student->getDegreeProgram == degreeProgram) student->print();
   }
}


const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Geoffrey,Myers,gmyer12@wgu.edu,39,5,10,25,SOFTWARE" }


