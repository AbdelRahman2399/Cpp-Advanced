//Rationals by Bido
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>

class R{
    int num;
    int denum;

public:
    R() : num(0), denum(1){};
    R(int r) : num(r), denum(1){};
    R(int upper, int lower) : num(upper), denum(lower){};
    R(const R & o) : num(o.num), denum(o.denum) {}
    R & operator = (const R & o);
    R & operator = (R && o) noexcept;
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

    void Reset(){
        num = 0;
        denum = 1;
    }

    R(R && o) noexcept{
            puts("move ctor");
            num = o.num;
            denum = o.denum;
            o.Reset();
    }

    operator std::string (){
        if(denum == 1){
        return std::to_string(num);
        }else{
        return std::to_string(num) + "/" + std::to_string(denum);
        }
    }

    

};


std::ostream & operator << (std::ostream & o , R & r){
    return o << std::string(r);
}

R & R::operator = (const R & o){
    if(this != &o){
        num = o.num;
        denum = o.denum; 
    }
    return *this;
}

R & R::operator = (R && o) noexcept{
    if(this != &o){
        num = std::move(o.num);
        denum = std::move(o.denum);
        o.Reset();
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
    std::cout << f3 << std::endl;
    R f4;
    std::cout << f4 << std::endl;
    f3 = f4 + 14;
    std::cout << f3 << std::endl;
    f3 = 14 + f4;
    std::cout << f3 << std::endl;
    R f5 = std::move(f3);
    std::cout << f3 << std::endl;
    std::cout << f5 << std::endl;
    f3 = std::move(f2);
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;    



}