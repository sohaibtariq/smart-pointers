#include <iostream>
#include <string>
#include "copied_string.h"
using namespace std;

copied_string::copied_string() {
    _strbuf = NULL;
    _length = 0;
}

copied_string::~copied_string() {
   if (this->_strbuf != NULL) {
        delete _strbuf;
    }
  
        _length = 0;
}

copied_string::copied_string(const copied_string& a)
{
    
    this->_strbuf = a._strbuf;
    this->_length = a._length;
}

copied_string::copied_string(char *ch, int i)
{
    char * ptr = new char[i];
    for (int j = 0; j < i; j++) {
        ptr[j] = ch[j];
    }
    _strbuf = ptr;
    _length = i;

}
char copied_string::charAt(int x) const
{
    if (x < _length)
        return *(_strbuf + x);
}

int copied_string::length() const
{
    return _length;
}

void copied_string::reserve(int l)
{
   char *ptr= new char[l];
   _strbuf = ptr;
   _length = l;
}

void copied_string::append(char c)
{
    char *temp = new char[_length];
    memcpy(temp, _strbuf, _length);
    reserve(_length + 1);
    memcpy(_strbuf, temp, _length );
    _strbuf[_length-1] = c;
}

char * copied_string::get_str()
{
    return _strbuf;
}

int copied_string::get_length()
{
    return _length;
}
