#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>

    struct DataStorage
    {
    public:
        DataStorage() = default;

        std::string AddBalance(const std::string& accountId, float amount);
        bool CheckAccountExists(const std::string& accountId);
        std::string CreateAccount(const std::string& accountId, float amount);
        std::string GetBalance(const std::string& accountId);
        void ResetAccounts();
        std::string WithdrawFromAccount(const std::string& accountId, float amount);

    private:
        std::map<std::string, float> accounts;

    };
#endif //DATA_STORAGE_H
