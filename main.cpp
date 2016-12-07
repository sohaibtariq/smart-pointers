#include <iostream>
#include "copied_string.h"
#include "string_refcount.h"
#include "refcount.h"
#include "copied_ptr.h"
#include"owned_ptr.h"
#include "owned_string.h"
#include "reflink_ptr.h"
using namespace std;

int main() { 
    
    char ptr[] ="Use Visual Studio to define and run your unit tests to maintain code health, ensure code coverage, and to find errors and faults before your customers do.";
    string_refcount n(ptr, sizeof(ptr));
    cout << n.charAt(0);
    string_refcount x(n);
    cout<< x.length();

    x.append('!');
    cout << x.charAt(x.length()-1);
    
    refcount r;
    refcount r2(n);
    refcount r3(n);
    cout << " refcount : " << n._refcount;

    copied_string cp(ptr, sizeof(ptr));
    copied_ptr cp_ptr(cp);
    
    owned_string os;
    owned_string os2(ptr,sizeof(ptr));
    owned_ptr op(os2);
    owned_ptr op2(op);
    cout<<"owned:"<<op->get_str()<<endl;
    op2->append('l');
    cout<<"length"<<op2->length()<<endl;
    cout << op2.owner;
    cout << op.owner;

    reflink_ptr rf(os2);
    rf->append('a');
    cout << op->get_str();


    /*cout << n.length();
    cout << x.length();*/
    //cout << strlen();
    return 0;   
}