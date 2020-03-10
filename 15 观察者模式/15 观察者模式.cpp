//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>

using namespace std;
//一个对象改变，其他对象跟着改变
//应该提供抽象观察者和抽象观察目标
//每个具体观察目标应该使用随时能从中间删除的list容器存放观察者名单
//——————————————————————————————————————————————————————————————————————————————————————————
class AbsHero {
public:
    virtual void update()const = 0;
};

class FrostMaster:public AbsHero{
public:
    FrostMaster() {
        cout << "FrostMaster is here! Now feel the cold!" << endl;
    }
    virtual void update() const {
        cout << "FrostMaster now can relax for a while..." << endl;
    }
};

class FireMaster :public AbsHero {
public:
    FireMaster() {
        cout << "FireMaster is here! Now feel the heat!" << endl;
    }
    virtual void update() const {
        cout << "FireMaster now can relax for a while..." << endl;
    }
};

class AbsBoss {
public:
    virtual void addHero(AbsHero* hero) = 0;
    virtual void deleteHero(AbsHero* hero) = 0;
    virtual void notify() = 0;
};

class DarkLord:public AbsBoss {
public:
    virtual void addHero(AbsHero* hero) {
        HeroList.push_back(hero);
    }
    virtual void deleteHero(AbsHero* hero) {
        HeroList.remove(hero);
    }
    virtual void notify(){
        for (const auto& c : HeroList) {
            c->update();
        }
    }
    
public:
    list<AbsHero*> HeroList;
};

void case01() {
    AbsBoss* pBoss = new DarkLord;
    AbsHero* pHero1 = new FrostMaster;
    AbsHero* pHero2 = new FireMaster;

    pBoss->addHero(pHero1);
    pBoss->deleteHero(pHero2);
    pBoss->notify();
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

