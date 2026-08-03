// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef ORDER_H
#define ORDER_H

#include "Product.h"
#include "Inventory.h"

class Order {
    private:
        const int orderNumber;     // Fingerprint for the order number.
        char*     customerName;    // COPYSTRING POTENTIAL?
        Product** itemProducts;    // array of pointers to products.
        int*      itemQuantities;
        int       itemCount;
        int       itemCapacity;

        void      grow();           // doubles capacity when full

    public:

        //ASSIGNMENT OP DELETION
        Order& operator=(const Order& other) = delete;


        //CONSTRUCTORS
        //default parametrized
        Order(int num = 0, const char* name = "", Product* _items = nullptr);

        //copy
        Order(const Order& other);

        //destructor
        ~Order();

        //getters
        int       getOrderNumber() const;
        Product** getItemProducts()    const;
        char*     getCustomerName()    const;
        int*      getItemQuantities()  const;
        int       getItemCount()       const;

        //member funcs
        void      addItem(Product* p, int quantity);
        Order     mergeWith(const Order& other);
        bool      complete(Inventory& inv);
        double    total();
        void      displayOrder();
        

        friend class DailyReport;

};

#endif