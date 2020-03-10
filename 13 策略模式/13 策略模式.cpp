//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//不继承具体类，而是保存抽象类指针，(可继承也可不继承抽象类，因为我们已经有一个抽象类指针了)，接收具体类的对象，调用抽象类方法，传什么就实现那一种的方法
//——————————————————————————————————————————————————————————————————————————————————————————
class WeaponStategy {
public:
    virtual void UseWeapon() const= 0;
};

class Knife :public WeaponStategy {
public:
    virtual void UseWeapon() const {
        cout << "Use Knife! Chua!" << endl;
    }
};

class Gun :public WeaponStategy {
public:
    virtual void UseWeapon() const {
        cout << "Use Gun! Boom!" << endl;
    }
};

class Person{
public:
    Person() {
        this->weapon = NULL;
    }
    void setWeapon(WeaponStategy* weapon) {
        if (this->weapon != NULL) {
            delete this->weapon;
        }
        this->weapon = weapon;
    }
    void Fight() const {
        this->weapon->UseWeapon();
    }
private:
    WeaponStategy* weapon;
};

void case01() {
    Person* p = new Person;

    //WeaponStategy* knife = new Knife;
    //p->setWeapon(knife);
    //p->Fight();

    p->setWeapon(new Knife);
    p->Fight();
    p->setWeapon(new Gun);
    p->Fight();
    delete p;
}
int main() {

    case01();
    return 0;
}

/*
 *
 *
 *
 *
 */

