#pragma once
#include <cstddef>

struct bucket {
    int* data = nullptr;
    std::size_t capacity = 0;
    std::size_t used = 0;
    bucket* next = nullptr;
};

class arena {
public:
    arena* create();
    int* allocate(std::size_t count);
    void destroy(arena* a);
private:
    bucket* first = nullptr;
    bucket* current = nullptr;
};
