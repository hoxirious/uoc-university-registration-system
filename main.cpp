#include "student.h"
#include "date.h"
#include "program_functions.h"

int main(int argc, char **argv)
{

    while (1)
    {
        switch (main_menu())
        {
        case 1:
            pressEnter();
            break;

        case 2:
            pressEnter();
            break;

        case 3:
            pressEnter();
            break;

        case 4:
            pressEnter();
            break;

        case 5:
            cout << "\nProgram terminated!\n\n";
            quit = 1;
            break;

        default:
            cout << "\nNot a valid input.\n";
            pressEnter();
        }
        if (quit == 1)
            break;
    }

    return 0;
}