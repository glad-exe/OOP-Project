// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "DigitalProduct.h"
using namespace std;

    //Same old helper function as in Product class. Just copied here to avoid any issues with inheritance and access specifiers.
    //see also: store.cpp, supplier.cpp, label.cpp, digitalproduct.cpp
    // This function takes a C-style string (const char*) as input and creates a new dynamically allocated copy of that string.
    // It first checks if the input string is null, and if so, it treats it as an empty string. 
    // It then calculates the length of the input string, allocates memory for a new string of the same length plus one for the null terminator,
    // and copies each character from the original string to the new string.
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
    // Initializes downloadSize to 0.0 and licenceKey to an empty string.
    // Calls the base Product constructor with default values.
    DigitalProduct::DigitalProduct(double dSize = 0.0, const char* lKey = "", int bCode = 0, const char* pName = "",
        double pPrice = 0.0, int pStock = 0, const char* pDescription = "")
        : Product(bCode, pName, pPrice, pStock, pDescription) {

            downloadSize = dSize;
            licenceKey = copyString(lKey);
            cout << "DigitalProduct " << pName << " created." << endl;
    }

    //Copy constructor
    // Uses the base Product copy constructor to copy the base class members
    // and also copies the downloadSize and licenceKey from the other DigitalProduct object.
    DigitalProduct::DigitalProduct(const DigitalProduct& og)
        : Product(og) {

            downloadSize = og.downloadSize;
            licenceKey = copyString(og.licenceKey);
            cout << "DigitalProduct copied." << endl;
    }

    //Destructor
    //Frees the dynamically allocated memory for licenceKey
    DigitalProduct::~DigitalProduct() {
        delete[] licenceKey;
        cout << "DigitalProduct destroyed." << endl;
    }
    //member functions
    //delivery charge for digital products is always 0.0
    //i dont know why this would ever be needed IRL but its here for the sake of the assignment.
    double DigitalProduct::deliveryCharge() const {
        return 0.0;
    }

    //display information about the digital product, calls the base class displayInfo
    //adds download size and licence key
    void DigitalProduct::displayInfo() const {
        Product::displayInfo();
        cout << "Download Size: " << downloadSize << " MB" << endl;
        cout << "Licence Key: " << licenceKey << endl;
    }
