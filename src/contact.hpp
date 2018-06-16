#include <string>
#include <iostream>

class Contact {
    int id;
    std::string name;
    std::string phone;

    public:
    Contact() { }
    Contact(std::string _name, std::string _phone) : name(_name), phone(_phone) {}
    ~Contact() { }
    friend std::ostream& operator<<(std::ostream& os, const Contact& contact) {
        os << contact.name << " " << contact.phone;
    }
};