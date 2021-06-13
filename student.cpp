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
void Student::set_course_list(vector <course_record>) {}

string Student::get_Fname() {}
string Student::get_Lname() {}
string Student::get_phone() {}
string Student::get_ID() {}
Date Student::get_Date() {}
vector <course_record> Student::get_course_list() {}

void Student::add_course(Course *course_to_add, double g){}

void Student::drop_course(Course *course_to_drop){}

void Student::modify_grade(Course *course_to_add, double grade_update){
    for (int i = 0; i < course_list.size(); ++i) {
        if (course_list[i].reg_course->get_cid() == course_to_add->get_cid()) {
            course_list[i].grade = grade_update;
        }
    }
}

string Student::student_info(){
    string si("Student ID: ");
    si.append(ID);
    si.append("\nFirst Name: ");
    si.append(Fname);
    si.append(" Last name: ");
    si.append(Lname);
    si.append("\nConstant number: ");
    si.append(phone);
    si.append("\nDate of Birth: ");
    si += birthday.get_month();
    si += '/';
    si += birthday.get_day();
    si += '/';
    si += birthday.get_year();
    si.append("\nCourse list:\n");
    si.append("     Course Name     Grade\n");
    for (int i = 0; i < course_list.size(); ++i) {
        si.append("     ");
        si.append(course_list[i].reg_course->get_cid());
        si.append("     ");
        si += course_list[i].grade;
        si.append("\n");
    }
}