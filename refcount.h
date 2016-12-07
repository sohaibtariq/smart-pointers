#pragma once
#include "string_refcount.h"

class refcount {
public:
    refcount();
    refcount(string_refcount&);
    refcount(refcount&);
    refcount(char*, int);
    ~refcount();
    string_refcount* operator->() { return _ptr; };
private:
    string_refcount* _ptr;
};