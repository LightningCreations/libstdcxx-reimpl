#include <random>

namespace std {

void random_device::_M_fini() {}

random_device::result_type random_device::_M_getval() {
    return 0; // So very random.
}

}
