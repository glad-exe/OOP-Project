// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#ifndef STORE_H
#define STORE_H

#include "Inventory.h"
#include "Supplier.h"

class Store {
    private:
        char* storeName;
        char* address;
        Inventory inventory;
        Supplier supplier;
        char* copyString(const char* source);

    public:
        Store(const char* sName = "", const char* sAddress = "", int warehouseSize = 0);
        ~Store();

        void openStore();
        void closeStore();

        const char* getName() const;
        const char* getAddress() const;
        Inventory&  getInventory();
        Supplier&   getSupplier();
    };

    #endif
