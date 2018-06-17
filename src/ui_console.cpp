#include "ui_console.hpp"
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <cstring>

namespace Contacts {
    void UIConsole::ShowMenu() {
        std::cout << "Menu" << std::endl << "====" << std::endl;
        std::cout << "Type: add *name* *phone* - To add new contact" << std::endl;
        std::cout << "Type: drop *name* - To delete a contact" << std::endl;
        std::cout << "Type: list - To list all contacts" << std::endl;
        std::cout << "Type: show *name* - To show a contact phone number" << std::endl;
        std::cout << "Type: find *phone* - To find a contact by phone number" << std::endl;
        std::cout << "Type: quit - To exit application" << std::endl;
        std::cout << "----" << std::endl;
    }

    AppRequest UIConsole::GetRequest(std::vector<std::string>& params) {
        std::string entry;
        std::getline(std::cin, entry);

        std::vector<std::string> arguments;
        char* temp = strtok(const_cast<char*>(entry.c_str()), " ");
        while (temp != nullptr) {
            arguments.push_back(std::string(temp));
            temp = strtok(nullptr, " ");
        }

        if (arguments[0] == "quit") {
            return AppRequest::Quit;
        } else if (arguments[0] == "list") {
            return AppRequest::List;
        }

        params.clear();
        for (int i = 1; i < arguments.size(); i++) {
            params.push_back(arguments[i]);
        }
        
        if (arguments[0] == "add") {
            return AppRequest::Add;
        } else if (arguments[0] == "drop") {
            return AppRequest::Drop;
        } else if (arguments[0] == "show") {
            return AppRequest::Show;
        } else if (arguments[0] == "find") {
            return AppRequest::Find;
        }

        return AppRequest::List;
    }

    void UIConsole::ShowData(std::vector<Contact>& contacts) {
        for (auto& c : contacts) {
            std::cout << c << std::endl;
        }
    }
}