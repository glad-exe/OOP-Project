// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef DAILY_H
#define DAILY_H
#include "Order.h"
#include "Inventory.h"
class DailyReport{
    public:
        // THERE IS NO WAAAAAAY THIS IS DONE WHAAAAAAAAAAAAAT
        //CONSTRUCTORS
        //Default constructor
        DailyReport();

        //DESTRUCTOR
        ~DailyReport();

        //member functions
        void generate(Inventory& inv, Order orders[], int orderCount);
};
#endif