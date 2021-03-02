#include <future>

namespace std {

__future_base::_Result_base::_Result_base() {}

__future_base::_Result_base::~_Result_base() {}

future_error::~future_error() noexcept {}

const char* future_error::what() const noexcept {
    return "Future error";
}

}
