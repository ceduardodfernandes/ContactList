#include "app.hpp"
#include "ui_interface.hpp"
#include "ui_console.hpp"

namespace Contacts {
    void App::Initialize() {
        app_interface = new UIConsole();
    }

    bool App::Run() {
        app_interface->ShowMenu();
        
        return true;
    }
}