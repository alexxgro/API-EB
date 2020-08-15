#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <map>
#include <string>

    struct DataStorage
    {
    public:
        DataStorage() = default;

    private:
        float AlterBalance(const std::string& userId);
        float GetBalance(const std::string& userId);

    private:
        std::map<std::string, float> accounts;

    };
#endif //DATA_STORAGE_H
