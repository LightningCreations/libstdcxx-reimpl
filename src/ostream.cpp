#include <ostream>

namespace std {

template class basic_ostream<char>;
template ostream& endl(ostream&);
template ostream& operator<<(ostream&, const char*);
template ostream& __ostream_insert(ostream&, const char*, long);
template ostream& flush(ostream&);
template ostream& ostream::_M_insert<double>(double);
template ostream& ostream::_M_insert<unsigned long>(unsigned long);

} // namespace std
