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

void growOrders(Order**& orders, int& orderCapacity) {
    int newCapacity = orderCapacity * 2;
    Order** newOrders = new Order*[newCapacity];

    for (int i = 0; i < orderCapacity; i++) {
        newOrders[i] = orders[i];
    }

    delete[] orders;
    orders = newOrders;
    orderCapacity = newCapacity;
}

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
    inv.addProduct(p, false);
    cout << "Product added to warehouse." << endl;
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
    char* name = new char[100];
    cout << "Enter name to search: ";
    cin.ignore();
    cin.getline(name, 100);

    Product* p = inv.findByName(name);
    if (p == 0) {
        cout << "No product found with name " << name << "." << endl;
        return;
    }
    p->displayInfo();
    delete[] name;
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
        delete p;
    }
}

void handleAddSupplier(Supplier& supplier) {

}

void handleStartOrder(Order**& orders, int& orderCount, int& orderCapacity) {
    if (orderCount >= orderCapacity) {
        growOrders(orders, orderCapacity);
    }

    int num;
    char name[100];
    cout << "Enter order number: ";
    cin >> num;
    cin.ignore();
    cout << "Enter customer name: ";
    cin.getline(name, 100);

    orders[orderCount] = new Order(num, name);
    orderCount++;
    cout << "Order number " << num << " started successfully." << endl;
}

void handleAddItemToOrder(Order** orders, int orderCount, Inventory& inv) {

}

void handleMergeOrders(Order**& orders, int& orderCount, int& orderCapacity) {


}

void handleCompleteOrder(Order** orders, int& orderCount, Inventory& inv) {
    int num;
    cout << "Enter order number to complete: ";
    cin >> num;

    int index = -1;
    for (int i = 0; i < orderCount; i++) {
        if (orders[i]->getOrderNumber() == num) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "No order found with number " << num << "." << endl;
        return;
    }

    bool success = orders[index]->complete(inv);

    if (!success) {
        cout << "Order could not be completed because of insufficient stock." << endl;
        return;
    }

    cout << "Order completed successfully." << endl;

    delete orders[index];
    for (int j = index; j < orderCount - 1; j++) {
        orders[j] = orders[j + 1];
    }
    orderCount--;
    orders[orderCount] = 0;
}

void handlePrintSellableStock(Inventory& inv) {
    cout << "Total sellable stock value: " << inv.sellableStockValue() << endl;
}

void handlePrintProductCount() {
    cout << "Total products currently in system: " << Product::getProductCount() << endl;
}

void handlePrintLabels(Inventory& inv) {
    int bCode;
    cout << "Enter barcode to print labels for: ";
    cin >> bCode;

    Product* p = inv.findByBarcode(bCode);
    if (p == 0) {
        cout << "No product found." << endl;
        return;
    }

    Label productLabel(p->getProductName());
    productLabel.printLabel();

    Label shelfLabel("Shelf Location");
    shelfLabel.printLabel();

    Label boxLabel("Delivery Box");
    boxLabel.printLabel();
}

void handlePrintDailyReport(Inventory& inv, Order orders[], int orderCount) {
    DailyReport r;
    r.generate(inv, orders, orderCount);

}

bool handleCloseShop(Store& store) {
    store.closeStore();
    cout << "Shutting down. All memory will be released." << endl;
    return false; 
}

int main() {
    Order** orders = new Order*[4];
    int orderCount = 0;
    
    for(int i = 0; i < orderCount; i++) {
        delete orders[i];
    }
    
}
