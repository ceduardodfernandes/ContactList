#ifndef __REQUEST_TYPES_HPP__
#define __REQUEST_TYPES_HPP__

namespace Contacts {
    enum class AppRequest {
        ListAll,
        Find,
        Add,
        Drop,
        Quit,
    };
}

#endif