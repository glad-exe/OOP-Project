// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "Inventory.h"
#include "PerishableProduct.h"
using namespace std;

    //checks if 2 strings are the smae
    bool Inventory::sameText(const char* a, const char* b) const{
        int i = 0;
        while(a[i] != '\0' && b[i] != '\0'){
            if(a[i] != b[i]) return false;
            i++;
        }
        return a[i] == '\0' && b[i] == '\0';
    }

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
    void Inventory::removeByBarcode(int barcode){
    }

    //finds product by barcode
    Product* Inventory::findByBarcode(int barcode) const{
        //idk how to do this one
    }

    //finds product by its name
    Product* Inventory::findByName(const char* name) const{
        //idk how to do this one either
    }

    //prints everything thats on the shelf rn
    void Inventory::listShelf() const{
    }

    //adds up value of stock that didnt expire yet
    double Inventory::sellableStockValue() const{

        return total;
    }
