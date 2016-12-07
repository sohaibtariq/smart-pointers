#include <iostream>
#include <string>
#include "owned_string.h"
using namespace std;

owned_string::owned_string() {
    _strbuf = NULL;
    _length = 0;
}



owned_string::owned_string(owned_string& s)
{
    char * c = s.get_str();
    int l = s.get_length();
    char * new_c = new char[l];
    for (int i = 0; i < l; i++) {
        new_c[i] = c[i];
    }
    _strbuf = new_c;
    _length = l;

}

owned_string::owned_string(char *ch, int i)
{
    char * ptr = new char[i];
    memset(ptr,0,sizeof(ptr));
    for (int j = 0; j < i; j++) {
        ptr[j] = ch[j];
    }
    _strbuf = ptr;
    _length = i;

}

char owned_string::charAt(int x) const
{
    if (x < _length)
        return *(_strbuf + x);
}

int owned_string::length() const
{
    return _length;
}

void owned_string::reserve(int l)
{
    char *ptr = new char[l];
    _strbuf = ptr;
    _length = l;
}

void owned_string::append(char c)
{
    char *temp = new char[_length];
    memcpy(temp, _strbuf, _length);
    reserve(_length + 1);
    delete _strbuf;
    memcpy(_strbuf, temp, _length);
    _strbuf[_length - 1] = c;
    temp = NULL;
}

char * owned_string::get_str()
{
    return _strbuf;
}

int owned_string::get_length()
{
    return _length;
}


owned_string::~owned_string() {

    //   if (_strbuf != NULL) {
    //      delete[] _strbuf;
    _strbuf = NULL;
    _length = 0;
    //   }
}