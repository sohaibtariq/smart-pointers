#pragma once

class owned_string {
public:
    owned_string();                           //default constructor
    ~owned_string();                          //destructor; would delete the allocated buffer
    owned_string(owned_string& a);         //constructor for shallow copying
    owned_string(char*, int);                 //constructor to convert a char* to owned_string
    char charAt(int) const;                      //returns the character at the passed index
    int length() const;                          //returns the length of the buffer
    void reserve(int);                           //allocates memory for the string, according to the passed character length
    void append(char);                           //appends a single character at the end
    char* get_str();                             //get a pointer to the string   
    int get_length();                            // get the length of the string   


private:
    char* _strbuf;                               //buffer to store the original string
    int _length;                                 //length of the string

};