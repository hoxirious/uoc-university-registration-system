#include "course.h"

int Course::find_student(string id)
{
    for (int i = 0; i < (int)student_list.size(); i++)
    {
        if (id == student_list.at(i).student->get_ID())
        {
            return i;
        }
    }
    return -1;
}
Course::Course() : Cid(""), capacity(0), enrolled(0)
{
}

Course::Course(string id, Date s, Date e, int max)
{
    Cid = id;
    start = s;
    end = e;
    capacity = max;
}

Course::~Course() {
    delete &student_list; 
}

string Course::get_cid()
{
    return Cid;
}

void Course::enroll(Student *S_obj)
{
    if (find_student(S_obj->get_ID()) == -1)
    {
        struct student_record new_record = {S_obj, 0.0};
        student_list.push_back(new_record);
        enrolled = (int)student_list.size();
        cout << "Success: Course " << get_cid() << " has successfully enrolled student " << S_obj->get_Lname() << endl;
    }
    else
    {
        cout << "Failed: Course " << get_cid() << " has already enrolled student " << S_obj->get_Lname() << endl;
    }
}

void Course::withdraw(string uid)
{
    //TODOS if not found
    int pos = find_student(uid);
    student_list.erase(student_list.begin() + pos);
    enrolled = (int)student_list.size();
    cout << "Success: Course " << get_cid() << "has successfully withdrawn student " << uid << endl;
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
    si += to_string(capacity);
    si.append("\nEnrolled: ");
    si += to_string(enrolled);
    si.append("\nList of Student:\n");
    si.append("Student name       Grade");
    si.append("\n");
    for (int i = 0; i < (int)student_list.size(); ++i)
    {
        si.append(student_list[i].student->get_Fname());
        si.append(" ");
        si.append(student_list[i].student->get_Lname());
        si.append("     ");
        si += to_string(student_list[i].grade);
        si.append("\n");
    }
    return si;
}
