#include <memory>

namespace std {

bad_weak_ptr::~bad_weak_ptr() {}

const char* bad_weak_ptr::what() const {
    return "Bad weak_ptr";
}

}
