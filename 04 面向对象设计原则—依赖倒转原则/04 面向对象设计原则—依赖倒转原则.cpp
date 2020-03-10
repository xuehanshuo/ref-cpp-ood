//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//——————————————————————————————————————————————————————————————————————————————————————————
/*The magic world is in danger, 
so the department has decided to train more and more specialized magicians instead of versatile ones,
now you need to design how this works
*/

//抽象层：
class AbsMagician {
public:
    virtual void doCast() const= 0;
};
//实现层1：
class FrostMaster:public AbsMagician {
public:
    void doCast() const{
        cout << "Frost is coming!" << endl;
    }
};
//实现层2：
class FireMaster :public AbsMagician {
public:
    void doCast() const {
        cout << "Fire is coming!" << endl;
    }
};
//中层业务：
void Solve(AbsMagician*magician) {
    magician->doCast();
    delete magician;
}
//高层业务：
void case01(){
    //AbsMagician* magician = new FrostMaster;
    //Solve(magician);
    Solve(new FrostMaster);
    Solve(new FireMaster);
}

//高层业务：向中层业务传new出来的实现层指针
//中层业务：用抽象层指针接收传进来的指针，调用抽象层的方法，delete传进来的指针
//抽象层：作为父类，提供方法纯虚函数
//实现层：继承父类，提供方法重写

int main() {

    case01();
    return 0;
}



