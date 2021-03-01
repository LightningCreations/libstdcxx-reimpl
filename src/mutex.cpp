#include <mutex>

namespace std {

thread_local void *__once_callable;
thread_local void (*__once_call)();

extern "C" void __once_proxy() {}

}
