
#include "program_functions.h"
using namespace std;

// function to show main menue and prompt the user to select input option
int main_menu()
{
    //System(“clear”);
    int input;
    cout << "Main menu" << endl
         << "Please select one of the following operations\n"
         << setw(5) << "1. Load students list file" << endl
         << setw(5) << "2. Load courses file" << endl
         << setw(5) << "3. Enroll from file" << endl
         << setw(5) << "4. Show course details" << endl
         << setw(5) << "5. Show student details" << endl
         << setw(5) << "6. Create course" << endl
         << setw(5) << "7. Add student to database" << endl
         << setw(5) << "8. Enroll student to course" << endl
         << setw(5) << "9. Withdraw student from course" << endl
         << setw(5) << "10. Update student grade" << endl
         << setw(5) << "11. Save changes" << endl
         << setw(5) << "12. Exit" << endl;
    cin >> input;
    buffer_cleaner();
    return input;
}

void pressEnter()
{
    cout << "\n<<< Press Enter to Continue>>>\n";
    cin.get();
    system("clear");
}

// cleans leftovers in the input buffer after any input operation
void buffer_cleaner()
{
    int ch;
    do
    {
        ch = cin.get();
    } while (ch != '\n' && ch != EOF);
    if (ch == EOF)
    {
        cout << "End of the input was detected... Quiting" << endl;
        exit(1);
    }
}

// function to open file using file stream and extract course information in the file. the extraction is based on the file format provided in the supporting materials document
int load_coursefile(string filename, vector<Course> &clist)
{
    ifstream infile(filename);

    if (infile.fail())
    {
        cout << "Error opening file: " << filename << endl;
        return -1;
    }
    string ID;
    int be_y, be_m, be_d, en_y, en_m, en_d, max_c;
    int count = 0;

    while (!infile.eof())
    {
        infile >> ID >> be_y >> be_m >> be_d >> en_y >> en_m >> en_d >> max_c;
        Course *search = find_course(ID, clist);
        if (search == NULL)
        {
            Date be(be_y, be_m, be_d);
            Date en(en_y, en_m, en_d);
            Course new_course(ID, be, en, max_c);
            clist.push_back(new_course);
            count++;
        }
    }
    infile.close();
    return count;
}

// function to open file using file stream and extract student information in the file.
int load_studentfile(string filename, vector<Student> &slist)
{

    ifstream infile(filename);

    if (infile.fail())
    {
        cout << "Error opening file: " << filename << endl;
        return -1;
    }
    string fname, lname, cellp, ucid;
    int yr, m, d;
    int count = 0;

    while (!infile.eof())
    {
        infile >> ucid >> fname >> lname >> cellp >> yr >> m >> d;
        Student *search = find_student(ucid, slist);
        if (search == NULL)
        {
            Date dob(yr, m, d);
            Student new_student(fname, lname, cellp, ucid, dob);
            slist.push_back(new_student);
            count++;
        }
    }
    infile.close();
    return count;
}

// search function that finds a student object in the vector of students using the student id and return a pointer to the student object
Student *find_student(string id, vector<Student> &student_list)
{
    // Student *current = (Student*)malloc(sizeof(Student));
    Student *current = &student_list[0];
    for (int i = 0; i < (int)student_list.size(); ++i)
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
Course *find_course(string cid, vector<Course> &course_list)
{
    Course *current = &course_list[0];
    for (int i = 0; i < (int)course_list.size(); ++i)
    {
        if (current->get_cid() != cid)
        {
            current = &course_list[i + 1];
        }
        else
        {
            return current;
        }
    }
    return NULL;
}

// function to open enrollement file using a file stream and extracts student enrollment into courses information. must update the course objects to include the student in the student list, and update the student object to have the course in enrolled courses list
int enrollment_file(string filename, vector<Course> &clist, vector<Student> &slist)
{
    ifstream in_stream(filename);
    int counter = 0;
    if (in_stream.fail())
    {
        cout << "Error loading file: " << filename << endl;
        in_stream.clear();
        return -1;
    }

    while (!in_stream.eof())
    {
        string id, course;
        int num_courses;
        in_stream >> id >> num_courses;
        Student *found_student = find_student(id, slist);

        if (found_student != NULL)
        {
            for (int i = 0; i < num_courses; i++)
            {
                double grade; 
                in_stream >> course;
                Course *found_course = find_course(course, clist);
                if (found_course != NULL)
                {
                    in_stream >> grade;
                    found_student->add_course(found_course, grade);
                    found_course->enroll(found_student, grade);
                }
                else
                {
                    cout << "Error: course not found" << endl;
                    return -1;
                }
                course.clear();
            }
        }
        else{
            cout << "Error: student not found" << endl;
            return -1; 
        }
        counter++;
    }
    in_stream.close();
    return counter;
}

// function that take course id and displays the string return of the course object
void show_course_details(string c, vector<Course> &clist)
{
    Course *current = find_course(c, clist);
    if (current == NULL)
    {
        cout << "Error: Course not found" << endl;
        return;
    }
    else
    {
        cout << current->course_info() << endl;
    }
}

// function that takes the student id and displays the string return of the student object info
void show_student_details(string s, vector<Student> &slist)
{
    Student *current = find_student(s, slist);
    if (current == NULL)
    {
        cout << "Error: Student not found" << endl;
        return;
    }
    else
    {
        cout << current->student_info() << endl;
    }
}

// creates a new course by prompting the user to input required course information (not including enrolled students)
Course create_course()
{
    string course_id;
    int syear, smonth, sdate;
    int eyear, emonth, edate;
    int capacity;
    cout << "Course ID: ";
    cin >> course_id;
    buffer_cleaner();
    cout << "Enter start date (yyyy mm dd): ";
    cin >> syear >> smonth >> sdate;
    buffer_cleaner();
    cout << "Enter end date (yyyy mm dd): ";
    cin >> eyear >> emonth >> edate;
    buffer_cleaner();
    cout << "Enter Course Capacity:  ";
    cin >> capacity;
    buffer_cleaner();
    //TODOS check existed
    Course new_course(course_id, Date(syear, smonth, sdate), Date(eyear, emonth, edate), capacity);
    return new_course;
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
    //TODOS check existed
    Student new_student(first, last, cell, uid, Date(year, month, date));
    buffer_cleaner();
    return new_student;
}

void enroll_to_course(string sid, string cid, vector<Student> &slist, vector<Course> &clist)
{
    //initialize pointers to objects
    Student *student = find_student(sid, slist);
    Course *course = find_course(cid, clist);

    if (student == NULL || course == NULL)
    {
        cout << "The student or course is invalid. Please register first!" << endl;
        return;
    }
    else
    {
        student->add_course(course, 0.0);
        course->enroll(student,0.0);
    }
}

void withdraw_from_course(string sid, string cid, vector<Student> &slist, vector<Course> &clist)
{
    //initialize pointers to objects
    Student *student = find_student(sid, slist);
    Course *course = find_course(cid, clist);

    if (student == NULL || course == NULL)
    {
        //TODOS sysout error
        cout << "Error: student or course does not exist";
    }
    else
    {
        student->drop_course(course);
        course->withdraw(sid);
    }
}

//10. update student grade that takes a student id, course id, and grade to update the student grade in a given course. note that parameters needed
// might be more than the three specified
void update_grade(string sid, string cid, double new_grade, vector<Student> &slist, vector<Course> &clist)
{

    Student *current_s = find_student(sid, slist);

    if (current_s == NULL)
    {
        cout << "Error: Student not found" << endl;
        return;
    }

    Course *current_c = find_course(cid, clist);

    if (current_c == NULL)
    {
        cout << "Error: Course not found" << endl;
        return;
    }

    current_s->modify_grade(current_c, new_grade);
    current_c->update_grade(sid, new_grade);
}
//11. save changes will modify courses.txt, students.txt, and enroll.txt to reflect any changes that were made during the program run
//(i.e. new students added, course added, and new enrolments .... etc)
void modify_output(vector<Student> &slist, vector<Course> &clist, string filename)
{
    ofstream outfile(filename);

    for (int i = 0; i < (int)slist.size(); ++i)
    {
        outfile << slist.at(i).get_ID() << " " << (int)slist.at(i).get_course_list().size() << " ";
        for (int j = 0; j < (int)slist[i].get_course_list().size(); ++j)
        {
            outfile << slist[i].get_course_list().at(j).reg_course->get_cid() << " "
                    << slist[i].get_course_list().at(j).grade;
            if (j != (int)slist[i].get_course_list().size() - 1) {
                outfile << " ";
            }
        }
        if (i != (int)slist.size() - 1) {
            outfile << endl;
        }

    }

    outfile.close();
}