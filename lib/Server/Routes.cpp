#include "Routes.h"


    Routes::Routes(crow::SimpleApp &app, Transactions transactionHandler) :
                localApp(app),
                transactionHandler(std::move(transactionHandler)) {

            CROW_ROUTE(localApp, "/balance")([&](){
                return BalanceRoute();
            });

            CROW_ROUTE(localApp, "/")
            .methods("POST"_method)
            ([&](const crow::request& req){
                std::ostringstream os;
                os << "hi back /r/n";
                return crow::response{os.str()};
            });
    }

    std::string Routes::BalanceRoute() {
        return "Hello";
    }