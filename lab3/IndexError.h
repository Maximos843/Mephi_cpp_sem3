#ifndef IndexError_h
#define IndexError_h

#include <string.h>
#include <iostream>

typedef enum {
    Empty_list,
    Invalid_args,
    Invalid_param,
    Index_exist,
    Out_of_range,
    Empty_tree,
} Code;

class IndexError{
    Code error;
    std::string text[6] = {
        "List is empty",
        "Sequence doesn't have element with this index",
        "Param incorrect",
        "Index doesn't exist",
        "Index out of range",
        "Tree is empty",
    };

public:
    void printError(){
        std::cout << text[(int) error] << std::endl;
    };
    IndexError(Code er) : error(er) {};
};

#endif