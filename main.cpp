#include <iostream>
#include "Store.h"
#include "Inventory.h"
#include "Product.h"
#include "BoxedProduct.h"
#include "PerishableProduct.h"
#include "DigitalProduct.h"
#include "Order.h"
#include "Supplier.h"
#include "Label.h"
#include "ShelfLocation.h"
#include "DailyReport.h"
#include "StringUtils.h"

using namespace std;

Product* promptForNewProduct() {
    int type;
    cout << "Product type - 1: Boxed  2: Perishable  3: Digital: ";
    cin >> type;

    int barcode;
    string name, description;
    double price;
    int stock;

    cout << "Barcode: ";
    cin >> barcode;
    cin.ignore();
    cout << "Name: ";
    getline(cin, name);
    cout << "Price: ";
    cin >> price;
    if (price < 0) { cout << "Price cannot be negative." << endl; return 0; }
    cout << "Stock: ";
    cin >> stock;
    if (stock < 0) { cout << "Stock cannot be negative." << endl; return 0; }
    cin.ignore();
    cout << "Description: ";
    getline(cin, description);

    if (type == 1) {
        double weight;
        cout << "Weight (kg): ";
        cin >> weight;
        return new BoxedProduct(weight, barcode, name.c_str(), price, stock, description.c_str());
    }
    else if (type == 2) {
        double temp; int daysLeft;
        cout << "Storage temperature: ";
        cin >> temp;
        cout << "Days until expiration: ";
        cin >> daysLeft;
        return new PerishableProduct(barcode, name.c_str(), price, stock, description.c_str(), temp, daysLeft);
    }
    else if (type == 3) {
        double size;
        string licence;
        cout << "Download size (MB): ";
        cin >> size;
        cin.ignore();
        cout << "Licence key: ";
        getline(cin, licence);
        return new DigitalProduct(size, licence.c_str(), barcode, name.c_str(), price, stock, description.c_str());
    }

    cout << "Invalid product type." << endl;
    return 0;
}

void handleAddToShelf(Inventory& inv) {
    Product* p = promptForNewProduct();
    if (p == 0) return;
    inv.addProduct(p, true);
    cout << "Product added to shelf." << endl;
}

void handleAddToWarehouse(Inventory& inv) {
    Product* p = promptForNewProduct();
    if (p == 0) return;
    inv.addProduct(p, true);
    cout << "Product added to shelf." << endl;
}

void handleDisplayShelf(Inventory& inv) {
    inv.listShelf();
}

void handleSearchByBarcode(Inventory& inv) {
    int bCode;
    cout << "Enter barcode to search: ";
    cin >> bCode;

    Product* p = inv.findByBarcode(bCode);
    if (p == 0) {
        cout << "No product found with barcode " << bCode << "." << endl;
        return;
    }
    p->displayInfo();
}

void handleSearchByName(Inventory& inv) {
    char* name;
    cout << "Enter barcode to search: ";
    cin.ignore();
    cin.getline(name, 100);

    Product* p = inv.findByName(name);
    if (p == 0) {
        cout << "No product found with barcode " << name << "." << endl;
        return;
    }
    p->displayInfo();
}

void handleRemoveByBarcode(Inventory& inv) {
    int bCode;
    cout << "Enter barcode to search: ";
    cin >> bCode;

    Product* p = inv.findByBarcode(bCode);
    if (p == 0) {
        cout << "No product found with barcode " << bCode << "." << endl;
        return;
    } else {
        cout << "Removing: " << endl;
        p->displayInfo();
        inv.removeByBarcode(bCode);
        delete[] p;
    }
}

void handleAddSupplier(Store& store) {

}
void handleStartOrder(Order orders[], int& orderCount, int maxOrders) {

}

void handleAddItemToOrder(Order orders[], int orderCount, Inventory& inv) {

}

void handleMergeOrders(Order orders[], int orderCount) {

}

void handleCompleteOrder(Order orders[], int orderCount, Inventory& inv) {

}

void handlePrintSellableStock(Store& store) {

}

void handlePrintProductCount() {

}

void handlePrintLabels(Store& store) {

}

void handlePrintDailyReport(Inventory& inv, Order orders[], int orderCount) {

}

bool handleCloseShop(Store& store) {
    store.closeStore();
    cout << "Shutting down. All memory will be released." << endl;
    return false; 
}


