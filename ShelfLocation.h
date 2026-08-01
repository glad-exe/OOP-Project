// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef SHELFLOCATION_H
#define SHELFLOCATION_H
class ShelfLocation {
    private:
        char aisle;
        int slot;
    public:
        ShelfLocation();
        char getAisle(); //ASK ABOUT THIS
        int getSlot();
        void displayLocation() const;
};
#endif