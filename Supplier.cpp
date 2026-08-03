// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Supplier.h"
#include "StringUtils.h"
#include<iostream>

    //same idea as copyString, but for the barcode list. counts up to the -1 at the end
    int* Supplier::copyIntArr(const int* original){
        int len = 0;
        while(original[len] != -1) len++;

        int* temp = new int[len + 1];
        for(int i = 0; i < len; i++) temp[i] = original[i];

        temp[len] = -1;
        return temp;
    }

    //CONSTRUCTORS
    //defualt para
    Supplier::Supplier(const char* name, const char* phone, const char* address, int* codes) {
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
    //copy constructor
    Supplier::Supplier(const Supplier& other) {
        supplierName = copyString(other.supplierName);
        supplierPhone = copyString(other.supplierPhone);
        supplierAddress = copyString(other.supplierAddress);
        supplierCodes = copyIntArr(other.supplierCodes);
    }
    //destructor
    Supplier::~Supplier() {
        delete[] supplierName;
        delete[] supplierPhone;
        delete[] supplierAddress;
        delete[] supplierCodes;
    }

    //SETTERS

    Supplier& Supplier::setSupplierName    (const char* name) {
        delete[] supplierName;
        supplierName = copyString(name);
        return *this;
    }

    Supplier& Supplier::setSupplierPhone   (const char* phone) {
        delete[] supplierPhone;
        supplierPhone = copyString(phone);
        return *this;
    }

    Supplier& Supplier::setSupplierAddress (const char* address) {
        delete[] supplierAddress;
        supplierAddress = copyString(address);
        return *this;
    }
    
    Supplier& Supplier::setSupplierCodes   (int* codes) {
        delete[] supplierCodes;
        supplierCodes = copyIntArr(codes);
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

    // displays the info
    void Supplier::displayInfo() const {
        std::cout << "Name    : " << supplierName << std::endl;
        std::cout << "Phone   : " << supplierPhone << std::endl;
        std::cout << "Address : " << supplierAddress << std::endl;
        std::cout << "Codes   : " << std::endl;

        int i = 0;
        while(supplierCodes[i] != -1){
            std::cout << supplierCodes[i] << " ";
            i++;
        }
        std::cout << std::endl;
    }
