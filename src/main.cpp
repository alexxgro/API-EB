#include <iostream>
#include "../lib/DTO/DataStorage.h"
#include "../lib/Server/crow.h"
#include "../lib/Server/Routes.h"
#include "../lib/Transactions/Transactions.h"

int main()
{
    crow::SimpleApp app;
    DataStorage dataStorage;
    Transactions transactionHandler(std::move(dataStorage));

    Routes router(app, std::move(transactionHandler));

    app.port(80).bindaddr("192.168.1.144").multithreaded().run();
}