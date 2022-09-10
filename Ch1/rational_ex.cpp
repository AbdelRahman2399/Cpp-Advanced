//Rationals by Bido
#include <cstdio>
#include <iostream>
#include <string>

class R{
    int num;
    int denum;

public:
    R() : num(0), denum(1){};
    R(int r) : num(r), denum(1){};
    R(int upper, int lower) : num(upper), denum(lower){};
    R(const R & o) : num(o.num), denum(o.denum) {}
    R & operator = (const R & o);
    /*R operator + (const R & o) const;
    R operator - (const R & o) const;
    R operator * (const R & o) const;
    R operator / (const R & o) const;*/
    int numerator() const{
        return num;
    }
    int denumerator() const{
        return denum;
    }
    float value();
    std::string print(){
        if(denum == 1){
        std::cout<< num << std::endl;
        }else{
        std::cout<< num << '/' << denum << std::endl;
        }
    }

};

R & R::operator = (const R & o){
    if(this != &o){
        num = o.num;
        denum = o.denum; 
    }
    return *this;
}

R operator + (const R & i,const R & o){
    int lower = i.denumerator() * o.denumerator();
    int upper = (i.denumerator()*o.numerator()) + (i.numerator()*o.denumerator());
    return R(upper,lower);
}

R operator - (const R & i,const R & o){
    int lower = i.denumerator() * o.denumerator();
    int upper = - (i.denumerator()*o.numerator()) + (i.numerator()*o.denumerator());
    return R(upper,lower);
}

R operator * (const R & i,const R & o){
    int lower = i.denumerator() * o.denumerator();
    int upper = i.numerator() * o.numerator();
    return R(upper,lower);
}

R operator / (const R & i,const R & o){
    int lower = i.denumerator() * o.numerator();
    int upper = i.numerator() * o.denumerator();
    return R(upper,lower);
}

float R::value(){
    return(num/denum);
}




int main(){
    R f1(1,2);
    R f2(1,3);
    R f3;
    f3 = f1 + f2;
    f3.print();
    R f4;
    f4.print();
    f3 = f4 + 14;
    f3.print();
    f3 = 14 + f4;
    f3.print();

}
