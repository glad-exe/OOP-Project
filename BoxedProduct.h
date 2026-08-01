// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "Product.h"
#include "ShelfLocation.h"
class BoxedProduct : public Product
{
private:
    double weight;
    ShelfLocation location;
public:
    BoxedProduct(double weight = 0.0, int bCode = 0, const char* pName = "",
        double pPrice = 0.0, int pStock = 0, const char* pDescription = "");

    ~BoxedProduct();

    double deliveryCharge() const;
    displayInfo();

};    

