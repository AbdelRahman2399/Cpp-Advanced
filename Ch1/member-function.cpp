// member-function.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-10-03
#include <cstdio>
using namespace std;

class A {
    int _value = 0;
public:
    void setv ( const int a ) { _value = a; };
    int getv ();
    int getv () const;
};

int A::getv () {
    return _value; 
}

int A::getv () const {
    puts("const qualified");
    return _value; 
}

int main() {
    A a;
    a.setv(42);
    printf("a is %d\n", a.getv());
    const A b = a;
    printf("b is %d\n", b.getv());
    return 0;
}
