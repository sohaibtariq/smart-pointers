#pragma once
#include "owned_string.h"

class owned_ptr {

public:
    owned_ptr();
    ~owned_ptr();
    owned_ptr(owned_string&);
    owned_ptr(owned_ptr&);
    owned_ptr(char*,int);
    int get_length();
    char *get_ptr();
    owned_string* operator ->() { return _ptr; }
    bool owner;
private:
    owned_string * _ptr;

};