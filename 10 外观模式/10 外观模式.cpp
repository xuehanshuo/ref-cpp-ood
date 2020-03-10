//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//ktv模式打开->一系列都打开
//——————————————————————————————————————————————————————————————————————————————————————————
class ElementMaster {
public:
    void Call()const {
        cout << "ElementMaster is called!" << endl;
    }
    void Relax()const {
        cout << "ElementMaster now starts relaxing!" << endl;
    }
};
class DarkMaster {
public:
    void Call()const {
        cout << "DarkMaster is called!" << endl;
    }
    void Relax()const {
        cout << "DarkMaster now starts relaxing!" << endl;
    }
};
class LovelyMaster {
public:
    void Call()const {
        cout << "LovelyMaster is called!" << endl;
    }
    void Relax()const {
        cout << "LovelyMaster now starts relaxing!" << endl;
    }
};

class MagicMinistry {
public:
    MagicMinistry() {
        pElement = new ElementMaster;
        pDarkMaster = new DarkMaster;
        pLovelyMaster = new LovelyMaster;
    }
    void FightMood() {
        pElement->Call();
        pDarkMaster->Call();
        pLovelyMaster->Relax();
    }
    void DailyMood() {
        pElement->Relax();
        pDarkMaster->Relax();
        pLovelyMaster->Call();
    }
    ~MagicMinistry() {
        delete pElement ;
        delete pDarkMaster ;
        delete pLovelyMaster ;
    }
private:
    ElementMaster* pElement;
    DarkMaster* pDarkMaster;
    LovelyMaster* pLovelyMaster;
};

void case01() {
    MagicMinistry* pMagicMinistry = new MagicMinistry;
    pMagicMinistry->DailyMood();
    cout << "——————————————————————————————————" << endl;
    pMagicMinistry->FightMood();
    delete pMagicMinistry;
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

