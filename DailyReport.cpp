// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "DailyReport.h"
#include "Inventory.h"
#include "Order.h"

    //CONSTRUCTORS

    //Default constructor
    DailyReport::DailyReport(){
        std::cout << "Daily Report created." << std::endl;
    }

    //DESTRUCTOR
    DailyReport::~DailyReport(){
        std::cout << "Daily Report destroyed." << std::endl;
    }

    //member functions

    //goes through every order and checks if the items still match the inventory
    void DailyReport::generate(Inventory& inv, Order** orders, int orderCount){

        std::cout << "Daily report: " << std::endl;

        for(int i = 0; i < orderCount; i++){

            std::cout << "Order number" << orders[i]->getOrderNumber() << " - " << orders[i]->getCustomerName() << std::endl;

            for(int j = 0; j < orders[i]->getItemCount(); j++){

                Product* p = orders[i]->getItemProducts()[j];
                int qty = orders[i]->getItemQuantities()[j];
                bool found = false;

                for(int s = 0; s < inv.shelfCount; s++){
                    if(inv.shelf[s]->isSameItem(*p)) found = true;
                }
                for(int w = 0; w < inv.warehouseCount; w++){
                    if(inv.warehouse[w]->isSameItem(*p)) found = true;
                }

                if(found == false){
                    std::cout << "Mismatch : " << p->getProductName() << " ( " << qty << ") was ordered but not found." << std::endl;
                }
            }
        }
        std::cout << "End of report" << std::endl;
    }
