#include "ui_interface.hpp"

namespace Contacts {
    class App {
        IUInterface *app_interface;
        
        public:
        void Initialize();
        bool Run();
    };
}