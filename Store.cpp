// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#include "Store.h"

#include <iostream>
using namespace std;

//Same old helper function as in Product class. Just copied here to avoid any issues with inheritance and access specifiers.
//see also: supplier.cpp, digitalproduct.cpp, label.cpp
char* Store::copyString(const char* original){
    if(!original) original = "";
    int len = 0;
    while(original[len] != '\0') len++;
    char* temp = new char[len + 1];
    for(int i = 0; i < len; i++) temp[i] = original[i];
    temp[len] = '\0';
    return temp;
}

Store::Store(const char* sName, const char* sAddress, int warehouseSize)
    :inventory(warehouseSize) {
        storeName = copyString(sName);
        address = copyString(sAddress);
        cout << "Store " << storeName << " created." << endl;
    }

Store::~Store(){
    delete[] storeName;
    delete[] address;
    cout << "Store " << storeName << " destroyed." << endl;
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
