// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#include "Product.h"
#ifndef LABEL_H
#define LABEL_H

char* copyString(const char* source);

class Label {
private:
    char* labelText;
    friend char* copyString(const char* source);

public:
    // CONSTRUCTORS
    Label();                          
    Label(const char* text);          
    Label(const Label& other);        

    // ASSIGNMENT OPERATOR
    Label& operator=(const Label& other);

    // DESTRUCTOR
    ~Label();

    // SETTERS AND GETTERS
    void setText(const char* text);
    const char* getText() const;

    // MEMBER FUNCTIONS
    void printLabel() const;
    char* Label::copyString(const char* original);
};

#endif