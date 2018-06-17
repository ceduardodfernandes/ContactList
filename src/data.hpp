#ifndef __DATA_HPP__
#define __DATA_HPP__

#include "contact.hpp"
#include <string>
#include <vector>
#include <map>

namespace Contacts {
    class Data {
        static Data* _instance;
        const std::string filename = "db.dat";
        std::map<std::string,Contact> _contacts;
        void Load();
        public:
        static Data* GetInstance() {
            if (_instance == nullptr) {
                _instance = new Data();
                _instance->Load();
            }

            return _instance;
        }

        void Flush();
        bool AddContact(Contact& contact);
        bool DropContact(Contact& contact);
        bool DropContact(std::string name);
        std::vector<Contact> List();
        Contact* Find(std::string phone);
        Contact* Get(std::string name);
    };
}

#endif