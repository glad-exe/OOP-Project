// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Order.h"
#include "Product.h"
#include "Inventory.h"

char* Order::copyString(const char* original){
    if(!original) original = "";
    int len = 0;
    while(original[len] != '\0') len++;

    char* temp = new char[len + 1];
    for(int i = 0; i < len; i++) temp[i] = original[i];

    temp[len] = '\0';
    return temp;
}
int Order::getOrderNumber() const {return orderNumber;}

Order::Order(int num, const char* name, Product* cart) : orderNumber(num), customerName(copyString(name)) {
    
}
Order::Order(const Order* other) : orderNumber(other->getOrderNumber()){
    customerName = copyString(other->customerName);


}

Order::~Order() {

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