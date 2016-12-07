#pragma once

//////////////////////  need to overload -> and * ////////////////////

/* Defines the string class that will be used in the reference counted COW pointer
*/

class string_refcount {
public:
    string_refcount();                           //default constructor
    ~string_refcount();                          //destructor; would delete the allocated buffer
    string_refcount(string_refcount& a);         //constructor for shallow copying
    string_refcount(char*, int);                 //constructor to convert a char* to string_refcount
    char charAt(int) const;                      //returns the character at the passed index
    int length() const;                          //returns the length of the buffer
    void reserve(int);                           //allocates memory for the string, according to the passed character length
    void append(char);                           //appends a single character at the end
    char* get_str();                             //get a pointer to the string   
    int get_length();                            // get the length of the string   
    int _refcount ;

private:
    char* _strbuf;                               //buffer to store the original string
    int _length;                                 //length of the string

};