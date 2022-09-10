#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <memory>
using namespace std;

void prints (string & s){
    if(s == ""){
        cout << "empty" << endl;
    }else{
        cout << s << endl;
    }
}


int main(){
    string s1 = "Hello!";
    string s2 = "Goodbye!";
    prints(s1);
    prints(s2);
    swap(s1,s2);
    prints(s1);
    prints(s2);

    string s3 = move(s2); // data in s2 will be oved to s3, s2 will then be empty
    prints(s1);
    prints(s2);
    prints(s3);   


    return 0;    

}