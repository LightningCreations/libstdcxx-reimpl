#include <condition_variable>
#include <thread>

namespace std {

condition_variable::condition_variable() {}

condition_variable::~condition_variable() {}

void condition_variable::notify_all() noexcept {}

void condition_variable::wait(std::unique_lock<std::mutex> &lock) {}

thread::_State::~_State() {}

}
