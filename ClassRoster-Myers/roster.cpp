#include "roster.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

Roster::Roster()
{
}

Roster::~Roster()
// free up the memory used by the class roster
{
   //loop over the class roster and delete the student objects
   for (Student* student : classRosterArray)
   {
      delete student;
   }
   cout << "Roster object deleted." << endl;
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
   case NETWORK:
      newStudent = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
      break;
   case SOFTWARE:
      newStudent = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3);
      break;
   }
   
   //if we successfully created a new object, add it to the class roster
   if (newStudent != nullptr)
   {
      classRosterArray.push_back(newStudent);
   }
   else
   {  //if for some reason we can't create the student object, let the user know
      cout << "Unable to add student to roster with student ID " << studentID << endl;
   }

}

void Roster::add(string studentString)
//adds a student based on a single string formatted as "ID,First,Last,email,age,class1,class2,class3,program"
{
   vector<string> elements;   //hold each element as the string is separated by commas
   int start = 0;             //the start index of each element
   int length = 0;            //the length of each element
   string substring;          //extracted substring to add to the array

   //loop over each element in the array
   for (int end = 0; end < studentString.size(); end++)
   {
      if (studentString[end] == ',')
      {
         length = end - start;   //lenght of substring is the end - start
         substring = studentString.substr(start, length);   //grab the substring
         elements.push_back(substring);                     //push it to the array
         start = end + 1;     //update start: +1 to skip over the comma
      }
   }
   //the loop doesn't grab the last element, so we grab that below
   substring = studentString.substr(start);  //no need for end, grabs to the end of the string
   elements.push_back(substring);

   if (elements.size() == 9) {
      //more or less elements means we have an invalid string
      string studentID = elements[0];
      string firstName = elements[1];
      string lastName = elements[2];
      string email = elements[3];
      int age = stoi(elements[4]);
      int class1 = stoi(elements[5]);
      int class2 = stoi(elements[6]);
      int class3 = stoi(elements[7]);
      Degree program;
      if (elements[8] == "NETWORK") {
         program = NETWORK;
      }
      else if (elements[8] == "SECURITY")
      {
         program = SECURITY;
      }
      else if (elements[8] == "SOFTWARE")
      {
         program = SOFTWARE;
      }
      Roster::add(studentID, firstName, lastName, email, age, class1, class2, class3, program);
   }
   else
   {
      cout << "Unable to add student: " << studentString << endl;
   }
  
   


}

void Roster::remove(string studentID)
//removes the given student ID from the class roster if it exists
{
   //create a new, empty class roster
   vector<Student*> newRoster;

   //loop over the class roster looking for the given student ID
   for (Student* student : classRosterArray)
   {
      if (student->getStudentID() == studentID) {
         //if we find a match, delete the student object
         delete student;
         cout << "Student ID " << studentID << " was removed." << endl;
      }
      else {
         //if not a match, add the new, updated class roster 
         newRoster.push_back(student);
      }
   }

   if (newRoster.size() == classRosterArray.size())
   //if both arrays are the same size, we didn't find the student ID to delete 
   {
      cout << "Student ID " << studentID << " was not found." << endl;
   }
   else
   //if the arrays are not the same size, we must have deleted the given student ID
   {
      classRosterArray = newRoster;
   }
   
}

void Roster::printAll() const
{
   cout << "List of all students" << endl;

   //print header
   Roster::printHeader();

   //print each student
   for (Student* student : classRosterArray)
   {
      student->print();
   }
   cout << endl;
}

void Roster::printAverageDaysInCourse(string studentID) const
{
   //loop over the class roster looking for the given student ID
   for (Student* student : classRosterArray)
   {
      if (student->getStudentID() == studentID) 
      {
         cout << "Student ID: " << studentID << " Averge Days in Class: " << student->averageDaysPerClass() << endl;
      }
   }
}

void Roster::printInvalidEmails() const
{
   for (Student* student : classRosterArray)
   {
      if (not student->isEmailValid()) cout << "Invalid email: " << student->getEmailAddress() << endl;
   }
   cout << endl;
}

void Roster::printByDegreeProgram(Degree degreeProgram) const
//prints each student that matches the given degree program
{
   cout << "List of all students in the ";
   switch (degreeProgram) {
   case NETWORK: 
      cout << "networking program." << endl;
      break;
   case SECURITY:
      cout << "security program." << endl;
      break;
   case SOFTWARE:
      cout << "software program." << endl;
      break;
   }

   //print header 
   Roster::printHeader();

   //loop over the class roster, print each student that matches the given degree program
   for (Student* student : classRosterArray)
   {
      if (student->getDegreeProgram() == degreeProgram) student->print();
   }
   cout << endl;
}

vector<string> Roster::getListOfStudentIDs()
{
   vector<string> studentIDList;

   for (Student* student : classRosterArray)
   {
      studentIDList.push_back(student->getStudentID());
   }

   return studentIDList;
}

void Roster::printHeader()
{
   cout << left << setw(Student::NAME_W) << "Name"
      << setw(Student::ID_W) << "ID"
      << setw(Student::AGE_W) << "Age"
      << setw(Student::EMAIL_W) << "Email Address"
      << setw(Student::DAYPERCLASS_W) << "Avg"
      << setw(Student::DEGREE_W) << "Program" << endl;
}


int main() 
{
   const string studentData[] =
   { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
   "A5,Geoffrey,Myers,gmyer12@wgu.edu,39,5,10,25,SOFTWARE" };
    
   //print out header for output
   cout << "Class: Scripting and Programming - Applications – C867" << endl
      << "Language: C++11" << endl
      << "Student: Geoffrey Myers (SID: 000883177)" << endl << endl;

   Roster classRoster;

   for (string student : studentData)
   {
      classRoster.add(student);
   }
   
   classRoster.printAll();
   classRoster.printInvalidEmails();

   vector<string> studentIDs = classRoster.getListOfStudentIDs();
   for (string studentID : studentIDs)
   {
      classRoster.printAverageDaysInCourse(studentID);
   }
   cout << endl;


   classRoster.printByDegreeProgram(SOFTWARE);
   classRoster.remove("A3");
   classRoster.remove("A3");
   //expected: the above line should print a message saying such a student with this ID was not found.

   classRoster.printAll();

   //delete &classRoster;
}

