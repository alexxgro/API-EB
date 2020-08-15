#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../DTO/DataStorage.h"


class Transactions {
public:
    Transactions(DataStorage dataStorage);

    std::string GetBalance(const std::string& account_id);
    void ResetAccounts();

private:
    DataStorage dataStorage;
};


#endif //TRANSACTIONS_H
