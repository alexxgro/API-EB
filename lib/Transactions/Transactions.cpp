#include "Transactions.h"

Transactions::Transactions(DataStorage dataStorage) :
                            dataStorage(std::move(dataStorage)) {}

std::string Transactions::AddToBalanceOrCreateAccount(const std::string& accountId, float amount) {
    std::string updatedBalance;

    if (dataStorage.CheckAccountExists(accountId)) {
        updatedBalance = dataStorage.AddBalance(accountId, amount);
    }
    else {
        updatedBalance = dataStorage.CreateAccount(accountId, amount);
    }

    return updatedBalance;
}

std::string Transactions::GetBalance(const std::string& accountId) {
    return dataStorage.GetBalance(accountId);
}

void Transactions::ResetAccounts() {
    dataStorage.ResetAccounts();
}

bool Transactions::Transfer(const std::string& origin,
              const std::string& destination,
              float amount,
              std::string& updatedBalanceOrigin,
              std::string& updatedBalanceDestination) {

    if (!dataStorage.CheckAccountExists(origin)) {
        return false;
    }
    else {
        WithdrawFromAccount(origin, amount, updatedBalanceOrigin);
        updatedBalanceDestination = AddToBalanceOrCreateAccount(destination, amount);
        return true;
    }
}

bool Transactions::WithdrawFromAccount(const std::string& accountId, float amount, std::string& updatedBalance) {
    if (dataStorage.CheckAccountExists(accountId)) {
        updatedBalance = std::string("0");
        return false;
    }
    else {
        updatedBalance = dataStorage.WithdrawFromAccount(accountId, amount);
        return true;
    }
}