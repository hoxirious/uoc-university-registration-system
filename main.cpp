#include "program_functions.h"

int main(int argc, char **argv)
{

    vector<Student> slist;
    vector<Course> clist;
    int s_result = 0, c_result = 0;
    if (argc > 1)
    {
        do
        {
            s_result = load_studentfile(argv[1], slist);
            c_result = load_coursefile(argv[2], clist);
            if (s_result == -1 || c_result == -1)
            {
                cout << "Error: Input files are invalid";
                pressEnter();
            }
        } while (c_result == -1 || s_result == -1);
        cout << s_result << " students added to databases from file" << endl;

        for (int i = 0; i < s_result; i++)
            show_student_details(slist.at(i).get_ID(), slist);
        cout << "---------------------------------------------" << endl;
        cout << c_result << " courses added to databases from file" << endl;
        for (int i = 0; i < c_result; i++)
            show_course_details(clist.at(i).get_cid(), clist);
        pressEnter();
    }
    else
    {
        string s_filename, c_filename;
        while (s_result != -1)
        {
            cout << "Input students list file name" << endl;
            cin >> s_filename;
            s_result = load_studentfile(s_filename, slist);
            buffer_cleaner();
        }
        cout << s_result << " students added to databases from file" << endl;
        pressEnter();
        while (c_result != -1)
        {
            cout << "Input students list file name" << endl;
            cin >> s_filename;
            c_result = load_studentfile(s_filename, slist);
            buffer_cleaner();
        }
        cout << c_result << " courses added to databases from file" << endl;
        pressEnter();
    }
    while (1)
    {
        string input1, input2;
        int input3;

        switch (main_menu())
        {
        case 1:

            pressEnter();
            break;

        case 2:
            pressEnter();
            break;

        case 3:
            cin >> input1;
            if (enrollment_file(input1, clist, slist) != -1)
            {
                //TODOS Check the output of random samples using option 4 and 5
                cout << "It works!";
            }
            else
            {
                cout << "Nope";
            }
            input1.clear();
            buffer_cleaner();
            pressEnter();
            break;

        case 4:
            cin >> input1;
            show_course_details(input1, clist);
            input1.clear();
            buffer_cleaner();
            pressEnter();
            break;

        case 5:
            cin >> input1;
            show_student_details(input1, slist);
            input1.clear();
            buffer_cleaner();
            pressEnter();
            break;

        case 6:
            create_course();
            pressEnter();
            break;

        case 7:
            create_student();
            pressEnter();
            break;

        case 8:
            cout << "Enter student ID (example 30074838): ";
            cin >> input1;
            cout << "Enter course ID (example ENSF337): ";
            cin >> input2;
            enroll_to_course(input1, input2, slist, clist);
            show_student_details(input1, slist);
            show_course_details(input2, clist);
            input1.clear();
            input2.clear();
            buffer_cleaner();
            pressEnter();
            break;
        case 9:
            cout << "Enter student ID (example 30074838): ";
            cin >> input1;
            cout << "Enter course ID (example ENSF337): ";
            cin >> input2;
            withdraw_from_course(input1, input2, slist, clist);
            show_student_details(input1, slist);
            show_course_details(input2, clist);
            input1.clear();
            input2.clear();
            buffer_cleaner();
            pressEnter();
            break;

        case 10:
            cout << "Enter student ID (example 30074838): ";
            cin >> input1;
            cout << "Enter course ID (example ENSF337): ";
            cin >> input2;
            cout << "Enter modified grades: ";
            cin >> input3;
            update_grade(input1, input2, input3, slist, clist);
            input1.clear();
            input2.clear();
            buffer_cleaner();
            pressEnter();
            break;

        case 11:
            modify_output(slist, clist, "enroll.txt");
        case 12:
            system("clear");
            exit(1);
            break;

        default:
            cout << "\nNot a valid input1.\n";
            pressEnter();
        }
    }

    return 0;
}