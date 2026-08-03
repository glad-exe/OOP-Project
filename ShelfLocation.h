// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#ifndef SHELFLOCATION_H
#define SHELFLOCATION_H

class ShelfLocation {
    private:
        char aisle; // i have nothing to add, its such a simple file.
        int  slot;
    public:
        ShelfLocation();
        char getAisle();
        int  getSlot();
        void displayLocation() const;

        //finally.
        void setAisle(char a);
        void setSlot(int s);
};
#endif