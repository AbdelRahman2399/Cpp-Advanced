// class.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-10-03
#include <cstdio>
using namespace std;

// a very simple class
class c1 {
    int i = 0;
public:
    void setvalue( const int & value ) { i = value; }
    int getvalue() const;
    int getvalue2() const;
};

int c1::getvalue() const{
    //printf("pointer is %p",this);
    return i;
}


int c1::getvalue2() const{
    return this->getvalue();
    // or getvalue();
}

int main() {
    const int i = 47;
    c1 o1;
    o1.setvalue(i);
    printf("value is %d\n", o1.getvalue());
    printf("value is %d\n", o1.getvalue2());
    return 0;
}
