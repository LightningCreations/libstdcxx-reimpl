#include <iostream>
#include <streambuf>

namespace std {

ios_base::ios_base() throw() {}
ios_base::~ios_base() {}

void ios_base::_M_init() throw() {}

static uint64_t Init_refcount = 0;

class __libstdlcxx_cin_streambuf : public streambuf {

};

class __libstdlcxx_cout_streambuf : public streambuf {
  protected:
    virtual int overflow(int c) override;
};

class __libstdlcxx_cerr_streambuf : public streambuf {

};

class __libstdlcxx_clog_streambuf : public streambuf {

};

int __libstdlcxx_cout_streambuf::overflow(int c) {
    return (putchar(c) != EOF) ? c : EOF;
}

static __libstdlcxx_cin_streambuf cin_streambuf;
static __libstdlcxx_cout_streambuf cout_streambuf;
static __libstdlcxx_cerr_streambuf cerr_streambuf;
static __libstdlcxx_clog_streambuf clog_streambuf;

istream cin(&cin_streambuf);
ostream cout(&cout_streambuf);
ostream cerr(&cerr_streambuf);
ostream clog(&clog_streambuf);

class __libstdlcxx_Init {
  public:
    __libstdlcxx_Init();
    ~__libstdlcxx_Init();
};

__libstdlcxx_Init::__libstdlcxx_Init() {
    new (&cin) istream(&cin_streambuf);
    new (&cout) ostream(&cout_streambuf);
    new (&cerr) ostream(&cerr_streambuf);
    new (&clog) ostream(&clog_streambuf);
    cin.tie(&cout);
    cerr.tie(&cout);
}

__libstdlcxx_Init::~__libstdlcxx_Init() {
    std::cout.flush();
    std::cerr.flush();
    std::clog.flush();
}

ios_base::Init::Init() {
    static __libstdlcxx_Init true_init; // Idea from LLVM libc++
}

ios_base::Init::~Init() {
}

} // namespace std
