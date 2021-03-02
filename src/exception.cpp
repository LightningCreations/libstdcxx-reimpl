#include <exception>

namespace std {

exception::~exception() noexcept {}

const char* exception::what() const noexcept {
    return "Generic exception";
}

exception_ptr::exception_ptr(exception_ptr const&) noexcept {}

exception_ptr::~exception_ptr() noexcept {}

bool __exception_ptr::operator==(const exception_ptr &x, const exception_ptr &y) noexcept {
    return x._M_exception_object == y._M_exception_object;
}

exception_ptr current_exception() noexcept {
    return exception_ptr(nullptr);
}

void rethrow_exception(exception_ptr p) {
    throw *((exception*) p._M_exception_object);
}

}
