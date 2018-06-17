#include "data.hpp"
#include <iostream>
#include <fstream>
#include <exception>

namespace Contacts {

    Data* Data::_instance = nullptr;

    void Data::Load() {
        _contacts.clear();

        try {
            std::ifstream file(filename);
            if (file.is_open()) {
                while (!file.eof()) {
                    std::string line;
                    std::getline(file, line);
                    Contact contact;
                    if (contact.Parse(line)) {
                        _contacts[contact.GetName()] = contact;
                    }
                }
            }
        } catch (std::exception& e) {
            std::cout << "Error loading data: " << e.what() << std::endl;
        }
    }

    void Data::Flush() {
        std::ofstream file;
        file.open(filename, std::ofstream::out | std::ofstream::trunc);
        file.close();

        file.open(filename);
        for (auto c : _contacts) {
            file << c.second << std::endl;
        }
        file.close();
    }

    bool Data::AddContact(Contact& contact) {
        _contacts[contact.GetName()] = contact;
        Data::Flush();
        return true;
    }

    bool Data::DropContact(Contact& contact) {
        return DropContact(contact.GetName());
    }

    bool Data::DropContact(std::string name) {
        std::map<std::string,Contact>::iterator it = _contacts.find(name);

        if (it != _contacts.end()) {
            _contacts.erase(it);
            Data::Flush();
            return true;
        } else {
            return false;
        }
    }
            
    std::vector<Contact> Data::List() {
        int i = 0;
        std::vector<Contact> result(_contacts.size());
        for (auto& c : _contacts) {
            result[i++] = Contact(c.second);
        }

        return result;
    }

    Contact* Data::Find(std::string phone) {
        for (auto& c : _contacts) {
            if (c.second.GetPhone() == phone) {
                return &c.second;
            }
        }

        return nullptr;
    }
        
    Contact* Data::Get(std::string name) {
        auto it = _contacts.find(name);

        if (it != _contacts.end()) {
            return &((*it).second);
        }

        return nullptr;
    }
}