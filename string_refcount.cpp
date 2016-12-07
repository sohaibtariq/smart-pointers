#include <iostream>
#include <string>
#include "string_refcount.h"
using namespace std;

string_refcount::string_refcount() {
    _strbuf = NULL;
    _length = 0;
    _refcount = 0;
}

string_refcount::string_refcount(string_refcount& s)
{
    char * c = s.get_str();
    int l = s.get_length();
    char * new_c = new char[l];
    for (int i = 0; i < l; i++) {
        new_c[i] = c[i];
    }
    _strbuf = new_c;
    _length = l;
    _refcount = 0;
}

string_refcount::string_refcount(char *ch, int i)
{
    char * ptr = new char[i];
    for (int j = 0; j < i; j++) {
        ptr[j] = ch[j];
    }
    _strbuf = ptr;
    _length = i;
    _refcount = 0;

}

char string_refcount::charAt(int x) const
{
    if (x < _length)
        return *(_strbuf + x);
}
 
int string_refcount::length() const
{
    return _length;
}

void string_refcount::reserve(int l)
{
    char *ptr = new char[l];
    _strbuf = ptr;
    _length = l;
}

void string_refcount::append(char c)
{
    char *temp = new char[_length];
    memcpy(temp, _strbuf, _length);
    reserve(_length + 1);
    delete _strbuf;
    memcpy(_strbuf, temp, _length);
    _strbuf[_length - 1] = c;
    temp = NULL;
}

char * string_refcount::get_str()
{
    return _strbuf;
}

int string_refcount::get_length()
{
    return _length;
}


string_refcount::~string_refcount() {
    _strbuf = NULL;
    // if (_strbuf != NULL) {
    //    delete _strbuf;
    _length = 0;
    // }
}