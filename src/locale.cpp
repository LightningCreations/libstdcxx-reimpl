#include <locale>

namespace std {

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

locale::facet::~facet() {}

size_t locale::id::_M_id() const throw() {
    return 0; // FIXME: Stub
}

locale::locale() throw() {
    _M_impl = new _Impl(0); // We'll figure out what this is used for later ;)
}

locale::~locale() throw() {
}

const char *__num_base::_S_atoms_in;
const char *__num_base::_S_atoms_out;

template class num_get<char>;

template class num_put<char>;

template class __cxx11::numpunct<char>;
template<> __cxx11::numpunct<char>::~numpunct() {}

locale::_Impl::_Impl(size_t _a) throw() {}

template bool has_facet<ctype<char>>(const std::locale&) throw();
template bool has_facet<num_get<char>>(const std::locale&) throw();
template bool has_facet<num_put<char>>(const std::locale&) throw();

} // namespace std
