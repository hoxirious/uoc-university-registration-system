#include "program_functions.h"

// function to show main menue and prompt the user to select input option
int main_menu(){}
// cleans leftovers in the input buffer after any input operation
void buffer_cleaner(){}
// function to open file using file stream and extract course information in the file. the extraction is based on the file format provided in the supporting materials document
int load_coursefile(string filename, vector<Course> & clist){}
// function to open file using file stream and extract student information in the file.
int load_studentfile(string filename, vector<Student> & slist){}
// search function that finds a student object in the vector of students using the student id and return a pointer to the student object
Student* find_student(string id,vector<Student>& student_list){}
// search function that finds a course object in the vector of students using the course id and returns a pointer to the course object
Course* find_course(string cid,vector<Course>& course_list){}
// function to open enrollement file using a file stream and extracts student enrollment into courses information. must update the course objects to include the student in the student list, and update the student object to have the course in enrolled courses list
int enrollment_file(string filename, vector<Course> & clist, vector<Student>& slist){}
// function that take course id and displays the string return of the course object
void show_course_details(string c,vector<Course>& clist){}
// function that takes the student id and displays the string return of the student object info
void show_student_details(string s,vector<Student>& slist){}
// creates a new course by prompting the user to input required course information (not including enrolled students)
Course create_course(){}
// creates a new student object by prompting user to input required student information for the constructor
Student create_student(){}
// enrolls the student with sid into course with cid.
void enroll_to_course(string sid, string cid,vector<Student>& slist,vector<Course>& clist){}