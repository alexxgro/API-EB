#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "../DTO/DataStorage.h"


class Transactions {
public:
    Transactions(DataStorage dataStorage);

private:
    DataStorage dataStorage;
};


#endif //TRANSACTIONS_H
