#include "app.hpp"
#include "ui_interface.hpp"
#include "ui_console.hpp"
#include "data.hpp"
#include <iostream>
#include <algorithm>

namespace Contacts {
    void App::Initialize() {
        app_interface = new UIConsole();
    }

    bool App::Run() {
        app_interface->ShowMenu();
        
        std::vector<std::string> params;
        AppRequest response = app_interface->GetRequest(params);
        
        if (response == AppRequest::Quit) {
            return false;
        } else if (response == AppRequest::Add) {
            Contact c(params[0], params[1]);
            Data::GetInstance()->AddContact(c);
        } else if (response == AppRequest::Drop) {
            Data::GetInstance()->DropContact(params[0]);
        } else if (response == AppRequest::List) {
            std::vector<Contact> contacts = Data::GetInstance()->List();
            app_interface->ShowData(contacts);
        }

        return true;
    }
}