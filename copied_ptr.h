//This class represents a copied pointer implementation that creates a deep copy of a copied_str object

#pragma once
#include "copied_string.h"

class copied_ptr {
private:
    copied_string* _str;
public:
    copied_ptr();   //default constructor
    copied_ptr(copied_string &);
    copied_ptr(copied_ptr &);
    copied_ptr(char*, int);
    int get_length();
    char* get_ptr();
    ~copied_ptr();
    copied_string* operator ->() { return _str; }
};