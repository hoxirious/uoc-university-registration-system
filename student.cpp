#include "student.h"

int Student::find_course(string c_name) {
    for(int i=0; i<course_list.size(); i++) {
        if(c_name == course_list.at(i).reg_course->get_cid()){
            return 1; 
        }
    }
    return 0; 
}

Student::Student() {}
Student::Student(string first, string last, string cell, string uid, Date birth) {}
Student::~Student() {}

void Student::set_Fname(string Fn) {}
void Student::set_Lname(string ln) {}
void Student::set_phone(string cell) {}
void Student::set_ID(string uid) {}
void Student::set_Date(Date bd) {}

string Student::get_Fname()
{
    return Fname;
}
string Student::get_Lname()
{
    return Lname;
}
string Student::get_phone()
{
    return phone;
}
string Student::get_ID()
{
    return ID;
}
Date Student::get_Date()
{
    return birthday;
}

void Student::add_course(Course *course_to_add, double g)
{
    if (find_course(course_to_add->get_cid()))
    {
        struct course_record new_course = {course_to_add, 0.0};
        course_list.push_back(new_course);
    }
    else
    {
        //TODOS printout already added
    }
}
void Student::drop_course(Course *course_to_drop) {}
void Student::modify_grade(Course *course_to_add, double grade_update) {}
string Student::student_info() {}