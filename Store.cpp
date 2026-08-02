// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Store.h"
#include "StringUtils.h"
#include <iostream>
using namespace std;

//Default constructor
Store::Store(const char* sName, const char* sAddress, int warehouseSize)
    :inventory(warehouseSize) {
        storeName = copyString(sName);
        address = copyString(sAddress);
        cout << "Store " << storeName << " created." << endl;
    }

//destructor
Store::~Store(){
    cout << "Store " << storeName << " destroyed." << endl;
    delete[] storeName;
    delete[] address;
}


void Store::openStore(){ //MAKE SURE TO READ ABOUT THIS FUNCTION, WE DONT KNOW IF THIS IS ENOUGH OR IF WE NEED TO ADD MORE FUNCTIONALITY
    cout << storeName << " is now open." << endl;
}

void Store::closeStore(){ //MAKE SURE TO READ ABOUT THIS FUNCTION, WE DONT KNOW IF THIS IS ENOUGH OR IF WE NEED TO ADD MORE FUNCTIONALITY
    cout << storeName << " is now closed." << endl;
}

const char* Store::getName()    const { return storeName; }
const char* Store::getAddress() const { return address;   }
Inventory&  Store::getInventory()     { return inventory; }
Supplier&   Store::getSupplier()      { return supplier;  }
