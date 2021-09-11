#include <system_error>

namespace std {

error_category::~error_category() {}

__cow_string error_category::_M_message(int condition) const {
    return __cow_string();
}

error_condition error_category::default_error_condition(int code) const noexcept {
    return error_condition(code, *this);
}

bool error_category::equivalent(int code, const error_condition &condition) const noexcept {
    return default_error_condition(code) == condition;
}

bool error_category::equivalent(const error_code &code, int condition) const noexcept {
    return *this == code.category() && code.value() == condition;
}

system_error::~system_error() noexcept {}

}
