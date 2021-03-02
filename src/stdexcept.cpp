#include <stdexcept>

namespace std {

logic_error::~logic_error() noexcept {}

const char* logic_error::what() const noexcept {
    return "Logic error";
}

}
