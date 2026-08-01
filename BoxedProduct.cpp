// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "BoxedProduct.h"
#include "ShelfLocation.h"
BoxedProduct::BoxedProduct(double pWeight, int bCode, const char* pName, 
    double pPrice, int pStock, const char* pDescription)
    : Product(bCode, pName, pPrice, pStock, pDescription), weight(pWeight), location() {
        cout << "BoxedProduct " << pName << " created." << endl;

    }
    
    BoxedProduct::~BoxedProduct() {
        cout << "BoxedProduct destroyed." << endl;
    }
    
    double BoxedProduct::deliveryCharge() const {
        if (weight <= 5.0) return 5.0;
        else if (weight <= 20.0) return 10.0;
        else return 20.0;
    }