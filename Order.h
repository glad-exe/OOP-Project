// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef ORDER_H
#define ORDER_H

class Order {
    private:
        const int orderNumber; // Fingerprint for the order number.
        char*     customerName; // COPYSTRING POTENTIAL
        Product*  items; //whyyyyyyyyyyyyyyyyyyyyyyyy

    public:
        Order(int num = 0, const char* name = "", Product* cart = nullptr);
        Order(const Order& other);
        ~Order();

        void     addItem(Product p, int quantity);
        Order    mergeWith(Order other);
        void     complete(Inventory i);
        
        int      getOrderNumber() const;
        Product* copyProductArr(const int* original);
        double   total();
        void     displayOrder();



        friend class DailyReport;


};

#endif