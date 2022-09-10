#include <cstdio>
#include <iostream>
using namespace std;

class Val{

int value;
public:

Val() : value(0){}
Val(const int & v) : value(v) {}
void SetVal(int & v){
    value = v;
}

int GetVal(){
    return value;
}

operator std::string() const{
    return std::to_string(value);
}

Val & operator ++ (){
    value++;
    return *this;
}

Val & operator -- (){
    value--;
    return *this;
}

Val operator ++ (int){
    Val temp = *this;
    value++;
    return temp;
}

Val operator -- (int){
    Val temp = *this;
    value--;
    return temp;
}


};

std::ostream & operator << (std::ostream & o, const Val & v){
    return o << std::string(v);
}


int main(){
    Val v1(3);
    cout << v1 << endl;
    cout << ++v1 << endl;
    cout << v1++ << endl;
    cout << v1 << endl;

    return 0;

}



