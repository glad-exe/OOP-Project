// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#include<iostream>
#include "Label.h"
using namespace std;

    void Label::copyText(const char* source){
        int len = 0;
        while(source[len] != '\0') len++;

        if(len > 99) len = 99;

        for(int i = 0; i < len; i++){
            labelText[i] = source[i];
        }
        labelText[len] = '\0';
    }

    //CONSTRUCTORS
    //Default constructor
    Label::Label(){
        copyText("Untitled Label");
        cout << "Label " << labelText << " created" << endl;
    }

    //Constructor with text
    Label::Label(const char* text){
        copyText(text);
        cout << "Label " << labelText << " created" << endl;
    }

    //DESTRUCTOR
    Label::~Label(){
        cout << "Label " << labelText << " destroyed" << endl;
    }

    //SETTERS AND GETTERS

    void Label::setText(const char* text){
        copyText(text);
    }

    const char* Label::getText() const { return labelText; }

    //MEMBER FUNCTIONS

    //prints the sticker
    void Label::printLabel() const{
        cout << "*  " << labelText << endl;
    }
