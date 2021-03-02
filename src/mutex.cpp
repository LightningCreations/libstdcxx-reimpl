#include <mutex>

namespace std {

__thread void *__once_callable;
__thread void (*__once_call)();

extern "C" void __once_proxy() {}

}
