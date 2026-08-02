// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "BoxedProduct.h"
#include "ShelfLocation.h"
#include <iostream>

    //CONSTRUCTORS
    //Default parametrized constructor
    // Initializes weight to 0.0 and calls the base Product constructor with default values.
    // also initializes the ShelfLocation object using its default constructor.
    BoxedProduct::BoxedProduct(double pWeight, int bCode, const char* pName, 
    double pPrice, int pStock, const char* pDescription)
        :Product(bCode, pName, pPrice, pStock, pDescription), weight(pWeight), location() {
        cout << "BoxedProduct " << pName << " created." << endl;
    }

    //Copy constructor
    // Uses the base Product copy constructor to copy the base class members
    // and also copies the weight and location from the other BoxedProduct object.
    BoxedProduct::BoxedProduct(const BoxedProduct& other) : Product(other), weight(other.weight), location(other.location) {
        cout << "BoxedProduct " << other.productName << " copied." << endl;
    }

    //Destructor
    // Calls the base Product destructor
    // basic, no need to handle anything in heap.
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
        cout << "Weight         : " << weight << "kg" << endl;
        cout << "Delivery Charge: $" << deliveryCharge() << endl;
        location.displayLocation();
    }