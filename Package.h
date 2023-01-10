#ifndef PACKAGE_h
#define PACKAGE_h
#include "Correspondence.h"
#include "Urgence.cpp"

class Package : public Correspondence{
    private:
        double weight;
        Urgence urg;
    public:
        Package(string to_name, string to_address, string from_name, double weight, Urgence urg);
        double getWeight() const;
        Urgence getUrg() const;
        void setWeight(double weight);
        void setUrg(Urgence urg);
        void print() const;
        double getPrice() const;
};

#endif // PACKAGE_h

