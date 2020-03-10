//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//替代继承 动态给一个类增加功能
//——————————————————————————————————————————————————————————————————————————————————————————
class AbsHero {
public:
    virtual void ShowStatus() = 0;
public:
    int mHp;
    int mMp;
};

class FrostMaster :public AbsHero {
public:
    FrostMaster(){
        this->mHp = 0;
        this->mMp = 0;
    }
    virtual void ShowStatus() {
        cout << "HP is " << this->mHp << endl
            << "MP is " << this->mMp << endl;
    }
};

class AbsEquipment :public AbsHero {
public:
    AbsEquipment(AbsHero* hero):hero(hero){}
    virtual void ShowStatus() {};
public:
    AbsHero* hero;
};

class Stick :public AbsEquipment {
public:
    Stick(AbsHero* hero):AbsEquipment(hero){}
    //新加的功能，用父类指针承接，父类指针不能延申调用，所以应在virtual中自己调用
    void PutOn() {
        this->mHp = this->hero->mHp;
        this->mMp = this->hero->mMp+1000;
        delete this->hero;
    }
    virtual void ShowStatus() {
        PutOn();
        cout << "HP is " << this->mHp << endl
            << "MP is " << this->mMp << endl;
    }
};

void case01() {
    AbsHero* hero = new FrostMaster;
    hero->ShowStatus();
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    hero = new Stick(hero);
    hero->ShowStatus();
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

