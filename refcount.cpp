#include<iostream>
#include "refcount.h"


refcount::refcount()
{
    _ptr = new string_refcount(); 
}

refcount::refcount(string_refcount& s) 
{
    _ptr = &s;
    s._refcount++;
}

refcount::refcount(refcount &p)
{
    _ptr = p._ptr;
    p->_refcount++;
}

refcount::refcount(char *c, int i)
{
    _ptr = new string_refcount(c, i);
}

refcount::~refcount()
{
    if (_ptr != NULL) {
        if (_ptr->_refcount > 0)
            _ptr->_refcount--;
       // delete  _ptr;
         _ptr=NULL;
    }
}


