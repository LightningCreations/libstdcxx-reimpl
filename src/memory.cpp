#include <memory>

namespace std {

bad_weak_ptr::~bad_weak_ptr() noexcept {}

const char* bad_weak_ptr::what() const noexcept {
    return "Bad weak_ptr";
}

}
