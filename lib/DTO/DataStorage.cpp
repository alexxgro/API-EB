#include "DataStorage.h"

std::string DataStorage::AddBalance(const std::string &accountId, float amount) {
    auto currentAccount = accounts.find(accountId);
    float newBalance = currentAccount->second + amount;

    accounts[currentAccount->first] = newBalance;

    return std::to_string(newBalance);
}

bool DataStorage::CheckAccountExists(const std::string& accountId) {
    auto it = accounts.find(accountId);
    if (it == accounts.end())
        return false;
    else
        return true;
}

std::string DataStorage::CreateAccount(const std::string& accountId, float amount) {
    accounts.insert(std::pair<std::string, float>(accountId, amount));

    return std::to_string(amount);
}

std::string DataStorage::GetBalance(const std::string& accountId) {
    auto it = accounts.find(accountId);
    if (it != accounts.end()) {
        return std::to_string(it->second);
    }
    else {
        return std::string("Not Found");
    }
}

void DataStorage::ResetAccounts() {
    accounts.clear();
}

std::string DataStorage::WithdrawFromAccount(const std::string& accountId, float amount) {
    auto currentAccount = accounts.find(accountId);
    float newBalance = currentAccount->second - amount;

    accounts[currentAccount->first] = newBalance;

    return std::to_string(newBalance);
}

