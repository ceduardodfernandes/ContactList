#ifndef __IUINTERFACE_HPP__
#define __IUINTERFACE_HPP__

#include <vector>
#include <string>
#include "request_types.hpp"
#include "contact.hpp"

namespace Contacts {
    class IUInterface {
        public:
        virtual void ShowMenu() = 0;
        virtual AppRequest GetRequest(std::vector<std::string>& params) = 0;
        virtual void ShowData(std::vector<Contact>& contacts) = 0;
    };
}

#endif