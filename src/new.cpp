#include <new>
#include <stdlib.h>

void* operator new(size_t count) {
    return malloc(count);
}

void* operator new[](size_t count) {
    return malloc(count);
}

void operator delete(void *ptr) noexcept {
    free(ptr);
}

void operator delete[](void *ptr) noexcept {
    free(ptr);
}

void operator delete(void *ptr, size_t sz) {
    free(ptr);
}

void operator delete[](void *ptr, size_t sz) {
    free(ptr);
}

namespace std {

bad_alloc::~bad_alloc() noexcept {}

const char* bad_alloc::what() const noexcept {
    return "Bad allocation";
}

const nothrow_t nothrow;

}
