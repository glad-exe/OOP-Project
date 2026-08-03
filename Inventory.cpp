// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "Inventory.h"
#include "PerishableProduct.h"
#include "StringUtils.h"
using namespace std;

    //CONSTRUCTOR
    Inventory::Inventory(int size){
        warehouseSize = size;
        warehouseCount = 0;
        shelfCount = 0;

        for(int i = 0; i < 50; i++) shelf[i] = 0;

        warehouse = new Product*[warehouseSize];
        for(int i = 0; i < warehouseSize; i++) warehouse[i] = 0;

        cout << "Inventory created." << endl;
    }

    //DESTRUCTOR
    Inventory::~Inventory(){
        for(int i = 0; i < shelfCount; i++) delete shelf[i];
        for(int i = 0; i < warehouseCount; i++) delete warehouse[i];
        delete[] warehouse;

        cout << "Inventory destroyed." << endl;
    }

    //member funcions

    //adds a product to shelf, or warehouse if toShelf is false
    void Inventory::addProduct(Product* product, bool toShelf){
        if(toShelf){
            if(shelfCount >= 50){
                cout << "shelf is full, cant add no more." << endl;
                return;
            }
            shelf[shelfCount] = product;
            shelfCount++;
        }
        else{
            if(warehouseCount >= warehouseSize){
                cout << "warehouse full, cant add no more." << endl;
                return;
            }
            warehouse[warehouseCount] = product;
            warehouseCount++;
        }
    }

    //removes product by its barcode
    //needs to be fixed, because it doesnt delete the product from memory, just from the array
    void Inventory::removeByBarcode(int barcode){
        for(int i = 0; i < shelfCount; i++){
            if(shelf[i]->getBarcode() == barcode){
                delete shelf[i];
                for(int j = i; j < shelfCount - 1; j++) shelf[j] = shelf[j + 1];
                shelfCount--;
                shelf[shelfCount] = 0;
                return;
            }
        }

        for(int i = 0; i < warehouseCount; i++){
            if(warehouse[i]->getBarcode() == barcode){
                delete warehouse[i];
                for(int j = i; j < warehouseCount - 1; j++) warehouse[j] = warehouse[j + 1];
                warehouseCount--;
                warehouse[warehouseCount] = 0;
                return;
            }
        }

        cout << "barcode not found, sorry." << endl;
    }

    //finds product by barcode
    Product* Inventory::findByBarcode(int barcode) const{
        for(int i = 0; i < shelfCount; i++){
            if(shelf[i]->getBarcode() == barcode) return shelf[i];
        }
        for(int i = 0; i < warehouseCount; i++){
            if(warehouse[i]->getBarcode() == barcode) return warehouse[i];
        }
        return 0;
    }

    //finds product by its name
    Product* Inventory::findByName(const char* name) const{
        for(int i = 0; i < shelfCount; i++){
            if(sameText(shelf[i]->getProductName(), name)) return shelf[i];
        }
        for(int i = 0; i < warehouseCount; i++){
            if(sameText(warehouse[i]->getProductName(), name)) return warehouse[i];
        }
        return 0;
    }

    //prints everything thats on the shelf rn
    void Inventory::listShelf() const{
        for(int i = 0; i < shelfCount; i++){
            shelf[i]->displayInfo();
        }
    }

    //adds up value of stock that didnt expire yet
    double Inventory::sellableStockValue() const{
        double total = 0.0;

        for(int i = 0; i < shelfCount; i++){
            PerishableProduct* per = dynamic_cast<PerishableProduct*>(shelf[i]);
            if(per != 0 && per->hasExpired()) continue;
            total += shelf[i]->totalStockValue();
        }

        for(int i = 0; i < warehouseCount; i++){
            PerishableProduct* per = dynamic_cast<PerishableProduct*>(warehouse[i]);
            if(per != 0 && per->hasExpired()) continue;
            total += warehouse[i]->totalStockValue();
        }

        return total;
    }
