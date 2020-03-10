//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//继承和组合，优先使用组合。
//——————————————————————————————————————————————————————————————————————————————————————————
//实现人开车兜风
//首先对于车，有一个抽象类车和几个具体实现的车，分别提供了兜风虚函数和兜风函数重写，这个地方应该用到继承
//之后对于人，人不应该使用继承，继承车的函数，这样人就与具体的车发生了耦合，不同车还需要对应被继承于多个人的类
//所以应该把抽象类车的指针当做人类的成员属性，初始化时赋予它(绑定一种车)，之后用过抽象类的兜风操作完成实现

class AbsCar {
public:
    virtual void drive()const = 0;
};

class Benchi :public AbsCar{
public:
    void drive()const {
        cout << "Benchi is driving now!" << endl;
    }
};

class Baoma :public AbsCar {
public:
    void drive()const {
        cout << "Baoma is driving now!" << endl;
    }
};

class Person {
public:
    void SetCar(AbsCar*car) {
        this->car = car;
    }
    //可以类内释放或者类外释放，类内释放则可以放进析构函数中，或者任意想放的位置
    //放在兜风函数中，则不能用const修饰了，但是可以满足随时换车，改变car指向，且不会造成内存泄漏
    void Doufeng() {
        this->car->drive();
        if (this->car != NULL) {
            delete this->car;
            this->car = NULL;
        }
    }
#if 0
    ~Person() {
        if (this->car != NULL) {
            delete this->car;
            this->car = NULL;
        }
    }
#endif
private:
    AbsCar* car;
};

void test01() {
#if 0
    Person p1;
    //使用new而不是自己定义出来一辆车，再传进去作为参数
    p1.SetCar(new Baoma);
    p1.Doufeng();
#endif
    Person* p = new Person;
    p->SetCar(new Baoma);
    p->Doufeng();

    //这里需要注意，如果对car的delete放在了析构中，则会内存泄漏(没delete就换车了)，所以应该把delete放在兜风函数中
    p->SetCar(new Benchi);
    p->Doufeng();
    delete p;
}

int main() {

    test01();
    return 0;
}

/*
 *
 *
 *
 *
 */

