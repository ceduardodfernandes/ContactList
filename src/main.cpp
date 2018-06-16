#include <iostream>

#include "app.hpp"

int main(int argc, char* argv[]) {

    Contacts::App app;
    app.Initialize();

    while (1) {
        if (!app.Run())
            break;
    }

    return 0;
}
