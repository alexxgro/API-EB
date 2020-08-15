#include "Routes.h"

    Routes::Routes(crow::SimpleApp &app, Transactions transactionHandler) :
                localApp(app),
                transactionHandler(std::move(transactionHandler)) {

            CROW_ROUTE(localApp, "/balance")([&](const crow::request& req){
                return BalanceRoute(req);
            });

            CROW_ROUTE(localApp, "/event")
                 .methods(crow::HTTPMethod::POST)
                        ([&](const crow::request& req){
                            return EventRoute(crow::json::load(req.body));
                        });

            CROW_ROUTE(localApp, "/reset")
                .methods(crow::HTTPMethod::POST)
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

    crow::response Routes::EventRoute(crow::json::rvalue body) {
        if (!body) {
            return crow::response(400);
        }

        std::string eventType = (body["type"]).s();
        float amount = std::stof((body["amount"]).s());

        if (eventType == "deposit") {
            auto newBalance = transactionHandler.AddToBalanceOrCreateAccount((body["destination"]).s(), amount);
            return crow::response(201, newBalance);
        }
        else if (eventType == "withdraw") {
            std::string updatedBalance;
            std::string origin = (body["origin"]).s();
            auto accountFound = transactionHandler.WithdrawFromAccount(origin, amount, updatedBalance);
            if (!accountFound) {
                return crow::response(404, std::to_string(0));
            }
            else {
                std::string jsonResponse = std::string("{\"destination\": {\"id\":") +
                                            origin + "\"" +
                                            ", \"balance\":" +
                                            updatedBalance + "}}";

                return crow::response(201, jsonResponse);
            }

        }
        else if (eventType == "transfer") {
            std::string origin = (body["origin"]).s();
            std::string destination = (body["destination"]).s();
            std::string updatedBalanceOrigin, updatedBalanceDestination;
            auto accountFound = transactionHandler.Transfer(origin, destination, amount, updatedBalanceOrigin, updatedBalanceDestination);
            if (!accountFound) {
                return crow::response(404, std::to_string(0));
            }
            else {
                std::string jsonResponse = std::string("{\"origin\": {\"id\":") +
                                           origin + "\"" +
                                           ", \"balance\":" +
                                            updatedBalanceOrigin + "},\"destination\":{\"id\":\"" +
                                            destination + "\", \"balance\":" +
                                            updatedBalanceDestination + "}}";
                return crow::response(201, jsonResponse);
            }
        }

        return crow::response(404, std::to_string(0));

    }

    crow::response Routes::ResetRoute() {
        transactionHandler.ResetAccounts();
        return crow::response(200, std::string("OK"));
    }