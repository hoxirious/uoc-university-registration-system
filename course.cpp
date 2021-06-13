#include "course.h"

int Course::find_student (string s_name) {}

Course::Course() {}
Course::Course(string id, Date s, Date e, int max) {}
Course::~Course() {}

string Course::get_cid() {} 

void Course::enroll(Student *S_obj) {}

void Course::withdraw(string uid) {}

void Course::update_grade (string uid, double g) {
    for (int i = 0; i < student_list.size(); ++i) {
        if (student_list[i].student->get_ID() == uid) {
            student_list[i].grade = g;
        } 
    }
}

string Course::course_info() {
    string si("Course ID: ");
    si.append(Cid);
    si.append("\nStart Date: ");
    si += start.get_month();
    si += '/';
    si += start.get_day();
    si += '/';
    si += start.get_year();
    si.append("\nEnd Date: ");
    si += end.get_month();
    si += '/';
    si += end.get_day();
    si += '/';
    si += end.get_year();
    si.append("\nCapacity: ");
    si += capacity;
    si.append("\nEnrolled: ");
    si += enrolled;
    si.append("\nList of Student:\n");
    si.append("     Student name     Grade");
    for (int i = 0; i < student_list.size(); ++i) {
        si.append("   ");
        si.append(student_list[i].student->get_Fname());
        si.append("");
        si.append(student_list[i].student->get_Lname());
        si.append("   ");
        si += student_list[i].grade;
        si.append("\n");
    }
}