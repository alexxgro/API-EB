#include "DataStorage.h"

float DataStorage::AlterBalance(const std::string& accountId){
    return 0;
}

std::string DataStorage::GetBalance(const std::string& accountId){
    auto it = accounts.find(accountId);
    if (it != accounts.end()) {
        return std::to_string(it->second);
    }
    else {
        return std::string("Not Found");
    }
}

