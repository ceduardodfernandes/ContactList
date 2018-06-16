#ifndef __IUINTERFACE_HPP__
#define __IUINTERFACE_HPP__

#include <vector>
#include <string>
#include "request_types.hpp"

namespace Contacts {
    class IUInterface {
        public:
        virtual void ShowMenu() = 0;
        virtual AppRequest GetRequest(std::vector<std::string>& params) = 0;
    };
}

#endif