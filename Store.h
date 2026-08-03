// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#ifndef STORE_H
#define STORE_H

#include "Inventory.h"
#include "Supplier.h"

class Store {
    private:
        char*     storeName;     // Name of the store, stored as a dynamically allocated C-style string.
        char*     address;       // Address of the store, stored as a dynamically allocated C-style string.
        Inventory inventory;     // Inventory object. read documentation in inventory.h for more information. 
        Supplier  supplier;      // Supplier object

    public:
        Store(const char* sName = "", const char* sAddress = "", int warehouseSize = 0);
        ~Store();

        Store(const Store& other) = delete;
        Store& operator=(const Store& other) = delete;

        void openStore();
        void closeStore();

        const char* getName() const;
        const char* getAddress() const;
        Inventory&  getInventory();
        Supplier&   getSupplier();
    };

#endif
