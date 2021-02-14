#include <locale>

namespace std {

ctype<char>::ctype(const mask *tbl, bool del, size_t refs): locale::facet(refs), ctype_base(), _M_del(del), _M_table(tbl) {
}

ctype<char>::~ctype() {}
locale::id ctype<char>::id;
char ctype<char>::do_tolower(char c) const {
    return c; // FIXME: Incomplete
}
const char* ctype<char>::do_tolower(char *beg, const char *end) const {
    return beg; // FIXME: Incomplete
}
char ctype<char>::do_toupper(char c) const {
    return c; // FIXME: Incomplete
}
const char* ctype<char>::do_toupper(char *beg, const char *end) const {
    return beg; // FIXME: Incomplete
}
void ctype<char>::_M_widen_init() const {
    // What is this supposed to do? /shrug
}

locale::facet::~facet() {}

_Atomic_word locale::id::_S_refcount;
size_t locale::id::_M_id() const throw() {
    if(_M_index == 0) _M_index = ++_S_refcount;
    return _M_index - 1;
}

locale::locale() throw() {
    _M_impl = new _Impl(0); // No other references exist to our knowledge
}

locale::~locale() throw() {
}

const char *__num_base::_S_atoms_in;
const char *__num_base::_S_atoms_out;

template class num_get<char>;

template class num_put<char>;

template class __cxx11::numpunct<char>;
template<> __cxx11::numpunct<char>::~numpunct() {}

locale::_Impl::_Impl(size_t _a) throw() {
    _M_facets = new const facet*[1];
    _M_facets[0] = new std::ctype<char>(); // No other references exist to our knowledge
    _M_facets_size = 1; // Temp
}

template bool has_facet<ctype<char>>(const std::locale&) throw();
template bool has_facet<num_get<char>>(const std::locale&) throw();
template bool has_facet<num_put<char>>(const std::locale&) throw();

template const ctype<char>& use_facet<ctype<char>>(const std::locale&);

} // namespace std
