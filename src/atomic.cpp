#include <cstdlib>
#include <future>

namespace std {

bool __atomic_futex_unsigned_base::_M_futex_wait_until(unsigned *__addr, unsigned __val, bool __has_timeout, chrono::seconds __s, chrono::nanoseconds __ns) {
    abort();
}

void __atomic_futex_unsigned_base::_M_futex_notify_all(unsigned *__addr) {
    abort();
}

}
