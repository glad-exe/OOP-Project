// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include "ShelfLocation.h"
#include <iostream>
    
ShelfLocation::ShelfLocation() = default;
char ShelfLocation::getAisle() {return aisle;}
int ShelfLocation::getSlot() {return slot;}

void ShelfLocation::displayLocation() const {
    std::cout << "Aisle: " << aisle << ", Slot: " << slot << std::endl;
}
