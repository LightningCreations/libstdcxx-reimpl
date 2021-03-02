#include <list>
#include <cstdio>
#include <exception>

namespace std {

namespace __detail {

void _List_node_base::_M_hook(_List_node_base *x) noexcept {
    printf("_List_node_base::_M_hook(_List_node_base*) is a stub\n");
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

}

}
