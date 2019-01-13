#include "pch.h"
#include "student.h"


Student::Student()
{
}


Student::~Student()
{
}

string Student::get_studentID() const
//return the studentID string
{
   return studentID;
}

string Student::get_first_name() const
//return the student's first name string
{
   return first_name;
}

string Student::get_last_name() const
//return the student's last name string
{
   return last_name;
}

int Student::get_age() const
//return the student's age int
{
   return age;
}

int * Student::get_days_per_class() const
//create a new array with the days per class and return the pointer to it
{
   int* days = new int[3];
   for (int i = 0; i < 3; 1++)
   {
      days[i] = days_per_class[i]
    }
   return days;
}

Degree Student::get_degree_type() const
//return the student's degree type
{
   return degree_type;
}
