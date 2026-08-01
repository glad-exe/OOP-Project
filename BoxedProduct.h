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
    
    
    ~BoxedProduct(){
        
    }

};    

