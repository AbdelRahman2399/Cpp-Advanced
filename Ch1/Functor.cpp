#include <cstdio>
#include <iostream>

class MultBy{

    int n;

public:
    int GetN() {return n;};
    MultBy(const int & n) : n(n) {};
    int operator () (int x) const {return n*x;};
};

std::ostream & operator << (std::ostream & o, MultBy n){
    return o << std::to_string(n.GetN());
}

int main(){
    MultBy times5(5);
    std::cout << times5 << std::endl;
    std::cout << times5(5) << std::endl;

    return 0;
}