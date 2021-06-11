#include "student.h"

int Student::find_course(string c_name) {}

Student::Student() {}
Student::Student(string first, string last, string cell, string uid, Date birth) {}
Student::~Student() {}

void Student::set_Fname(string Fn) {}
void Student::set_Lname(string ln) {}
void Student::set_phone(string cell) {}
void Student::set_ID(string uid) {}
void Student::set_Date(Date bd) {}

string Student::get_Fname() {}
string Student::get_Lname() {}
string Student::get_phone() {}
string Student::get_ID() {}
Date Student::get_Date() {}

void Student::add_course(Course *course_to_add, double g) {}
void Student::drop_course(Course *course_to_drop) {}
void Student::modify_grade(Course *course_to_add, double grade_update) {}
string Student::student_info() {}