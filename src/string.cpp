#include <istream>
#include <string>

namespace std {

template class basic_string<char>;

template<> istream& getline(istream &a, string&, char) {
    return a;
}
template istream& getline(istream&, string&);

}
