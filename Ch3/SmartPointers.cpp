#include <cstdio>
#include <iostream>
#include <string>
#include <memory>
#include <utility>

class Words{
    std::string txt;
public:
    Words() : txt("") {}
    Words(const std::string & s) : txt(s) {puts("ctor");}
    std::string GetWord(){
        if(this){
        return txt;
        }else{
        return "nullptr";
        }
    }
    operator std::string (){
        return txt;
    }
    ~Words(){puts("dtor");}

    
};

    std::ostream & operator << (std::ostream & o, Words * w){
        return o << w->GetWord();
    }

    void prints (std::shared_ptr<Words> & o){
        std::cout << "string :" << o->GetWord() << std::endl;
        std::cout << "ptr count:" << o.use_count() << std::endl;
    }

    void prints (std::weak_ptr<Words> & o){
        std::cout << "string :" << o.lock()->GetWord() << std::endl;
    }

int main(){
    std::shared_ptr<Words> W1(new Words("Hello!"));
    std::cout << W1 << std::endl;
    prints(W1);
    auto W2 = std::weak_ptr<Words>(W1);
    std::cout << W1 << std::endl;
    prints(W2);
    W2.reset();
    prints(W2);

    return 0;
}

