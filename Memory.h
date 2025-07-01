#pragma once
#include "Post.h"

class Memory {
private:
    Post* post; // a copy of the post saved as a memory

public:
    Memory(Post* _post);  // store a deep copy
    Memory(const Memory& other); // copy constructor
    Memory& operator=(const Memory& other); // assignment
    ~Memory();

    void show_memory(); // display the memory
};
