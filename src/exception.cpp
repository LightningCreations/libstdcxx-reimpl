#include <exception>

namespace std {

exception::~exception() {}

const char* exception::what() const {
    return "Generic exception";
}

}
