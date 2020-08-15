#include "Routes.h"


    Routes::Routes(crow::SimpleApp &app, Transactions transactionHandler) :
                localApp(app),
                transactionHandler(std::move(transactionHandler)) {

            CROW_ROUTE(localApp, "/balance")([&](const crow::request& req){
                return BalanceRoute(req);
            });

            CROW_ROUTE(localApp, "/event")
                 .methods("POST"_method)
                        ([&](const crow::request& req){
                            return EventRoute(req);
                        });

        CROW_ROUTE(localApp, "/reset")
                .methods("POST"_method)
                        ([&](){
                            return ResetRoute();
                        });
    }

    crow::response Routes::BalanceRoute(const crow::request& req) {
        auto account_id = req.url_params.get("account_id");
        if (!account_id) {
            return crow::response(404, "0");
        }
        else {
            auto currentBalance = transactionHandler.GetBalance(std::string(account_id));
            if (currentBalance == "Not Found") {
                return crow::response(404, std::to_string(0));
            } else
                return crow::response(200, currentBalance);
        }
    }

    crow::response Routes::EventRoute(const crow::request& req) {
        return crow::response(404, std::to_string(0));
    }

    crow::response Routes::ResetRoute() {
        transactionHandler.ResetAccounts();
        return crow::response(200, std::string("OK"));
    }