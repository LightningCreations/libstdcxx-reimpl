#include <stdexcept>

namespace std {

logic_error::~logic_error() {}

const char* logic_error::what() const {
    return "Logic error";
}

}
