#include "Transactions.h"

Transactions::Transactions(DataStorage dataStorage) :
                            dataStorage(std::move(dataStorage)) {}

std::string Transactions::GetBalance(const std::string& account_id) {
    return dataStorage.GetBalance(account_id);
}

void Transactions::ResetAccounts() {
    dataStorage.ResetAccounts();
}