// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "Inventory.h"
#include "PerishableProduct.h"
#include "StringUtils.h"


    //CONSTRUCTOR
    Inventory::Inventory(int size){
        warehouseSize = size;
        warehouseCount = 0;
        shelfCount = 0;

        for(int i = 0; i < 50; i++) shelf[i] = 0;

        warehouse = new Product*[warehouseSize];
        for(int i = 0; i < warehouseSize; i++) warehouse[i] = 0;

        std::cout << "Inventory created." << std::endl;
    }

    //DESTRUCTOR
    Inventory::~Inventory(){
        for(int i = 0; i < shelfCount; i++) delete shelf[i];
        for(int i = 0; i < warehouseCount; i++) delete warehouse[i];
        delete[] warehouse;

        std::cout << "Inventory destroyed." << std::endl;
    }

    //member funcions

    //adds a product to shelf, or warehouse if toShelf is false
    bool Inventory::addProduct(Product* product, bool toShelf){
        if(toShelf){
            if(shelfCount >= 50){
                std::cout << "shelf is full, cant add no more." << std::endl;
                return false;
            }
            shelf[shelfCount] = product;
            shelfCount++;
        }
        else{
            if(warehouseCount >= warehouseSize){
                std::cout << "warehouse full, cant add no more." << std::endl;
                return false;
            }
            warehouse[warehouseCount] = product;
            warehouseCount++;
        }
        return true;
    }

    //removes product by its barcode
    void Inventory::removeByBarcode(int barcode){
        for(int i = 0; i < shelfCount; i++){
            if(shelf[i]!= 0 && shelf[i]->getBarcode() == barcode){
                delete shelf[i];
                for(int j = i; j < shelfCount - 1; j++) shelf[j] = shelf[j + 1];
                shelfCount--;
                shelf[shelfCount] = 0;
                return;
            }
        }

        for(int i = 0; i < warehouseCount; i++){
            if(warehouse[i] != 0 && warehouse[i]->getBarcode() == barcode){
                delete warehouse[i];
                for(int j = i; j < warehouseCount - 1; j++) warehouse[j] = warehouse[j + 1];
                warehouseCount--;
                warehouse[warehouseCount] = 0;
                return;
            }
        }

        std::cout << "barcode not found, sorry." << std::endl;
    }

    //finds product by barcode
    Product* Inventory::findByBarcode(int barcode) const{
        for(int i = 0; i < shelfCount; i++){
            if(shelf[i] != 0 && shelf[i]->getBarcode() == barcode) return shelf[i];
        }
        for(int i = 0; i < warehouseCount; i++){
            if(warehouse[i] != 0 && warehouse[i]->getBarcode() == barcode) return warehouse[i];
        }
        return 0;
    }

    //finds product by its name
    Product* Inventory::findByName(const char* name) const{
        if(name == 0) return 0;
        for(int i = 0; i < shelfCount; i++){
            if(shelf[i] != 0 && sameText(shelf[i]->getProductName(), name)) return shelf[i];
        }
        for(int i = 0; i < warehouseCount; i++){
            if(warehouse[i] != 0 && sameText(warehouse[i]->getProductName(), name)) return warehouse[i];
        }
        return 0;
    }

    //prints everything thats on the shelf rn
    void Inventory::listShelf() const{
        for(int i = 0; i < shelfCount; i++){
            if(shelf[i] != 0) shelf[i]->displayInfo();
        }
    }

    //adds up value of stock that didnt expire yet
    double Inventory::sellableStockValue() const{
        double total = 0.0;

        for(int i = 0; i < shelfCount; i++){
            if(shelf[i] == 0) continue;
            PerishableProduct* per = dynamic_cast<PerishableProduct*>(shelf[i]);
            if(per != 0 && per->hasExpired()) continue;
            total += shelf[i]->totalStockValue();
        }

        for(int i = 0; i < warehouseCount; i++){
            if(warehouse[i] == 0) continue;
            PerishableProduct* per = dynamic_cast<PerishableProduct*>(warehouse[i]);
            if(per != 0 && per->hasExpired()) continue;
            total += warehouse[i]->totalStockValue();
        }

        return total;
    }
