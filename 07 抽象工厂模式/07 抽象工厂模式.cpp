//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//抽象工厂针对产品族，而不是产品等级结构
//产品族满足开闭原则，等级结构不满足
//——————————————————————————————————————————————————————————————————————————————————————————
class AbsApple {
public:
    virtual void showName()const = 0;
};
class ChinaApple:public AbsApple {
public:
    virtual void showName()const {
        cout << "This is an apple from China!" << endl;
    }
};
class USApple :public AbsApple {
public:
    virtual void showName()const {
        cout << "This is an apple from US!" << endl;
    }
};
class KoreaApple :public AbsApple {
public:
    virtual void showName()const {
        cout << "This is an apple from Korea!" << endl;
    }
};

class AbsOrange {
public:
    virtual void showName()const = 0;
};
class ChinaOrange :public AbsOrange {
public:
    virtual void showName()const {
        cout << "This is an orange from China!" << endl;
    }
};
class USOrange :public AbsOrange {
public:
    virtual void showName()const {
        cout << "This is an orange from US!" << endl;
    }
};
class KoreaOrange :public AbsOrange {
public:
    virtual void showName()const {
        cout << "This is an orange from Korea!" << endl;
    }
};

class AbsBanana {
public:
    virtual void showName()const = 0;
};
class ChinaBanana :public AbsBanana {
public:
    virtual void showName()const {
        cout << "This is an banana from China!" << endl;
    }
};
class USBanana :public AbsBanana {
public:
    virtual void showName()const {
        cout << "This is an banana from US!" << endl;
    }
};
class KoreaBanana :public AbsBanana {
public:
    virtual void showName()const {
        cout << "This is an banana from Korea!" << endl;
    }
};


class AbsFactory {
public:
    virtual AbsApple* CreateApple()const = 0;
    virtual AbsBanana* CreateBanana()const = 0;
    virtual AbsOrange* CreateOrange()const = 0;
};
class ChinaFactory :public AbsFactory {
public:
    virtual AbsApple* CreateApple()const {
        return new ChinaApple;
    }
    virtual AbsBanana* CreateBanana()const {
        return new ChinaBanana;
    }
    virtual AbsOrange* CreateOrange()const {
        return new ChinaOrange;
    }
};
class USFactory :public AbsFactory {
public:
    virtual AbsApple* CreateApple()const {
        return new USApple;
    }
    virtual AbsBanana* CreateBanana()const {
        return new USBanana;
    }
    virtual AbsOrange* CreateOrange()const {
        return new USOrange;
    }
};
class KoreaFactory :public AbsFactory {
public:
    virtual AbsApple* CreateApple()const {
        return new KoreaApple;
    }
    virtual AbsBanana* CreateBanana()const {
        return new KoreaBanana;
    }
    virtual AbsOrange* CreateOrange()const {
        return new KoreaOrange;
    }
};

void case01() {
    //针对每个抽象层创建指针
    AbsFactory* myfactory = NULL;
    AbsApple* myapple = NULL;
    AbsOrange* myorange = NULL;
    AbsBanana* mybanana = NULL;

    //中国工厂
    myfactory = new ChinaFactory;
    myapple = myfactory->CreateApple();
    myorange = myfactory->CreateOrange();
    mybanana = myfactory->CreateBanana();

    myapple->showName();
    myorange->showName();
    mybanana->showName();

    delete mybanana;
    delete myorange;
    delete myapple;
    delete myfactory;
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

