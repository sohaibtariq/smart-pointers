#include<iostream>
#include "owned_ptr.h"

owned_ptr::owned_ptr()
{
    _ptr = new owned_string();
    owner = false;
}

owned_ptr::~owned_ptr()
{
    if (_ptr != NULL){
        if (owner) {
            delete _ptr;
        }
        else
            _ptr = NULL;
    }
}

owned_ptr::owned_ptr(owned_string & s)
{

    char * c = s.get_str();
    char * new_c = new char[s.get_length()];
    for (int i = 0; i < s.get_length(); i++) {
        new_c[i] = c[i];
    }

    owned_string* ptr = new owned_string(new_c, s.get_length());
    _ptr = ptr;
    owner = true;

}

owned_ptr::owned_ptr(owned_ptr &p)
{
    _ptr = new owned_string(p.get_ptr(), p.get_length());
    p.owner = false;
    owner = true;

}

owned_ptr::owned_ptr(char *c, int i)
{
    _ptr = new owned_string(c, i);
}

int owned_ptr::get_length()
{
    return _ptr->get_length();
}

char * owned_ptr::get_ptr()
{
    return _ptr->get_str();
}
