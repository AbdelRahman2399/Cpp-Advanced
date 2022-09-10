#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

class Animal{
    string name;
    string type;
    string sound;
    Animal(){};

    friend ostream & farm(ostream & o,Animal a) ;
    friend string & AnimalName(Animal & a);

protected:

    Animal(const string & n, const string & t, const string & s) : name(n), type(t), sound(s) {}

public:

    string & GetName(){
        return name;
    }

    string & GetType(){
        return type;
    }

    string & GetSound() {
        return sound;
    }

    std::ostream & zoo(std::ostream & o) const {
    return o << name << " is in the zoo " << endl;
    }

    virtual ~Animal(){} //declare virtual destructor when there is a virtual function

    virtual void speak(){ //virtual => lets compiler know to use override version of the function in derived classes
        cout << sound << endl;
    }
    

};

class Fur{
    string FurType;
    Fur(){}

public:

    Fur(const string & f) : FurType(f){}
    string & furs(){
        return FurType;
    }
};

class Cat : public Animal, public Fur {
    int count;
public:
    Cat(const string & n) : Animal(n,"cat","meow") , Fur("silky"), count (0) {}
    int pet() {return ++ count;}
};

class Pig : public Animal {
    int count;
public:
    Pig(const string & n) : Animal(n,"pig","oink") , count (0) {}
    int feed() {return ++ count;}
    string latin() {return GetName() + "-ay";}
};

class Dog : public Animal {
    int count;
public:
    Dog(const string & n) : Animal(n,"dog","woof") , count (0) {}
    int walk() {return ++ count;}
    void speak(){
        cout << Animal::GetSound() << " awooooo" << endl;
    }
};

ostream & farm(ostream & o,Animal a) {
    return o << a.name << " is in the farm " << endl;
}

string & AnimalName(Animal & a) {
    return a.name;
}

int main(){
    Cat c1("fluffy");
    cout << c1.GetName() << " the " << c1.GetType() << " says " << c1.GetSound() << endl;
    Pig p1("arthur");
    cout << p1.latin() << " the " << p1.GetType() << " says " << p1.GetSound() << endl;
    cout << AnimalName(p1) << endl;
    p1.zoo(cout);
    cout << c1.GetName() << " has " << c1.furs() << " fur " << endl;
    Dog d1("max");
    d1.GetSound();

    Animal * ap[] = {&c1, &p1, &d1};
    for(auto p : ap){
        p->speak();
    }

}
