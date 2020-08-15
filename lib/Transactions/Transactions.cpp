#include "Transactions.h"

Transactions::Transactions(DataStorage dataStorage) :
                            dataStorage(std::move(dataStorage)){}
