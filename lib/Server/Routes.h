#ifndef ROUTES_H
#define	ROUTES_H

#include "crow.h"
#include "../Transactions/Transactions.h"

class Routes {
public:
    Routes(crow::SimpleApp &app, Transactions transactionHandler);

private:
    crow::SimpleApp &localApp;
    Transactions transactionHandler;
    crow::response BalanceRoute(const crow::request& req);
    crow::response EventRoute(crow::json::rvalue body);
    crow::response ResetRoute();
};

#endif	/* ROUTES_H */