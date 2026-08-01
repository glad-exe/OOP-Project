#include "Supplier.h"

    char* Supplier::copyString(const char* original){
        if(!original) original ="";
        int len = 0;
        while(original[len]!='\0') len++;

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

    // Setters
    Supplier& Supplier::setSupplierName    (const char* name) {


    }

    Supplier& Supplier::setSupplierPhone   (const char* phone) {

    }

    Supplier& Supplier::setSupplierAddress (const char* address) {

    }

    Supplier& Supplier::setSupplierCodes   (int* codes) {

    }

    // Getters
    const char* Supplier::getSupplierName  ()  const {

    }
    const char* Supplier::getSupplierPhone  () const {

    }

    const char* Supplier::getSupplierAddress() const {

    }

    int*        Supplier::getSupplierCodes  () const {

    }

    void Supplier::addSuppliedProduct(int _barcode) {

    }

    void Supplier::displayInfo() const {

    }
