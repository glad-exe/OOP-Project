#ifndef SUPPLIER_H
#define SUPPLIER_H

class Supplier {
    private:
        char*  supplierName;
        char*  supplierPhone;
        char*  supplierAddress;
        int*   supplierCodes;
    public:
        Supplier(const char* name = "", const char* phone = "", const char* address = "", int* codes = nullptr);
        Supplier(const Supplier& other);
        ~Supplier();
        //SETTERS
        Supplier& setSupplierName      (const char* name);
        Supplier& setSupplierPhone     (const char* phone);
        Supplier& setSupplierAddress   (const char* address);
        Supplier& setSupplierCodes     (int* codes);
        //GETTERS
        const char* getSupplierName    ()  const;
        const char* getSupplierPhone   () const;
        const char* getSupplierAddress () const;
        int*        getSupplierCodes   () const;

        //MEMBER FUNCTIONS

        //Utility function to copy a string, originally in Product class.
        char* copyString(const char* original);

        //Function to add a supplied product's barcode to the supplier's list of codes.
        void  addSuppliedProduct(int _barcode);

        //Function to display supplier information.
        void  displayInfo() const;
};

#endif