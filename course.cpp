#include "course.h"

int Course::find_student(string id)
{
    for (int i = 0; i <(int)student_list.size(); i++)
    {
        if (id == student_list.at(i).student->get_ID())
        {
            return i;
        }
    }
    return -1;
}
Course::Course(): Cid(""), capacity(0), enrolled(0) {
}

Course::Course(string id, Date s, Date e, int max) {
    Cid = id;
    start = s;
    end = e;
    capacity = max;
}

Course::~Course() {}

string Course::get_cid() {
    return Cid;
}

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

void Course::withdraw(string uid)
{
    //TODOS if not found
    int pos = find_student(uid) + 1;
    student_list.erase(student_list.begin() + pos);
}

void Course::update_grade(string uid, double g)
{
    int j = find_student(uid);
    if (j == -1)
    {
        cout << "Error: Course not found" << endl;
        return;
    }
    student_list[j].grade = g;
}

string Course::course_info()
{
    string si("Course ID: ");
    si.append(Cid);
    si.append("\nStart Date: ");
    si.append(start.date_string());
    si.append("\nEnd Date: ");
    si.append(end.date_string());
    si.append("\nCapacity: ");
    si += capacity;
    si.append("\nEnrolled: ");
    si += enrolled;
    si.append("\nList of Student:\n");
    si.append("     Student name     Grade");
    for (int i = 0; i < (int)student_list.size(); ++i)
    {
        si.append("   ");
        si.append(student_list[i].student->get_Fname());
        si.append("");
        si.append(student_list[i].student->get_Lname());
        si.append("   ");
        si += student_list[i].grade;
        si.append("\n");
    }
    return si; 
}
