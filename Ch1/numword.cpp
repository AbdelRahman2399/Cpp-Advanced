#include <cstdio>
#include <iostream>
#include <string>

std::string sunit [] ={"","one","two","three","four","five","six","seven","eight","nine"};
std::string stens [] ={"","ten","twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
std::string steens [] ={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen", "nineteen"};
std::string spowers [] ={"","thousand","million","billion","trillion"};
std::string prefix = "hundred";


class Nums{
    long long int n;

public:

    Nums(const long long int & x) : n(x) {};
    int GetsNum (){return n;};
    Nums & operator = (long long int & x) {
        n = x;
        return *this;
    }

    std::string ToString (){
        return std::to_string(n);   
    }

    void ToPrint (){
        std::string s = ToString();
        for(int z = s.size();z>0; ){
            if((z-1)%3 == 0){
                int x = s[0] - '0';
                int index = (z-1)/3;
                std::cout << sunit[x] << " " << spowers[index];
                s = s.substr(1,z);
                z = s.size();
            }
            if((z+1)%3 == 0){
                int ten = s[0] - '0';
                int unit = s[1] - '0';
                int index = (z-2)/3;
                if(ten != 0){
                if(ten != 1){
                std::cout << " " << stens[ten] << " " << sunit[unit] << " " << spowers[index];
                }else{
                std::cout << " " << steens[unit] << " " << spowers[index];    
                }
                }
                s = s.substr(2,z);
                z = s.size();

            }

            if((z)%3 == 0){
                int hund = s[0] - '0';
                int ten = s[1] - '0';
                int unit = s[2] - '0';
                int index = (z/3)-1;
                if(hund != 0){
                if(ten != 1){
                std::cout << " " << sunit[hund] << " " << prefix << " " << stens[ten] << " " << sunit[unit] << " " << spowers[index];
                }else{
                std::cout << " " << sunit[hund] << " " << prefix << " " << steens[unit] << " " << spowers[index];
                }
                }
                s = s.substr(3,z);
                z = s.size();
            }


        }

            std::cout << std::endl;

    }

};




int main(){
    Nums number(900);
    std::cout << number.GetsNum() << std::endl;
    number = 237;
    std::cout << number.GetsNum() << std::endl;
    number.ToPrint();
    number = 23000;
    number.ToPrint();
    number = 1379333;
    number.ToPrint();
    number = 232323;
    number.ToPrint();



    return 0;
}