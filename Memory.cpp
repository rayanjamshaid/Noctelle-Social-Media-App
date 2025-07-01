#include "Memory.h"
#include <iostream>

Memory::Memory(Post* _post) {
    if (_post) {
        post = new Post(*_post); // deep copy
    }
    else {
        post = nullptr;
    }
}

Memory::Memory(const Memory& other) {
    if (other.post) {
        post = new Post(*other.post);
    }
    else {
        post = nullptr;
    }
}

Memory& Memory::operator=(const Memory& other) {
    if (this != &other) {
        delete post;
        if (other.post) {
            post = new Post(*other.post);
        }
        else {
            post = nullptr;
        }
    }
    return *this;
}

Memory::~Memory() {
    delete post;
}

void Memory::show_memory() {
    if (post) {
        std::cout << "Memory from the past:\n";
        post->print_post(); // assuming Post has a print_post() method
    }
    else {
        std::cout << "No memory available.\n";
    }
}
