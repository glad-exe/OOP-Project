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
    Product(int bCode, const char* pName, double pPrice, int pStock, const char* pDescription);
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