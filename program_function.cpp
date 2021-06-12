
#include "program_functions.h"

// function to show main menue and prompt the user to select input option
int main_menu() {}

// cleans leftovers in the input buffer after any input operation
void buffer_cleaner() {}

// function to open file using file stream and extract course information in the file. the extraction is based on the file format provided in the supporting materials document
int load_coursefile(string filename, vector<Course> &clist)
{
    ifstream infile(filename);

    if (infile.fail())
    {
        cout << "Error opening file... quiting" << endl;
        exit(1);
    }
    string ID;
    int be_y, be_m, be_d, en_y, en_m, en_d, max_c;

    while (!infile.eof())
    {
        infile >> ID >> be_y >> be_m >> be_d >> en_y >> en_m >> en_d >> max_c;
        Course *search = find_course(ID, clist);
        if (search != NULL) {
            Date be(be_y, be_m, be_d);
            Date en(en_y, en_m, en_d);
            Course new_course(ID, be, en, max_c);
            clist.push_back(new_course);
        }
    }
    infile.close();
    return 0;
}

// function to open file using file stream and extract student information in the file.
int load_studentfile(string filename, vector<Student> &slist)
{

    ifstream infile(filename);

    if (infile.fail())
    {
        cout << "Error opening file... quiting" << endl;
        exit(1);
    }
    string fname, lname, cellp, ucid;
    int yr, m, d;

    while (!infile.eof())
    {
        infile >> fname >> lname >> cellp >> ucid >> yr >> m >> d;
        Student *search = find_student(ucid, slist);
        if (search != NULL)
        {
            Date dob(yr, m, d);
            Student new_student(fname, lname, cellp, ucid, dob);
            slist.push_back(new_student);
        }
    }
    infile.close();
    return 0;
}

// search function that finds a student object in the vector of students using the student id and return a pointer to the student object
Student *find_student(string id, vector<Student> &student_list)
{
    // Student *current = (Student*)malloc(sizeof(Student));
    Student *current = &student_list[0];
    for (int i = 0; i < student_list.size(); ++i)
    {
        if (current->get_ID() != id)
        {
            current = &student_list[i + 1];
        }
        else
        {
            return current;
        }
    }
    return NULL;
}

// search function that finds a course object in the vector of students using the course id and returns a pointer to the course object
Course *find_course(string cid, vector<Course> &course_list) {
    Course *current = &course_list[0];
    for (int i = 0; i < course_list.size(); ++i) {
        if (current->get_cid() != cid) {
            current = &course_list[i+1];
        }
        else {
            return current;
        }
    }
    return NULL;
}

// function to open enrollement file using a file stream and extracts student enrollment into courses information. must update the course objects to include the student in the student list, and update the student object to have the course in enrolled courses list
int enrollment_file(string filename, vector<Course> &clist, vector<Student> &slist) {}

// function that take course id and displays the string return of the course object
void show_course_details(string c, vector<Course> &clist) {
    Course *current = &clist[0];
    for (int i = 0; i <clist.size(); ++i) {
        if (current->get_cid() != c) {
            current = &clist[i+1];
        }
        else {
            cout << current->course_info();
            break;
        }
    }
    cout << "Error: Course not found" << endl;
}

// function that takes the student id and displays the string return of the student object info
void show_student_details(string s, vector<Student> &slist) {
    Student *current = &slist[0];
    for (int i = 0; i < slist.size(); ++i) {
        if(current->get_ID() != s) {
            current = &slist[i+1];
        }
        else {
            cout << current->student_info();
            break;
        }
    }
    cout << "Error: Student not Found" << endl;
}

// creates a new course by prompting the user to input required course information (not including enrolled students)
Course create_course() {}

// creates a new student object by prompting user to input required student information for the constructor
Student create_student() {}

// enrolls the student with sid into course with cid.
void enroll_to_course(string sid, string cid, vector<Student> &slist, vector<Course> &clist) {}

//10. update student grade that takes a student id, course id, and grade to update the student grade in a given course. note that parameters needed
// might be more than the three specified
void update_grade(string sid, string cid, int new_grade, vector<Student> &slist, vector<Course> &clist) {
    Student *current_s = &slist[0];
    Course *current_c = &clist[0];

    for (int i = 0; i < slist.size(); ++i) {
        if (current_s->get_ID() == sid ) {
            for (int j = 0; j < clist.size(); ++i) {
                if (current_c->get_cid() == cid) {
                    current_s->modify_grade(current_c, new_grade);
                    current_c->update_grade(sid, new_grade);
                    break;
                }
                else {
                    current_c = &clist[j+1];
                }
            }
            cout << "Error: Course not found" << endl;
            break; 
        }
        else {
            current_s = &slist[i+1];
        }
    }
    cout << "Error: Student not found" << endl;
}

//11. save changes will modify courses.txt, students.txt, and enroll.txt to reflect any changes that were made during the program run
//(i.e. new students added, course added, and new enrolments .... etc)
void modify_output(vector<Student> &slist, vector<Course> &clist) {

}