// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include <iostream>
#include "Label.h"

using namespace std;

//Same old helper function as in Product class. Just copied here to avoid any issues with inheritance and access specifiers.
//see also: store.cpp, supplier.cpp, digitalproduct.cpp
char* Label::copyString(const char* original){
    if(!original) original = "";
    int len = 0;
    while(original[len] != '\0') len++;

    char* temp = new char[len + 1];
    for(int i = 0; i < len; i++) temp[i] = original[i];

    temp[len] = '\0';
    return temp;
}

// CONSTRUCTORS

// Default constructor
Label::Label() {
    labelText = copyString("Untitled Label");
    cout << "Label " << labelText << " created" << endl;
}

// Parameterized constructor
Label::Label(const char* text) {
    labelText = copyString(text);
    cout << "Label " << labelText << " created" << endl;
}

// Copy Constructor (Deep Copy)
Label::Label(const Label& other) {
    labelText = copyString(other.labelText);
    cout << "Label " << labelText << " (Copy) created" << endl;
}

// ASSIGNMENT OPERATOR (Deep Copy & Self-Assignment Guard)
Label& Label::operator=(const Label& other) {
    if (this != &other) {
        delete[] labelText;                  // Free old memory
        labelText = copyString(other.labelText); // Allocate new copy
    }
    return *this;
}

// DESTRUCTOR
Label::~Label() {
    cout << "Label " << (labelText ? labelText : "") << " destroyed" << endl;
    delete[] labelText; // Free dynamic memory
}

// SETTERS AND GETTERS

void Label::setText(const char* text) {
    delete[] labelText;         // Deallocate previous heap memory
    labelText = copyString(text); // Reallocate with new string
}

const char* Label::getText() const {
    return labelText;
}

// MEMBER FUNCTIONS

void Label::printLabel() const {
    cout << "*  " << labelText << endl;
}