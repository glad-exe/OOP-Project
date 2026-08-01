#include "Product.h"
class PerishableProduct : public Product{
    private:
        double storageTemperature;
        int    daysUntilExpiration;
    public:
        //Constructors
        //Default parametrized constructor
        PerishableProduct(int bCode = 0, const char* pName = "", double pPrice = 0.0, int pStock = 0, 
            const char* pDescription = "", double sTemp = 0.0, int dUntilExp = 0);

        //Copy constructor
        PerishableProduct(const PerishableProduct& og);

        //Destructor
        ~PerishableProduct();

        //member functions
        bool   hasExpired()    const;
        double deliveryCharge() const;
        void   displayInfo()    const;
};