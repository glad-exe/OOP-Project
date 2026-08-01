// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "DigitalProduct.h"
using namespace std;

    //copies text into new memory
    char* DigitalProduct::copyText(const char* source){
        int len = 0;
        while(source[len] != '\0') len++;

        char* temp = new char[len + 1];
        for(int i = 0; i < len; i++){
            temp[i] = source[i];
        }
        temp[len] = '\0';

        return temp;
    }

    DigitalProduct::DigitalProduct(double dSize, const char* lKey, int bCode, const char* pName,
        double pPrice, int pStock, const char* pDescription)
        : Product(bCode, pName, pPrice, pStock, pDescription) {

            downloadSize = dSize;
            licenceKey = copyText(lKey);
            cout << "DigitalProduct " << pName << " created." << endl;
    }

    //makes an independent copy
    DigitalProduct::DigitalProduct(const DigitalProduct& og)
        : Product(og) {

            downloadSize = og.downloadSize;
            licenceKey = copyText(og.licenceKey);
            cout << "DigitalProduct copied." << endl;
    }

    DigitalProduct::~DigitalProduct() {
        delete[] licenceKey;
        cout << "DigitalProduct destroyed." << endl;
    }

    double DigitalProduct::deliveryCharge() const {
        return 0.0;
    }

    void DigitalProduct::displayInfo() const {
        Product::displayInfo();
        cout << "Download Size: " << downloadSize << " MB" << endl;
        cout << "Licence Key: " << licenceKey << endl;
    }
