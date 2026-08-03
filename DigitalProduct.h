// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#ifndef DIGITALPRODUCT_H
#define DIGITALPRODUCT_H

#include "Product.h"

class DigitalProduct : public Product {
    private:
        double downloadSize;  // Size of the digital product in megabytes (MB)
        char*  licenceKey;    // License key for the digital product, stored as a dynamically allocated C-style string.
    public:
    
        //CONSTRUCTORS
        //Default parametrized constructor

        DigitalProduct(double dSize = 0.0, const char* lKey = "", int bCode = 0, const char* pName = "",
            double pPrice = 0.0, int pStock = 0, const char* pDescription = "");

        //copy constructor
        DigitalProduct(const DigitalProduct& og);

        //Destructor
        ~DigitalProduct();

        //member functions
        double deliveryCharge() const;
        void   displayInfo() const;

};

#endif
