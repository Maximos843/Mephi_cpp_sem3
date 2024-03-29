//
//  IndexError.h
//  mephi_labs_sem3_cpp
//
//  Created by Максим Шелестов on 03.12.2023.
//

#ifndef IndexError_h
#define IndexError_h
#include <string.h>

typedef enum {
    Empty_list,
    Invalid_args,
} Code;

class IndexError{
    Code error;
    std::string text[2] = {"List is empty", "Sequence doesn't have element with this index"};

public:
    void printError(){
        std::cout << text[(int) error] << std::endl;
    };
    IndexError(Code er) : error(er) {};
};

#endif
