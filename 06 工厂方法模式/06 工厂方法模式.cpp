//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
/*工厂方法模式
——>简单工厂模式+开闭原则
——>对应每个实现层建立工厂，添加工厂抽象层
优点：
1.满足了开闭原则
缺点：
1.类的个数成倍增加
*/
//——————————————————————————————————————————————————————————————————————————————————————————
class Fruit {
public:
    virtual void showName()const = 0;
};

class Orange :public Fruit {
public:
    virtual void showName()const {
        cout << "I am a cute orange!" << endl;
    }
};
class Apple :public Fruit {
public:
    virtual void showName()const {
        cout << "I am an ugly Apple!" << endl;
    }
};
class Banana :public Fruit {
public:
    virtual void showName()const {
        cout << "I am a horny Banana!" << endl;
    }
};

class FruitFactory {
public:
    virtual Fruit* CreateFruit() = 0;
};

class OrangeFactory :public FruitFactory {
public:
    virtual Fruit* CreateFruit() {
        return new Orange;
    }
};
class AppleFactory :public FruitFactory {
public:
    virtual Fruit* CreateFruit() {
        return new Apple;
    }
};
class BananaFactory :public FruitFactory {
public:
    virtual Fruit* CreateFruit() {
        return new Banana;
    }
};

void case01() {
    Fruit* myfruit=NULL;
    FruitFactory* myfactory = NULL;

    myfactory = new OrangeFactory;
    myfruit=myfactory->CreateFruit();
    myfruit->showName();

    delete myfruit;
    delete myfactory;

    myfactory = new BananaFactory;
    myfruit = myfactory->CreateFruit();
    myfruit->showName();
    
    delete myfruit;
    delete myfactory;
}

int main() {
    
    case01();
    return 0;
}