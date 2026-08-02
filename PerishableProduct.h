// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#include "Product.h"

#ifndef PERISHABLEPRODUCT_H
#define PERISHABLEPRODUCT_H

class PerishableProduct : public Product{
    private:
        double storageTemperature;   // Storage temperature of the perishable product in degrees Celsius.
        int    daysUntilExpiration;  // Number of days until the perishable product expires.
    public:
        //Constructors
        //Default parametrized constructor
        PerishableProduct(int bCode = 0, const char* pName = "", double pPrice = 0.0, int pStock = 0, 
            const char* pDescription = "", double sTemp = 0.0, int dUntilExp = 0);

        //Copy constructor
        PerishableProduct(const PerishableProduct& og);

        //Destructor
        ~PerishableProduct();

        //MEMBER FUNCTIONS
        bool    hasExpired()      const;
        double  deliveryCharge()  const;
        void    displayInfo()     const;
};

#endif