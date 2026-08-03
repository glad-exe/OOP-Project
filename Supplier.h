// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#ifndef SUPPLIER_H
#define SUPPLIER_H

class Supplier {
    private:
        char*  supplierName;    //Supplier name, stored as a dynamically allocated C-style string.
        char*  supplierPhone;   //Phone number of the supplier, stored as a dynamically allocated C-style string.
        char*  supplierAddress; //Supplier address, stored as a dynamically allocated C-style string.
        int*   supplierCodes;   //Int list of every barcode this supplier uses, ends with a -1.
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
        const char* getSupplierName    () const;
        const char* getSupplierPhone   () const;
        const char* getSupplierAddress () const;
        int*        getSupplierCodes   () const;

        Supplier& operator=(const Supplier& other) = delete;
        //MEMBER FUNCTIONS
        //copies the barcode list, counts up to the -1 at the end
        int* copyIntArr(const int* original);

        //Function to add a supplied product's barcode to the supplier's list of codes.
        void  addSuppliedProduct(int _barcode);

        //Function to display supplier information.
        void  displayInfo() const;
};

#endif
