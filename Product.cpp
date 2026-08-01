#include<iostream>
#include "Product.h"
using namespace std;

    int Product::productCount = 0;

    char* Product::copyString(const char* original){
        if(!original) original ="";
        int len = 0;
        while(original[len]!='\0') len++;

        char* temp = new char[len + 1];
        for(int i = 0; i < len; i++) temp[i] = original[i];

        temp[len] = '\0';
        return temp;
    }

    //CONSTRUCTORS
    
    //Default constructor
    Product::Product(int bCode, const char* pName, double pPrice, int pStock, const char* pDescription)
    :barcode(bCode), price(pPrice), inStock(pStock){
        productName = copyString(pName);
        description = copyString(pDescription);
        productCount++;
        cout << "Product " << productName << " created." << endl;
    }

    //Copy Constructor
    Product::Product(const Product& og): barcode(og.barcode), price(og.price), inStock(og.inStock){
        productName = copyString(og.productName);
        description = copyString(og.description);
        productCount++;
        cout << "Product " << productName << " created." << endl;
    }

    //DESTRUCTOR
    Product::~Product(){
        cout << "Product " << productName << " destroyed." << endl;
        delete[] productName;
        delete[] description;
        productCount--;
    }

    //SETTERS

    //price
    Product& Product::setPrice(int tempPrice){
        if(tempPrice >= 0) price=tempPrice;
        else cout << "Negative price not allowed." << endl ;
        return *this;
    }

    //stock
    Product& Product::setStock(int tempStock){
        if(tempStock>=0) inStock=tempStock;

        else cout << "Negative stock not allowed." << endl;
        return *this;
    }

    //name
    Product& Product::setName(const char* newName) {
        delete[] productName;
        productName = copyString(newName);
        
        return *this; 
    }

    //MEMBER FUNCTIONS

    //add stock
    void Product::addStock(int tempStock){
        if(tempStock>=0)inStock+=tempStock;
        else cout << "Negative stock not allowed." << endl;
    }

    //compare
    bool Product::isSameItem(const Product& other) const { return barcode==other.barcode; }

    //total stock value
    double Product::totalStockValue() const { return (price*inStock); }

    //display info
    void Product::displayInfo() const {
        cout << "Barcode: " << barcode << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Price: " << price << endl;
        cout << "In Stock: " << inStock << endl;
        cout << "Description: " << description << endl;
    }