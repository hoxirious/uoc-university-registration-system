#include "course.h"

int Course::find_student(string id) {
    for(int i=0; i<student_list.size(); i++) {
        if(id == student_list.at(i).student->get_ID()){
            return 1; 
        }
    }
    return 0; 
}

Course::Course() {}

Course::Course(string id, Date s, Date e, int max) {}

string Course::get_cid() {}

void Course::enroll(Student *S_obj)
{
    if (find_student(S_obj->get_ID()))
    {
        struct student_record new_record = {S_obj, 0.0};
        student_list.push_back(new_record);
    }
    else
    {
        //TODOS printout it's been added
    }
}

void Course::withdraw(string uid) {}

void Course::update_grade(string uid, double g) {}

string Course::course_info() {}