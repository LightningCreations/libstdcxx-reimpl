#include <new>
#include <stdlib.h>

void* operator new(size_t count) {
    return malloc(count);
}

void* operator new[](size_t count) {
    return malloc(count);
}

void operator delete(void *ptr) {
    free(ptr);
}

void operator delete(void *ptr, size_t sz) {
    free(ptr);
}

namespace std {

bad_alloc::~bad_alloc() {}

const char* bad_alloc::what() const {
    return "Bad allocation";
}

}
