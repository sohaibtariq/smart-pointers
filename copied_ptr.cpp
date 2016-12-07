#include <iostream>
#include "copied_ptr.h"

copied_ptr::copied_ptr()
{
    _str = new copied_string();
}

copied_ptr::copied_ptr(copied_string &s)
{
    
    char * c = s.get_str();
    char * new_c = new char[s.get_length()];
    for (int i = 0; i < s.get_length(); i++) {
        new_c[i] = c[i];
    }

    copied_string* ptr = new copied_string(new_c,s.get_length());
    _str = ptr;

}

copied_ptr::copied_ptr(copied_ptr &p)
{
    _str = new copied_string(p.get_ptr(), p.get_length());
}

copied_ptr::copied_ptr(char *c, int i)
{
    _str= new copied_string(c,i);
}

int copied_ptr::get_length()
{
    return _str->get_length();
}

char * copied_ptr::get_ptr()
{
    return _str->get_str();
}

copied_ptr::~copied_ptr()
{
    if (_str != NULL)
        delete _str;

}
