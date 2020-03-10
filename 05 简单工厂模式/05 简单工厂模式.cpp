//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
/*简单工厂模式
——>自己写的业务函数中创建对象很麻烦，我不想创建，我只想拿来用。
——>创建工厂类，让工厂替我们创建对象。
——>传入参数，让工厂if-else判断我们要创建什么对象。
优点：
1.客户端和具体实现类解耦
2.对于某些创建过程复杂的对象，不用考虑这些了
缺点：
1.简单工程模式，增加新的功能是通过修改源代码实现，不符合开闭原则
2.这个类职责过重，发生问题，会影响很多模块
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
    //使用static可以让我们不创建工厂对象，只使用里面的功能
    static Fruit* CreateFruit(const string& fruitname) {
        if (fruitname == "Banana") {
            return new Banana;
        }
        else if (fruitname == "Orange") {
            return new Orange;
        }
        else {
            return new Apple;
        }
    }
};

void case01() {
    Fruit* myfruit = FruitFactory::CreateFruit("Orange");
    myfruit->showName();
    delete myfruit;
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

