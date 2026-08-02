// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "DailyReport.h"
#include "Inventory.h"
#include "Order.h"
using namespace std;
    //Default constructor
    DailyReport::DailyReport(){
        cout << "DailyReport created." << endl;
    }

    //DESTRUCTOR
    DailyReport::~DailyReport(){
        cout << "DailyReport destroyed." << endl;
    }

    //member functions

    //goes through every order and checks if the items still match the inventory
    void DailyReport::generate(Inventory& inv, Order orders[], int orderCount){

        cout << "eND OF DAY REPORT" << endl;

        for(int i = 0; i < orderCount; i++){

            cout << "Order nimber" << orders[i].orderNumber << " - " << orders[i].customerName << endl;

            for(int j = 0; j < orders[i].itemCount; j++){

                Product* p = orders[i].items[j].product;
                int qty = orders[i].items[j].quantity;
                bool found = false;

                //check the shelf
                for(int s = 0; s < inv.shelfCount; s++){
                    if(inv.shelf[s]->isSameItem(*p)) found = true;
                }

                //check the warehouse
                for(int w = 0; w < inv.warehouseCount; w++){
                    if(inv.warehouse[w]->isSameItem(*p)) found = true;
                }

                //if it was not found anywhere, print a mismatch
                if(found == false){
                    cout << "mismatch : " << p->getProductName() << " (qty " << qty << ") was ordered but not found." << endl;
                }
            }
        }

        cout << "End of report" << endl;
    }
