#ifndef LETTER_h
#define LETTER_h
#include "Correspondence.h"

class Letter : public Correspondence{
    private:
        int day;
        int month;
        int year;
        bool abroad;
        bool older;
    public:
        Letter(string to_name, string to_address, string from_name, int day, int month, int year, bool abroad, bool older);
        int get_day() const;
        int get_month() const;
        int get_year() const;
        bool getAbroad() const;
        bool getOlder() const;
        void set_from_date(int day, int month, int year);
        void setAbroad(bool abroad);
        void setOlder(bool older);
        void print() const;
        double getPrice(/*bool older*/) const;
        bool isOver30DaysOld() const;
};

#endif // LETTER_h
