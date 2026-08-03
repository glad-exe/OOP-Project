// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
using namespace std;
class Product{
    // protected so that we can use it in ther classes.
    // inheritance is used in DigitalProduct, BoxedProduct, PerishableProduct classes.
    protected:

        const int  barcode;      // Unique identifier for the product, assigned at the time of product creation and cannot be changed later.
        char*      productName;  // Name of the product, stored as a dynamically allocated C-style string.
        double     price;        // Price of the product in the store's currency.
        int        inStock;      // Quantity of the product currently available in stock.
        char*      description;  // Description of the product, stored as a dynamically allocated C-style string.
        static int productCount; // Static member variable to keep track of the total number of Product instances created. It is shared among all instances of the Product class.
        
        public:
        //ASSIGNMENT OP DELETION HOW DID WE FORGET THAT
        Product& operator=(const Product& og) = delete;
        //CONSTRUCTORS
        //Default constructor
        Product(int bCode = 0, const char* pName = "", double pPrice = 0.0, int pStock = 0, const char* pDescription = "");
        //Copy Constructor
        Product(const Product& og);
        
        //DESTRUCTOR
        virtual ~Product();
        
        //SETTERS
        Product& setPrice       (double      tempPrice);
        Product& setStock       (int         tempStock);
        Product& setName        (const char* newName);
        Product& setDescription (const char* newDescription);

        //GETTERS
        int         getBarcode()     const;
        const char* getProductName() const;
        double      getPrice()       const;
        int         getStock()       const;
        const char* getDescription() const;
        
        //member functions

        void           addStock(int tempStock = 1);
        
        bool           isSameItem(const Product& other) const;
        double         totalStockValue()                const;
        virtual void   displayInfo()                    const;

        static int     getProductCount();
};
#endif