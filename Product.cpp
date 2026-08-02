// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "Product.h"
using namespace std;
    int Product::productCount = 0;

    //THE helper function.
    //copies text into new memory
    //Used in Product, DigitalProduct, Supplier, Store, Label classes.
    char* Product::copyString(const char* original){
        if(!original) original = "";
        int len = 0;
        while(original[len] != '\0') len++;

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
    Product& Product::setPrice(double tempPrice){
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
    
    //from this point on, 
    //the setters all use the same pattern of using the copyString helper function
    //to handle dynamic memory allocation and deallocation for string attributes.
    //name
    Product& Product::setName(const char* newName) {
        delete[] productName;
        productName = copyString(newName);
        
        return *this; 
    }

    //description
    Product& Product::setDescription(const char* newDescription) {
        delete[] description;
        description = copyString(newDescription);
        
        return *this;
    }

    //GETTERS
    int         Product::getBarcode()      const { return barcode; }
    const char* Product::getProductName()  const { return productName; }
    double      Product::getPrice()        const { return price; }
    int         Product::getStock()        const { return inStock; }
    const char* Product::getDescription()  const { return description; }
    int         Product::getProductCount() const { return productCount; }

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
        cout << "Barcode      : " << barcode     << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Price        : " << price       << endl;
        cout << "In Stock     : " << inStock     << endl;
        cout << "Description  : " << description << endl;
    }