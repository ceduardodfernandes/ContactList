#include "ui_console.hpp"
#include <iostream>

namespace Contacts {
    void UIConsole::ShowMenu() {
        std::cout << "Menu" << std::endl << "====" << std::endl;
        std::cout << "Type: add *name* *phone* - To add new contact" << std::endl;
        std::cout << "Type: drop *name* - To delete a contact" << std::endl;
        std::cout << "Type: list - To list all contacts" << std::endl;
        std::cout << "Type: list *name* - To show a contact phone number" << std::endl;
        std::cout << "Type: find *phone* - To find a contact by phone number" << std::endl;
        std::cout << "Type: quit - To exit application" << std::endl;
        std::cout << "----" << std::endl;

        std::string entry;

        std::cin >> entry;
        std::cin.ignore();
    }
}