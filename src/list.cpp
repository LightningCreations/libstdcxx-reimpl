#include <list>
#include <unordered_map>
#include <cstdio>
#include <exception>

namespace std::__detail {

void _List_node_base::_M_hook(_List_node_base *x) noexcept {
    printf("_List_node_base::_M_hook(_List_node_base*) is a stub\n");
    std::terminate();
}

void _List_node_base::_M_unhook() noexcept {
    printf("_List_node_base::_M_unhook() is a stub\n");
    std::terminate();
}

void _List_node_base::_M_transfer(_List_node_base *x, _List_node_base *y) noexcept {
    printf("_List_node_base::_M_transfer(_List_node_base*, _List_node_base*) is a stub\n");
    std::terminate();
}

void _List_node_base::swap(_List_node_base &x, _List_node_base &y) noexcept {
    printf("_List_node_base::swap(_List_node_base&, _List_node_base&) is a stub\n");
    std::terminate();
}

std::size_t _Prime_rehash_policy::_M_next_bkt(std::size_t) const {
    printf("_Prime_rehash_policy::_M_next_bkt(size_t) is a stub\n");
    std::terminate();
}

std::pair<bool, std::size_t> _Prime_rehash_policy::_M_need_rehash(unsigned long, unsigned long, unsigned long) const {
    printf("_Prime_rehash_policy::_M_need_rehash(unsigned long, unsigned long, unsigned long) is a stub\n");
    std::terminate();
}

}
