#include <iostream>
#include "../lib/Server/crow.h"
#include "../lib/Server/Routes.h"

int main()
{
    crow::SimpleApp app;

    Routes router(app);

    app.port(80).bindaddr("192.168.1.144").multithreaded().run();
}