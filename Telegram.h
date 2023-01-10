#ifndef TELEGRAM_h
#define TELEGRAM_h
#include "Correspondence.h"

class Telegram : public Correspondence{
    private:
        int amount_words;
        int tax;
    public:
        Telegram(string to_name, string to_address, string from_name, int amount_words, int tax);
        int get_amount_words() const;
        int getTax() const;
        void set_amount_words(int amount_words);
        void setTax(int tax);
        void print() const;
        double getPrice() const;
};

#endif // TELEGRAM_h
