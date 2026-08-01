// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "DigitalProduct.h"
using namespace std;

    //Same old helper function as in Product class. Just copied here to avoid any issues with inheritance and access specifiers.
    //see also: store.cpp, supplier.cpp, label.cpp, digitalproduct.cpp
    char* Product::copyString(const char* original){
        if(!original) original = "";
        int len = 0;
        while(original[len] != '\0') len++;

        char* temp = new char[len + 1];
        for(int i = 0; i < len; i++) temp[i] = original[i];

        temp[len] = '\0';
        return temp;
    }

    //Default parametrized constructor
    DigitalProduct::DigitalProduct(double dSize = 0.0, const char* lKey = "", int bCode = 0, const char* pName = "",
        double pPrice = 0.0, int pStock = 0, const char* pDescription = "")
        : Product(bCode, pName, pPrice, pStock, pDescription) {

            downloadSize = dSize;
            licenceKey = copyString(lKey);
            cout << "DigitalProduct " << pName << " created." << endl;
    }

    //Copy constructor
    DigitalProduct::DigitalProduct(const DigitalProduct& og)
        : Product(og) {

            downloadSize = og.downloadSize;
            licenceKey = copyString(og.licenceKey);
            cout << "DigitalProduct copied." << endl;
    }

    DigitalProduct::~DigitalProduct() {
        delete[] licenceKey;
        cout << "DigitalProduct destroyed." << endl;
    }

    double DigitalProduct::deliveryCharge() const {
        return 0.0;
    }

    void DigitalProduct::displayInfo() const {
        Product::displayInfo();
        cout << "Download Size: " << downloadSize << " MB" << endl;
        cout << "Licence Key: " << licenceKey << endl;
    }
