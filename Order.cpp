// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Order.h"
#include "Product.h"
#include "Inventory.h"
#include "StringUtils.h"

int Order::getOrderNumber() const {return orderNumber;}

Order::Order(int num, const char* name, Product* cart) : orderNumber(num), customerName(copyString(name)) {
    
}
Order::Order(const Order& other) : orderNumber(other.orderNumber){
    customerName = copyString(other.customerName);


}

Order::~Order() {
    delete[] customerName;
    delete[] items;
    cout << "Order " << orderNumber << "destroyed.";
}

void   Order::addItem(Product p, int quantity) {

}

Order  Order::mergeWith(Order other) {

}

void   Order::complete(Inventory i) {

}

double Order::total() {

}

void   Order::displayOrder() {

}