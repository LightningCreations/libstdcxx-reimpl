#include <istream>

namespace std {

template class basic_istream<char>;

template class basic_iostream<char>; // Why is this in istream and not iostream?

} // namespace std
