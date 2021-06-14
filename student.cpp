#include "student.h"

int Student::find_course(string c_name)
{
    for (int i = 0; i < (int)course_list.size(); i++)
    {
        if (c_name == course_list.at(i).reg_course->get_cid())
        {
            return i;
        }
    }
    return -1;
}

Student::Student() : ID(""), Fname(""), Lname(""), phone("")
{
    birthday.set_day(0);
    birthday.set_month(0);
    birthday.set_year(0);
}
Student::Student(string first, string last, string cell, string uid, Date birth)
{
    set_Fname(first);
    set_Lname(last);
    set_phone(cell);
    set_ID(uid);
    set_Date(birth);
}
Student::~Student() {
}

void Student::set_Fname(string Fn)
{
    Fname = Fn;
}
void Student::set_Lname(string ln)
{
    Lname = ln;
}
void Student::set_phone(string cell)
{
    phone = cell;
}
void Student::set_ID(string uid)
{
    ID = uid;
}
void Student::set_Date(Date bd)
{
    birthday.set_day(bd.get_day());
    birthday.set_month(bd.get_month());
    birthday.set_year(bd.get_year());
}

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

vector<course_record> Student::get_course_list()
{
    return course_list;
}

void Student::add_course(Course *course_to_add, double g)
{
    if (find_course(course_to_add->get_cid()) == -1)
    {
        struct course_record new_course = {course_to_add, 0.0};
        course_list.push_back(new_course);
        cout << "Success: Student " << get_Lname() << " has added course: " << course_to_add->get_cid()<<endl;
    }
    else
    {
        cout << "Failed: Student " << get_Lname() << " has already added course: " << course_to_add->get_cid()<<endl;
    }
}
void Student::drop_course(Course *course_to_drop)
{
    //TODOS if not found
    int pos = find_course(course_to_drop->get_cid());
    course_list.erase(course_list.begin() + pos);
    cout << "Success: Course " << course_to_drop->get_cid()<< "has been dropped"<<endl;
}

void Student::modify_grade(Course *course_to_add, double grade_update)
{
    int j = find_course(course_to_add->get_cid());
    if (j == -1)
    {
        cout << "Error: Course not found" << endl;
        return;
    }
    course_list[j].grade = grade_update;
}

string Student::student_info()
{
    string si("Student ID: ");
    si.append(ID);
    si.append("\nFirst Name: ");
    si.append(Fname);
    si.append(" Last name: ");
    si.append(Lname);
    si.append("\nConstant number: ");
    si.append(phone);
    si.append("\nDate of Birth: ");
    si.append(birthday.date_string());
    si.append("\nCourse list:\n");
    si.append("     Course Name     Grade\n");
    for (int i = 0; i < (int)course_list.size(); ++i)
    {
        si.append("     ");
        si.append(course_list[i].reg_course->get_cid());
        si.append("     ");
        si += to_string(course_list[i].grade);
        si.append("\n");
    }
    return si;
}
