#include <future>
#include <system_error>

namespace std {

__future_base::_Result_base::_Result_base() {}

__future_base::_Result_base::~_Result_base() {}

future_error::~future_error() noexcept {}

const char* future_error::what() const noexcept {
    return "Future error";
}

class future_error_category : public error_category {
  public:
    const char* name() const noexcept override { return "future"; }
    std::string message(int condition) const override { return "Future error"; }
};

static future_error_category __future_category;

const error_category& future_category() noexcept {
    return __future_category;
}

}
