// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Order.h"
#include "StringUtils.h"
#include "Product.h"
#include "Inventory.h"

#include <iostream>

using namespace std;

Order::Order(int num, const char* name, Product* cart) : orderNumber(num), customerName(copyString(name)) {
    itemCapacity = 4;
    itemCount = 0;
    itemProducts = new Product*[itemCapacity];
    itemQuantities = new int[itemCapacity];
    cout << "Order " << orderNumber << " created." << endl;
}

// my pride and joy. due to them being pointer arrays, theres no need to actually copy ANY info
// i thought this would be bad, cause its not a deep copy, but this is exactly how it should work.
// think about it! if a site owner changes a product, it should change for everyones carts.
Order::Order(const Order& other) : orderNumber(other.orderNumber) {
    
    customerName = copyString(other.customerName);
    itemCapacity = other.itemCapacity;
    itemCount = other.itemCount;
    
    itemProducts = new Product*[itemCapacity];
    itemQuantities = new int[itemCapacity];
    
    for (int i = 0; i < itemCount; i++) {
        itemProducts[i] = other.itemProducts[i]; 
        itemQuantities[i] = other.itemQuantities[i];
    }
    cout << "Order " << orderNumber << " copied." << endl;
}

Order::~Order() {
    delete[] customerName;
    delete[] itemProducts;
    delete[] itemQuantities;
    cout << "Order " << orderNumber << "destroyed.";
}

void   Order::grow() {
    int newCapacity = itemCapacity * 2;
    Product** newProducts = new Product*[newCapacity];
    int* newQuantities = new int[newCapacity];

    for (int i = 0; i < itemCount; i++) {
        newProducts[i] = itemProducts[i];
        newQuantities[i] = itemQuantities[i];
    }

    delete[] itemProducts;
    delete[] itemQuantities;
    itemProducts = newProducts;
    itemQuantities = newQuantities;
    itemCapacity = newCapacity;
}

void   Order::addItem(Product* p, int quantity) {
    if (itemCount >= itemCapacity) grow();
    itemProducts[itemCount] = p;
    itemQuantities[itemCount] = quantity;
    itemCount++;
}

Order  Order::mergeWith(const Order& other) {

}

bool   Order::complete(Inventory& inv) {
    
}

double Order::total() {
    double sum = 0.0;
    for (int i = 0; i < itemCount; i++) {
        sum += itemProducts[i]->getPrice() * itemQuantities[i];
    }
    return sum;
}

void   Order::displayOrder() {
    cout << "Order " << orderNumber << " - " << customerName << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << "  " << itemProducts[i]->getProductName()
             << " x" << itemQuantities[i] << endl;
    }
    cout << "Total: " << total() << endl;
}