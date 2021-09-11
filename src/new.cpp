#include <new>
#include <stdlib.h>

static std::new_handler g_new_handler;

void* operator new(size_t count) {
    void *result = malloc(count);
    while(!result && g_new_handler) {
        g_new_handler();
        result = malloc(count);
    }
    if(!result) {
        throw new std::bad_alloc();
    }
    return result;
}

void* operator new[](size_t count) {
    return malloc(count);
}

void* operator new(size_t count, const std::nothrow_t&) noexcept {
    return malloc(count);
}

void* operator new[](size_t count, const std::nothrow_t&) noexcept {
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

new_handler set_new_handler(new_handler new_p) noexcept {
    new_handler prev = g_new_handler;
    g_new_handler = new_p;
    return prev;
}

}
