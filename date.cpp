#include "date.h"

Date::Date(): year(0), month (0), day(0) {}

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
    string result("");
    result.append(to_string(get_month()));
    result.append("/");
    result.append(to_string(get_day()));
    result.append("/");
    result.append(to_string(get_year()));
    return result;
}