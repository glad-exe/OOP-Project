// Group Names: 1. Ahmad Enad Dweikat 2. Mohamed Arabi Alkabbani 3. Munther Walid Alhawamdeh 4. Layth Marwan Allouzi
// Student ID: 20251030 20250141 20250032 20230270

#ifndef LABEL_H
#define LABEL_H

class Label{
    private:
        char labelText[100];
        void copyText(const char* source);

    public:
    //CONSTRUCTORS
    //Default constructor
    Label();
    //Constructor with text
    Label(const char* text);

    //DESTRUCTOR
    ~Label();

    //SETTERS AND GETTERS
    void setText(const char* text);
    const char* getText() const;

    //member functions
    void printLabel() const;

};

#endif
