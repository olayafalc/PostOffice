#include <iostream>
#include "Telegram.h"
using namespace std;

Telegram::Telegram(string to_name, string to_address, string from_name, int amount_words, int tax) : Correspondence(to_name, to_address, from_name), amount_words(amount_words), tax(tax) {}

//Getters
int Telegram::get_amount_words() const {return amount_words;}
int Telegram::getTax() const {return tax/100.00;}

//Setters
void Telegram::set_amount_words(int aw) {amount_words = aw;}
void Telegram::setTax(int t) {tax = t;}

//Functions
void Telegram::print() const {
    cout << "Telegram ";
    Correspondence::print(); //invoke base function via scope resolution operator
    cout << ", Amount of words=" << amount_words << ", Tax=" << tax/100.00 << endl;
}

double Telegram::getPrice() const {
    double price;

    if (amount_words < 50) {
        price = 2 + 2*tax/100.00;
    } else if (50 <= amount_words < 150) {
        price = 3 + 3*tax/100.00;
    } else {
        price = 5 + 5*tax/100.00;
    }
    //cout << "The price of the telegram is " << price << " pln" << endl;
    return price;
}





