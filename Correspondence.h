#ifndef CORRESPONDENCE_h
#define CORRESPONDENCE_h
#include <string>
using namespace std;

class Correspondence {
    private:
        string to_name;
        string to_address;
        string from_name;
    public:
        //Constructor
        Correspondence(string to_name, string to_address, string from_name);
        //Destructor
        virtual ~Correspondence(){};
        // Getters
        string get_to_name() const;
        string get_to_address() const;
        string get_from_name() const;
        // Setters
        void set_to_name(string to_name);
        void set_to_address(string to_address);
        void set_from_name(string from_name);
        // Public functions
        void print() const;
        virtual double getPrice() const = 0;
};

#endif // CORRESPONDENCE_h
