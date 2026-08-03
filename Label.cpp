// Group Names: 1. Ahmad Enad Dweikat 2. Mohammad Araby Al-kabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270
#include "StringUtils.h"
#include <iostream>
#include "Label.h"

// CONSTRUCTORS

// Default constructor
// basic
Label::Label() {
    labelText = copyString("Untitled Label");
    std::cout << "Label " << labelText << " created" << std::endl;
}

// Parameterized constructor
// only allocates memory for labelText and copies the provided text into it.
Label::Label(const char* text) {
    labelText = copyString(text);
    std::cout << "Label " << labelText << " created" << std::endl;
}

// Copy Constructor (Deep Copy)
// Allocates new memory for labelText and copies the content from the other Label object.
Label::Label(const Label& other) {
    labelText = copyString(other.labelText);
    std::cout << "Label " << labelText << " (Copy) created" << std::endl;
}

// ASSIGNMENT OPERATOR (Deep Copy & Self-Assignment Guard)
// Frees the existing memory of labelText, allocates new memory, 
// and copies the content from the other Label object.
Label& Label::operator=(const Label& other) {
    if (this != &other) {
        delete[] labelText;                  
        labelText = copyString(other.labelText); 
    }
    return *this;
}

// DESTRUCTOR
// Frees the dynamically allocated memory for labelText
// and prints a message indicating that the label has been destroyed.
Label::~Label() {
    std::cout << "Label " << (labelText ? labelText : "") << " destroyed" << std::endl;
    delete[] labelText;
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
    std::cout << "*  " << labelText << std::endl;
}