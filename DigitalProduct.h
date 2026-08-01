// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#ifndef DIGITALPRODUCT_H
#define DIGITALPRODUCT_H

#include "Product.h"

class DigitalProduct : public Product
{
private:
    double downloadSize;
    char* licenceKey;
    char* copyString(const char* source);

public:
    DigitalProduct(double dSize = 0.0, const char* lKey = "", int bCode = 0, const char* pName = "",
        double pPrice = 0.0, int pStock = 0, const char* pDescription = "");

    //copy constructor
    DigitalProduct(const DigitalProduct& og);

    ~DigitalProduct();

    double deliveryCharge() const;
    void displayInfo() const;

};

#endif
