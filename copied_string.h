#pragma once

//This class implements a string to be used with the copied pointer

class copied_string {
public:
    copied_string();                                //default constructor
    ~copied_string();                               //destructor; would delete the allocated buffer
    copied_string(const copied_string& a);             //constructor for shallow copying
    copied_string(char*, int);                      //constructor to convert a char* to copied_string
    char charAt(int) const;                      //returns the character at the passed index
    int length() const;                          //returns the length of the buffer
    void reserve(int);                           //allocates memory for the string, according to the passed character length
    void append(char);                           //appends a single character at the end
    char* get_str();
    int get_length();
private:
    char* _strbuf;                               //buffer to store the original string
    int _length;                                 //length of the string

};
