#include <fstream>

namespace std {

__basic_file<char>::~__basic_file() {}

template class basic_filebuf<char>;

template class basic_ifstream<char>;

}
