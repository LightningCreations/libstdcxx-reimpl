#include <ostream>

namespace std {

template class basic_ostream<char>;
template ostream& endl(ostream&);
template ostream& operator<<(ostream&, const char*);
template ostream& __ostream_insert(ostream&, const char*, long);
template ostream& flush(ostream&);

} // namespace std
