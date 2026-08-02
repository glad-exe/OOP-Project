// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#include "Product.h"
#ifndef LABEL_H
#define LABEL_H

class Label {
private:
    char* labelText; // Text of the label, stored as a dynamically allocated C-style string.
public:
    // CONSTRUCTORS
    // Default constructor
    Label();              
    // Parameterized constructor            
    Label(const char* text);    
    // Copy constructor (Deep Copy)      
    Label(const Label& other);        

    // ASSIGNMENT OPERATOR
    Label& operator=(const Label& other);

    // Destructor
    ~Label();

    // SETTERS AND GETTERS
    void setText(const char* text);
    const char* getText() const;

    // MEMBER FUNCTIONS
    void printLabel() const;
};

#endif