#include <list>
#include <cstdio>

namespace std {

namespace __detail {

void _List_node_base::_M_hook(_List_node_base *x) {
    printf("_List_node_base::_M_hook(_List_node_base*) is a stub\n");
}

void _List_node_base::_M_transfer(_List_node_base *x, _List_node_base *y) {
    printf("_List_node_base::_M_transfer(_List_node_base*, _List_node_base*) is a stub\n");
}

void _List_node_base::swap(_List_node_base &x, _List_node_base &y) {
    printf("_List_node_base::swap(_List_node_base&, _List_node_base&) is a stub\n");
}

}

}
