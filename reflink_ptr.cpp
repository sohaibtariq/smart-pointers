#include<iostream>
#include "reflink_ptr.h"

reflink_ptr::reflink_ptr()
{
    _ptr = new owned_string();
    next = this;
    previous = this;
}

reflink_ptr::~reflink_ptr()
{
    if (next==previous) {
        delete _ptr;
        if (next != NULL) {
            next = NULL;
            previous = NULL;
        }
    }
    else {
        previous->next = next;
        next->previous = previous;
        next = NULL;
        previous = NULL;
    }
}

reflink_ptr::reflink_ptr(owned_string &s)
{
    char * c = s.get_str();
    char * new_c = new char[s.get_length()];
    for (int i = 0; i < s.get_length(); i++) {
        new_c[i] = c[i];
    }

    owned_string* ptr = new owned_string(new_c, s.get_length());
    _ptr = ptr;
    next = this;
    previous = this;   

}

reflink_ptr::reflink_ptr(reflink_ptr &p)
{

    _ptr = new owned_string(p.get_ptr(), p.get_length());
    next = p.next;
    previous =&p ;
    next->previous = this;
    previous->next = this;
}

reflink_ptr::reflink_ptr(char *c, int i)
{
    _ptr = new owned_string(c,i);
    next=this;
    previous = this;
}

int reflink_ptr::get_length()
{
    return _ptr->get_length();
}

char * reflink_ptr::get_ptr()
{
    return _ptr->get_str();
}
