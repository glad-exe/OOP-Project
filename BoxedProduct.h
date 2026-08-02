// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef BOXEDPRODUCT_H
#define BOXEDPRODUCT_H

#include "Product.h"
#include "ShelfLocation.h"
#include "Label.h"
class BoxedProduct : public Product, public Label {
    private:
        double        weight;   // Weight of the boxed product in kilograms
        ShelfLocation location; // Shelf location of the boxed product in storage. Location has aisle and slot. Aisle is a char, slot is an int.
    public:
        //CONSTRUCTORS

        //Default parametrized constructor
        //SO UNREADABLE OH MY GOD
        BoxedProduct::BoxedProduct(double pWeight, int bCode, const char* pName,
        double pPrice, int pStock, const char* pDescription)
        : Product(bCode, pName, pPrice, pStock, pDescription),
        Label(pName), 
        weight(pWeight), location() {
            cout << "BoxedProduct " << pName << " created." << endl;
        }
        
        //Copy constructor
        BoxedProduct(const BoxedProduct& other);
        //Destructor
        ~BoxedProduct();

        //member functions
        double deliveryCharge() const;
        void   displayInfo() const;

};
 
#endif
