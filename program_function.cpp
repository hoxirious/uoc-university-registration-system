#include "program_functions.h"
#include <iostream>
#include <fstream>
#include <string>

int main_menu() {}

void buffer_cleaner() {}
int load_coursefile(string filename, vector<Course> &clist) {}
int load_studentfile(string filename, vector<Student> &slist) {}
Student *find_student(string id, vector<Student> &student_list) {}
Course *find_course(string cid, vector<Course> &course_list) {}

int enrollment_file(string filename, vector<Course> &clist, vector<Student> &slist)
{
    ifstream in_stream("enroll.txt");
    if (in_stream.fail())
    {
        cout << "Error loading file: " << filename << endl;
        in_stream.clear();
        exit(1);
    }
    while (!in_stream.eof())
    {
        vector<string> line;
        string ch;
        while (getline(in_stream, ch))
        {
            if (ch.at(ch.length() - 1) == ' ')
            {
                ch.erase(ch.length() - 1);
                line.push_back(ch);
                ch.clear();
            }
        }
        Student *found_student = find_student(line.at(0), slist);

        for (int i = 2; i < (2 + stoi(line.at(1))); i++)
        {
            Course *found_course = find_course(line.at(i), clist);
            found_course->enroll(found_student);
            //TODOS g=0 here, maybe fix later
            found_student->add_course(found_course, 0);
        }
    }
    in_stream.close();
}

void show_course_details(string c, vector<Course> &clist) {}
void show_student_details(string s, vector<Student> &slist) {}

Course create_course()
{
    string course_id;
    int syear, smonth, sdate;
    int eyear, emonth, edate;
    int capacity;
    cout << "Course ID: ";
    cin >> course_id;
    cin >> syear >> smonth >> sdate;
    cout << "Enter end date (yyyy mm dd): ";
    cin >> eyear >> emonth >> edate;
    cout << "Enter Course Capacity:  ";
    cin >> capacity;

    Course new_course(course_id, Date(syear, smonth, sdate), Date(eyear, emonth, edate), capacity);
}
Student create_student()
{
    string first, last, cell, uid;
    int year, month, date;
    cout << "Enter your first name: ";
    cin >> first;
    cout << "Enter your last name: ";
    cin >> last;
    cout << "Enter your phone number: ";
    cin >> cell;
    cout << "Enter your UCID: ";
    cin >> uid;
    cout << "Enter birthdate (yyyy mm dd): ";
    cin >> year >> month >> date;
    Student new_student(first, last, cell, uid, Date(year, month, date));
}

void enroll_to_course(string sid, string cid, vector<Student> &slist, vector<Course> &clist) {

}

void withdraw_from_course(string sid, string cid, vector<Student> &slist, vector<Course> &clist) {}

void update_grade(string sid, string cid, vector<Student> &slist, vector<Course> &clist) {}

// void modify_output(vector<Student> &slist, vector<Course> &clist) {}