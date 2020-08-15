#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../DTO/DataStorage.h"


class Transactions {
public:
    Transactions(DataStorage dataStorage);

    std::string AddToBalanceOrCreateAccount(const std::string& accountId, float amount);
    std::string GetBalance(const std::string& accountId);
    void ResetAccounts();
    bool WithdrawFromAccount(const std::string& accountId, float amount, std::string& updatedBalance);

private:
    DataStorage dataStorage;
};


#endif //TRANSACTIONS_H
