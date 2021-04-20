#include <chrono>
#include <cstdlib>

std::chrono::time_point<std::chrono::system_clock> std::chrono::system_clock::now() noexcept {
    abort();
}
