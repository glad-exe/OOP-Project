// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"

class Inventory{
    private:
        Product*  shelf[50];      // shelf is always 50, never changes
        int       shelfCount;     // how many are used at the moment
        Product** warehouse;      // size given when program starts
        int       warehouseSize;  // max size of warehouse
        int       warehouseCount; // how many are used

    public:
        //CONSTRUCTOR
        Inventory(int size);

        //DESTRUCTOR
        ~Inventory();

        //member funcions
        void      addProduct(Product* product, bool toShelf = true);
        void      removeByBarcode(int barcode);
        Product*  findByBarcode(int barcode) const;
        Product*  findByName(const char* name) const;
        void      listShelf() const;
        double    sellableStockValue() const;

        friend class DailyReport;
};

#endif
