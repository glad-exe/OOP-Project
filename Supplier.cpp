// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Supplier.h"
#include "StringUtils.h"
#include<iostream>
using namespace std;
    //Same old helper function as in Product class. Just copied here to avoid any issues with inheritance and access specifiers.
    //see also: store.cpp, digitalproduct.cpp, label.cpp


    //same idea as copyString, but for the barcode list. counts up to the -1 at the end
    int* Supplier::copyIntArr(const int* original){
        int len = 0;
        while(original[len] != -1) len++;

        int* temp = new int[len + 1];
        for(int i = 0; i < len; i++) temp[i] = original[i];

        temp[len] = -1;
        return temp;
    }

    Supplier::Supplier(const char* name = "", const char* phone = "", const char* address = "", int* codes = nullptr) {
        supplierName = copyString(name);
        supplierPhone = copyString(phone);
        supplierAddress = copyString(address);

        if(codes == nullptr){
            supplierCodes = new int[1];
            supplierCodes[0] = -1;
        }
        else{
            supplierCodes = copyIntArr(codes);
        }
    }
    Supplier::Supplier(const Supplier& other) {
        supplierName = copyString(other.supplierName);
        supplierPhone = copyString(other.supplierPhone);
        supplierAddress = copyString(other.supplierAddress);
        supplierCodes = copyIntArr(other.supplierCodes);
    }
    Supplier::~Supplier() {
        delete[] supplierName;
        delete[] supplierPhone;
        delete[] supplierAddress;
        delete[] supplierCodes;
    }

    //SETTERS
    Supplier& Supplier::setSupplierName    (const char* name) {
        supplierName = copyString(name);
        return *this;
    }
    Supplier& Supplier::setSupplierPhone   (const char* phone) {
        supplierPhone = copyString(phone);
        return *this;
    }
    Supplier& Supplier::setSupplierAddress (const char* address) {
        supplierAddress = copyString(address);
        return *this;
    }
    Supplier& Supplier::setSupplierCodes   (int* codes) {
        supplierCodes = codes;
        return *this;
    }

    //GETTERS
    const char* Supplier::getSupplierName   () const { return supplierName; }
    const char* Supplier::getSupplierPhone  () const { return supplierPhone; }
    const char* Supplier::getSupplierAddress() const { return supplierAddress; }
    int*        Supplier::getSupplierCodes  () const { return supplierCodes; }

    //grows the codes list by 1 and puts the new barcode right before the -1
    void Supplier::addSuppliedProduct(int _barcode) {
        int len = 0;
        while(supplierCodes[len] != -1) len++;

        int* temp = new int[len + 2];
        for(int i = 0; i < len; i++) temp[i] = supplierCodes[i];
        temp[len] = _barcode;
        temp[len + 1] = -1;

        delete[] supplierCodes;
        supplierCodes = temp;
    }
    // displys the info
    void Supplier::displayInfo() const {
        cout << "Name   : " << supplierName << endl;
        cout << "Phone  : " << supplierPhone << endl;
        cout << "Address: " << supplierAddress << endl;
        cout << "Codes  : ";

        int i = 0;
        while(supplierCodes[i] != -1){
            cout << supplierCodes[i] << " ";
            i++;
        }
        cout << endl;
    }
