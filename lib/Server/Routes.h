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
    std::string BalanceRoute();
};

#endif	/* ROUTES_H */