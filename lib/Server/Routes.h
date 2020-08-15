#ifndef ROUTES_H
#define	ROUTES_H

#include "crow.h"

class Routes {
public:
    Routes(crow::SimpleApp &app);

private:
    crow::SimpleApp &localApp;
    std::string BalanceRoute();
};

#endif	/* ROUTES_H */