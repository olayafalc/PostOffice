#include <iostream>
#include "Correspondence.h"

Correspondence::Correspondence(string to_name, string to_address, string from_name): to_name(to_name), to_address(to_address), from_name(from_name) {}

//Getters
string Correspondence::get_to_name() const {return to_name;}
string Correspondence::get_to_address() const {return to_address;}
string Correspondence::get_from_name() const {return from_name;}

//Setters
void Correspondence::set_to_name(string to_name) {this->to_name = to_name;}
void Correspondence::set_to_address(string to_address) {this->to_address = to_address;}
void Correspondence::set_from_name(string from_name) {this->from_name = from_name;}

//Pubic Functions
void Correspondence::print() const {
    cout << "Correspondence @ (From: " << from_name << ", To: " << to_name << ", Shipping Address: " << to_address << ")";
}

