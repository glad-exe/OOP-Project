// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Supplier.h"

    char* Supplier::copyString(const char* original){
        if(!original) original = "";
        int len = 0;
        while(original[len] != '\0') len++;

        char* temp = new char[len + 1];
        for(int i = 0; i < len; i++) temp[i] = original[i];

        temp[len] = '\0';
        return temp;
    }

    Supplier::Supplier(const char* name = "", const char* phone = "", const char* address = "", int* codes = nullptr) {
        supplierName = copyString(name);
        supplierPhone = copyString(phone);
        supplierAddress = copyString(address);
        supplierCodes = codes;
    }
    Supplier::Supplier(const Supplier& other) {
        supplierName = copyString(other.supplierName);
        supplierPhone = copyString(other.supplierPhone);
        supplierAddress = copyString(other.supplierAddress);
        supplierCodes = other.supplierCodes;
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

    void Supplier::addSuppliedProduct(int _barcode) {

        
    }

    void Supplier::displayInfo() const {

    }
