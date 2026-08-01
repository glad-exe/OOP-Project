// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "BoxedProduct.h"
#include "ShelfLocation.h"
    //CONSTRUCTORS
    //Default parametrized constructor
    BoxedProduct::BoxedProduct(double pWeight, int bCode, const char* pName, 
    double pPrice, int pStock, const char* pDescription)
    : Product(bCode, pName, pPrice, pStock, pDescription), weight(pWeight), location() {
        cout << "BoxedProduct " << pName << " created." << endl;
    }

    BoxedProduct::BoxedProduct(const BoxedProduct& other) : Product(other), weight(other.weight), location(other.location) {
        cout << "BoxedProduct " << other.productName << " copied." << endl;
    }

    //destructor
    BoxedProduct::~BoxedProduct() {
        cout << "BoxedProduct " << productName << " destroyed." << endl;
    }

    //member functions
    //delivery charge based on weight
    //very basic, if weight <= 5kg, charge $5, if weight <= 20kg, charge $10, else charge $20.
    //this is a basic example using practically random values.
    double BoxedProduct::deliveryCharge() const {
        if (weight <= 5.0) return 5.0;
        else if (weight <= 20.0) return 10.0;
        else return 20.0;
    }

    //display information about the boxed product, calls the base class displayInfo
    //adds weight and delivery charge
    void BoxedProduct::displayInfo() const {
        Product::displayInfo();
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Delivery Charge: $" << deliveryCharge() << endl;
        location.displayLocation();
    }