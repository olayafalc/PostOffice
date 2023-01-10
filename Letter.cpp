#include <iostream>
#include <ctime>
#include "Letter.h"
using namespace std;

Letter::Letter(string to_name, string to_address, string from_name, int day, int month, int year, bool abroad, bool older) : Correspondence(to_name, to_address, from_name), day(day), month(month), year(year), abroad(abroad), older(false) {}

//Getters
int Letter::get_day() const {return day;}
int Letter::get_month() const {return month;}
int Letter::get_year() const {return year;}
bool Letter::getAbroad() const {return abroad;}
bool Letter::getOlder() const {return older;}
//Setters
void Letter::set_from_date(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}
void Letter::setAbroad(bool a) {abroad = a;}
void Letter::setOlder(bool o) {older = o;}

//Functions
void Letter::print() const {
    cout << "Letter ";
    Correspondence::print(); //invoke base function via scope resolution operator
    if (abroad) {
        cout << ", Date (day/month/year)=" << day << "/" << month << "/" << year <<", Abroad=YES" << endl;
    } else {
        cout << ", Date (day/month/year)=" << day << "/" << month << "/" << year <<", Abroad=NO" << endl;
    }
}

double Letter::getPrice() const{
    double price;

    if(older) {
        price=15;
        if (abroad) {
            price = price + 10;
        }
    } else {
        price=7;
        if (abroad) {
            price = price + 7;
        }
    }
    //cout << "The price of the letter is " << price << " pln" << endl;
    return price;
}

bool Letter::isOver30DaysOld() const {
    int decemberDaysSpecialCase;
    //Get the current date
    time_t t = time(NULL);
    tm * timePtr = localtime(&t);
    int current_day = timePtr->tm_mday;
    int current_month = timePtr->tm_mon + 1; //Note: tm_mon is 0-indexed
    int current_year = timePtr->tm_year + 1900; //Note: tm_year is the numer of years since 1900

    if((year == current_year-1) && (month == 12) && (current_month == 1)) {
        decemberDaysSpecialCase = 31 - day;
        if ((decemberDaysSpecialCase + current_day) >= 30) {
            return true;
        } else {
            return false;
        }
    } else if (current_year > year) {
        return true;
    } else if ((current_year == year) && (current_month > month))  {
        return true;
    } else if ((current_year == year) && (current_month == month) && ((current_day - day) >= 30)) {
        return true;
    } else {
        return false;
    }
}
