// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "PerishableProduct.h"

    //Constructors

    //Default constructor
    PerishableProduct::PerishableProduct(int bCode, const char* pName, double pPrice, int pStock,
        const char* pDescription, double sTemp, int dUntilExp)
        : Product(bCode, pName, pPrice, pStock, pDescription) {
        storageTemperature = sTemp;
        daysUntilExpiration = dUntilExp;
        cout << "PerishableProduct " << pName << " created." << endl;
    }

    //Copy constructor
    PerishableProduct::PerishableProduct(const PerishableProduct& og)
        : Product(og) {
        storageTemperature = og.storageTemperature;
        daysUntilExpiration = og.daysUntilExpiration;
        cout << "PerishableProduct " << og.productName << " copied." << endl;
    }

    //Destructor
    PerishableProduct::~PerishableProduct() {
        cout << "PerishableProduct " << productName << " destroyed." << endl;
    }

    //MEMBER FUNCTIONS

    //checks if days left is 0 or less.
    bool PerishableProduct::hasExpired() const {
        if (daysUntilExpiration <= 0) return true;
        return false;
    }

    //frozen goods cost more to deliver.
    //
    double PerishableProduct::deliveryCharge() const {
        if (storageTemperature <= 4.0) return 15.0;
        return 5.0;
    }

    //shows product info plus the extra perishable goods.
    void PerishableProduct::displayInfo() const {
        Product::displayInfo();
        cout << "Storage Temp: " << storageTemperature << " C" << endl;
        cout << "Days Left   : " << daysUntilExpiration << endl;
        cout << "Expired     : " << hasExpired() << endl;
    }
