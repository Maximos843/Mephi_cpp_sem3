#ifndef IndexError_h
#define IndexError_h

#include <string.h>
#include <iostream>


const std::string SIZE_LOWER_ZERO = "Size < 0";
const std::string SIZE_ZERO = "Size = 0";
const std::string INVALID_PARAM = "Invalid param";
const std::string INDEX_OUT_OF_RANGE = "Index out of range";
const std::string EMPTY_ELEMENT = "Empty element";


/*typedef enum {
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
    IndexError(Code er) : error(er) {};
};*/

#endif