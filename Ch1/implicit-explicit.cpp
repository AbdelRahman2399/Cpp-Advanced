// implicit-explicit.cpp by Bill Weinman <http://bw.org/>
// updated 2018-11-08
#include <cstdio>
using namespace std;
// characters can implicitly be converted to integers
class c1 {
    int _value = 0;
public:
    explicit c1 (const int & value) : _value(value) {} //explicit =>can't convert char to int
    void setvalue( const int & value ) { _value = value; }
    int getvalue() const { return _value; }
};

void func(const c1 & o) {
    printf("value is %d\n", o.getvalue());
}

int main() {
    c1 o = 'x'; //won't convert x to its asci number '120' because constructor is explicit
    printf("value is %d\n", o.getvalue());
    func('x');
    return 0;
}

