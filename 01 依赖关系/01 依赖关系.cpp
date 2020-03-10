//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

//-----------------------------------------
class KDLK {
public:
    void run()const {
        cout << "KDLK is running!";
    }
private:
};

//依赖关系——car作为参数传进来了，车不属于人
class Person {
public:
    void GoToWork(KDLK*car)const {
        car->run();
    }
public:
};

//关联关系——车和人固定关系，车属于人
class Person {
public:
    void GoToWork()const {
        car->run();
    }
public:
    KDLK* car;
};
int main() {


    return 0;
}

/*
 *
 *
 *
 *
 */

