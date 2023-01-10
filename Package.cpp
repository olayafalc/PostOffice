#include <iostream>
#include "Package.h"
using namespace std;

Package::Package(string to_name, string to_address, string from_name, double weight, Urgence urg) : Correspondence(to_name, to_address, from_name), weight(weight), urg(urg) {}

//Getters
double Package::getWeight() const {return weight;}
Urgence Package::getUrg() const {return urg;}

//Setters
void Package::setWeight(double w) {weight = w;}
void Package::setUrg(Urgence u) {urg = u;}

//Functions
void Package::print() const {
    cout << "Package ";
    Correspondence::print(); //invoke base function via scope resolution operator
    switch(urg) {
        case Urgence::urgent:
            cout << ", Weight=" << weight << "kg, Urgence=urgent" << endl;
            break;
        case Urgence::medium:
            cout << ", Weight=" << weight << "kg, Urgence=medium" << endl;
            break;
        case Urgence::no_urgent:
            cout << ", Weight=" << weight << "kg, Urgence=no urgent" << endl;
            break;
    }
}

double Package::getPrice() const {
    double price;

    price = weight*10;
    if (urg == Urgence::urgent) {
        price = price + 20;
    } else if (urg == Urgence::medium) {
        price = price + 10;
    }
    //cout << "The price of the package is " << price << " pln" << endl;
    return price;
}

