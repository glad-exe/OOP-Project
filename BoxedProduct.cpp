#include "BoxedProduct.h"
#include "ShelfLocation.h"

BoxedProduct::BoxedProduct(double pWeight, int bCode, const char* pName, 
    double pPrice, int pStock, const char* pDescription)
    : Product(bCode, pName, pPrice, pStock, pDescription), weight(pWeight), location() {}