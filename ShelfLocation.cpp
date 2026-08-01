#include "ShelfLocation.h"
#include <iostream>
    
    ShelfLocation::ShelfLocation() = default;
    char ShelfLocation::getAisle() {return aisle;}
    int ShelfLocation::getSlot() {return slot;}

    void ShelfLocation::displayLocation() {
        std::cout << "Aisle: " << aisle << ", Slot: " << slot << std::endl;
    }
