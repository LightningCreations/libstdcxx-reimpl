#include <cstdlib>
#include <exception>

namespace std {

static terminate_handler current_terminate_handler = &abort;

void terminate() noexcept {
    current_terminate_handler();
    exit(1); // Something has gone horribly wrong
}

terminate_handler get_terminate() noexcept {
    return current_terminate_handler;
}

exception::~exception() noexcept {}

const char* exception::what() const noexcept {
    return "Generic exception";
}

// exception_ptr::exception_ptr(exception_ptr const&) noexcept {}

// exception_ptr::~exception_ptr() noexcept {}

// bool __exception_ptr::operator==(const exception_ptr &x, const exception_ptr &y) noexcept {
//     return x._M_exception_object == y._M_exception_object;
// }

exception_ptr current_exception() noexcept {
    return exception_ptr(nullptr);
}

void rethrow_exception(exception_ptr p) {
    throw *((exception*) p._M_exception_object);
}

}
