#include "date.h"

Date::Date() {}

Date::Date(int y, int m, int d) {
    set_year(y);
    set_month(m);
    set_day(d);
}

void Date::set_year(int y) {
    year = y;
}
void Date::set_month(int m) {
    month = m;
}

void Date::set_day(int d) {
    day = d;
}

int Date::get_year() {
    return year;
}
int Date::get_month() {
    return month;
}
int Date::get_day() {
    return day;
}

string Date::date_string(){
    string result("Date: ");
    result += get_month();
    result += "/";
    result += get_day();
    result += "/";
    result += get_year();

    return result;
}