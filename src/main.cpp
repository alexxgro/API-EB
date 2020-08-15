#include <iostream>
#include "../lib/Server/server.hpp"
#include "../lib/Server/crow.h"

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/balance")([](){
        return "Hello world";
    });

    CROW_ROUTE(app, "/")
            .methods("POST"_method)
                    ([](const crow::request& req){
                        std::ostringstream os;
                        os << "hi back /r/n";
                        return crow::response{os.str()};
                    });

    app.port(80).bindaddr("192.168.1.144").multithreaded().run();
}