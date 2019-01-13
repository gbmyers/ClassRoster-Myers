#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student
{
public:
	Student();
	~Student();

   //accessors
   string get_studentID() const;
   string get_first_name() const;
   string get_last_name() const;
   string get_email_address() const;
   int get_age() const;
   int* get_days_per_class() const;
   Degree get_degree_type() const;

   //mutators
   void set_studentID(string new_studentID);
   void set_first_name(string new_first_name);
   void set_last_name(string new_last_name);
   void set_email_address(string new_email_address);
   void set_age(int new_age);
   void set_days_per_class(int* new_days_per_class);
   void get_degree_type(Degree new_degree);

private:
   string studentID;
   string first_name;
   string last_name;
   string email_address;
   int age;
   int days_per_class[3];
   Degree degree_type;
};

