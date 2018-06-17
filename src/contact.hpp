#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

#include <string>
#include <iostream>
#include <cstring>

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
    std::string GetName()
    {
        return name;
    }
    std::string GetPhone()
    {
        return phone;
    }
    bool Parse(std::string raw) {
        if (raw.empty()) {
            return false;
        } else {
            char* temp = strtok(const_cast<char*>(raw.c_str()), " ");
            name = std::string(temp);
            temp = strtok(nullptr, " ");
            phone = std::string(temp);
            return true;
        }
    }
};

#endif