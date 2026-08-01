// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
using namespace std;
#include <cstring>
class Product{
    private:
        const int barcode;
        char* productName;
        double price;
        int inStock;
        char* description;
        static int productCount;
        char* copyString(const char* original);

    public:

    //CONSTRUCTORS
    //Default constructor
    Product(int bCode = 0, const char* pName = "", double pPrice = 0.0, int pStock = 0, const char* pDescription = "");
    //Copy Constructor
    Product(const Product& og);

    //DESTRUCTOR
    virtual ~Product();

    //SETTERS
    Product& setPrice(int tempPrice);
    Product& setStock(int tempStock);
    Product& setName(const char* newName) {
        delete[] productName;
        productName = copyString(newName);
        return *this; 
    }

    //member functions
    void addStock(int tempStock = 1);
    bool isSameItem(const Product& other) const;
    double totalStockValue() const;
    void displayInfo() const;

};