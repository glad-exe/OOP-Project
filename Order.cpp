// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Order.h"
#include "StringUtils.h"
#include "Product.h"
#include "Inventory.h"

#include <iostream>

using namespace std;

Order::Order(int num, const char* name) : orderNumber(num), customerName(copyString(name)) {
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
//Destructor
//frees up all dynamically allocated memory.
Order::~Order() {
    delete[] customerName;
    delete[] itemProducts;
    delete[] itemQuantities;
    cout << "Order " << orderNumber << "destroyed.";
}

// GETTERS
int        Order::getOrderNumber()    const { return orderNumber; }
Product**  Order::getItemProducts()   const {return itemProducts;}
int*       Order::getItemQuantities() const {return itemQuantities;}
char*      Order::getCustomerName()   const {return customerName;}
int        Order::getItemCount()      const { return itemCount; }

// I was gonna rewrite std::vector but i started the project too late for that.
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

//adds an item to an product array.
void   Order::addItem(Product* p, int quantity) {
    for (int i = 0; i < itemCount; i++) {
        if (itemProducts[i]->getBarcode() == p->getBarcode()) {
            itemQuantities[i] += quantity; 
            return; 
        }
    }
    if (itemCount >= itemCapacity) grow();
    itemProducts[itemCount] = p;
    itemQuantities[itemCount] = quantity;
    itemCount++;
}

Order   Order::mergeWith(const Order& other) {
    if (!sameText(customerName, other.customerName)) {
        cout << "Can not merge two orders from different customers." << endl;
        return *this;
    }

    Order merged(this->orderNumber, customerName);

    for (int i = 0; i < itemCount; i++) {
        merged.addItem(itemProducts[i], itemQuantities[i]);
    }
    for (int i = 0; i < other.itemCount; i++) {
        merged.addItem(other.itemProducts[i], other.itemQuantities[i]);
    }

    return merged;
}

bool   Order::complete(Inventory& inv) {
    // first pass checks if everything is available
    for (int i = 0; i < itemCount; i++) {
        Product* p = inv.findByBarcode(itemProducts[i]->getBarcode());
        if (p == 0 || p->getStock() < itemQuantities[i]) {
            return false;
        }
    }
    // second pass completes the order
    for (int i = 0; i < itemCount; i++) {
        Product* p = inv.findByBarcode(itemProducts[i]->getBarcode());
        p->setStock(p->getStock() - itemQuantities[i]);
    }

    return true;
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
