#ifndef __APP_HPP__
#define __APP_HPP__

#include "ui_interface.hpp"
#include "request_types.hpp"
#include "contact.hpp"
#include "data.hpp"

namespace Contacts {
    class App {
        IUInterface *app_interface;
        Data* DB;
        
        public:
        void Initialize();
        bool Run();
        void Request(AppRequest req);
    };
}

#endif