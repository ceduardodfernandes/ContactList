#ifndef __UICONSOLE_HPP__
#define __UICONSOLE_HPP__

#include "ui_interface.hpp"
#include "app.hpp"
#include <vector>

namespace Contacts {
    class UIConsole : public IUInterface {
        public:
        void ShowMenu();
        AppRequest GetRequest(std::vector<std::string>& params);
    };
}

#endif