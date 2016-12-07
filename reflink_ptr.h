#pragma once
#include "owned_string.h"

class reflink_ptr {

public:
   reflink_ptr();
   ~reflink_ptr();
   reflink_ptr(owned_string&);
   reflink_ptr(reflink_ptr&);
   reflink_ptr(char*, int);
    int get_length();
    char *get_ptr();
    owned_string* operator ->() { return _ptr; }
   
private:
    owned_string * _ptr;
    reflink_ptr *next;
    reflink_ptr *previous;


};