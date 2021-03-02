#include <condition_variable>
#include <thread>

namespace std {

condition_variable::condition_variable() noexcept {}

condition_variable::~condition_variable() noexcept {}

void condition_variable::notify_all() noexcept {}

void condition_variable::wait(std::unique_lock<std::mutex> &lock) noexcept {}

thread::_State::~_State() {}

void thread::join() {}

}
