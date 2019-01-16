#include "roster.h"
#include <iostream>
#include <iomanip>

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

   //found these very useful functions in the reference at cppreference.com
   classRosterArray.clear();          //remove all items from the class roster array
   classRosterArray.shrink_to_fit();  //this is probably superfluous since the object is about to be deleted
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

void Roster::printHeader()
{
   cout << left << setw(Student::NAME_W) << "Name"
      << setw(Student::ID_W) << "ID"
      << setw(Student::AGE_W) << "Age"
      << setw(Student::EMAIL_W) << "Email Address"
      << setw(Student::DAYPERCLASS_W) << "Avg"
      << setw(Student::DEGREE_W) << "Program" << endl;
}


const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Geoffrey,Myers,gmyer12@wgu.edu,39,5,10,25,SOFTWARE" };

int main() 
{

   Roster classRoster;

   classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, 30, 35, 40, SECURITY);
   classRoster.add("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORK);
   classRoster.add("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
   classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
   classRoster.add("A5", "Geoffrey", "Myers", "myers.geoffrey@gmail.com", 39, 10, 10, 10, SOFTWARE);

   /*TODO:
      * add each student to the class roster
    */


   classRoster.printAll();
   //classRoster.printInvalidEmails();
   //loop through classRosterArray and for each element:
   //   classRoster.printAverageDaysInCourse(/*current object's student id*/);

   classRoster.printByDegreeProgram(SOFTWARE);
   classRoster.remove("A3");
   classRoster.remove("A3");
   //expected: the above line should print a message saying such a student with this ID was not found.
}

