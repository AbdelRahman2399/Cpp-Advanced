#include <cstdio>
#include <cstring>
#include <iostream>
#include <memory>
#include <utility>

#include <cstddef>

constexpr const char * __strc_class = "strc";
constexpr const char * __strc_version = "1.1";
constexpr size_t _maxlen = 10240;

class strc {
    char * data = nullptr;
    void msg(const char *);
public:
    strc();
    strc(const char * s);
    strc(const strc &);
    strc(strc &&);
    ~strc();
    strc & operator = (strc);
    const char * value() const;
    operator const char * () const;
    void swap(strc &);
    void prints(){
    if(this){
        puts(data);
    }else{
        puts("nullptr");
    }
    }
};

void strc::msg(const char * s) {
    if(data) printf("%s: %s (%s)\n", __strc_class, s, data);
    else printf("%s: %s\n", __strc_class, s);
    fflush(stdout);
}

strc::strc() : data(nullptr) {
    msg("default ctor");
}

strc::strc(const char * s) {
    size_t slen = strnlen(s, _maxlen);
    data = new char[slen + 1];
    data[slen] = 0;
    memcpy(data, s, slen);
    msg("cstring ctor");
}

strc::strc(const strc & f) {
    size_t slen = strnlen(f.data, _maxlen);
    data = new char[slen + 1];
    data[slen] = 0;
    memcpy(data, f.data, slen);
    msg("copy ctor");
}

strc::strc(strc && o) {
    data = std::move(o.data);
    o.data = nullptr;
    msg("move ctor");
}

strc::~strc() {
    msg("dtor");
    delete[] data;
}

strc & strc::operator = (strc o) {
    swap(o);
    msg("copy and swap =");
    return *this;
}

const char * strc::value() const {
    return data;
}

strc::operator const char * () const {
    return value();
}

void strc::swap(strc & o) {
    msg("strc swap");
    std::swap(this->data, o.data);
}




int main(){
    //std::unique_ptr<strc> a(new strc("one"));
    //std::unique_ptr<strc> a(new strc("one"));
    std::unique_ptr<strc> a(new strc("one"));

    puts(a->value());
    fflush(stdout);

    std::unique_ptr<strc> b(new strc("two"));
    puts(b->value());


    a.reset(new strc("three"));
    puts(a->value());

    auto c = std::move(b);
    b->prints();
    c->prints();
    return 0;
}
