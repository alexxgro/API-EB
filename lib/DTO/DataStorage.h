#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>

    struct DataStorage
    {
    public:
        DataStorage() = default;

        float AlterBalance(const std::string& userId);
        std::string GetBalance(const std::string& userId);
        void ResetAccounts();

    private:
        std::map<std::string, float> accounts;

    };
#endif //DATA_STORAGE_H
