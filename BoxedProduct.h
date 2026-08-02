// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef BOXEDPRODUCT_H
#define BOXEDPRODUCT_H

#include "Product.h"
#include "ShelfLocation.h"
class BoxedProduct : public Product {
    private:
        double        weight;   // Weight of the boxed product in kilograms
        ShelfLocation location; // Shelf location of the boxed product in storage. Location has aisle and slot. Aisle is a char, slot is an int.
    public:
        //CONSTRUCTORS
        //Default parametrized constructor
        BoxedProduct(double weight = 0.0, int bCode = 0, const char* pName = "",
            double pPrice = 0.0, int pStock = 0, const char* pDescription = "");
        
        //Copy constructor
        BoxedProduct(const BoxedProduct& other);
        //Destructor
        ~BoxedProduct();

        //member functions
        double deliveryCharge() const;
        void   displayInfo() const;
};
 
#endif
