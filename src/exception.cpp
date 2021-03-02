#include <exception>

namespace std {

exception::~exception() {}

const char* exception::what() const {
    return "Generic exception";
}

exception_ptr::exception_ptr(exception_ptr const&) {}

exception_ptr::~exception_ptr() {}

bool operator==(const exception_ptr &x, const exception_ptr &y) {
    return x._M_exception_object == y._M_exception_object;
}

exception_ptr current_exception() {
    return exception_ptr(nullptr);
}

void rethrow_exception(exception_ptr p) {
    throw *((exception*) p._M_exception_object);
}

}
