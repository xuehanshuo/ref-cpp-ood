//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//系统中只有一个A类型的对象
//static
/*1.构造函数私有化
 *2.增加static，私有的当前类的指针
 *3.提供static，对外的接口，可以让用户获得单例对象
 */
//单例对象释放问题：
//1.不可以提供接口去释放，太危险
//2.可以不释放，最后由系统回收堆中的对象
//3.可以嵌套类，嵌套类中只写析构函数，并定义对应的static变量放入全局区内，程序结束时会自动析构对象，调用析构函数，释放单例对象
//——————————————————————————————————————————————————————————————————————————————————————————
//为了避免再创建对象，使用static配合类名直接访问
class MagicCore {
public:
    static MagicCore* getInstance() {
        return MC;
    }
#if 0
    class Garbo {
        ~Garbo() {
            if (MC != NULL) {
                delete MC;
            }
        }
    };
#endif
private:
    MagicCore() {
        MC = new MagicCore;
    }
    static MagicCore* MC;
    //static Garbo garbo;
};
//static成员变量初始化
MagicCore* MagicCore::MC=NULL;


//单例分为懒汉式
//懒汉式遇到多线程，线程不安全
//需要加锁再解锁
class SingletonLasy {
public:
    static SingletonLasy* getInstance() {
        if (pSingleton == NULL) {
            return new SingletonLasy;
        }
        return pSingleton;
    }
private:
    SingletonLasy() {}
    static SingletonLasy* pSingleton;
};
SingletonLasy* SingletonLasy::pSingleton=NULL;

//以及饿汉式
//饿汉式是线程安全的，用饿汉式
class SingletonHungry {
public:
    static SingletonHungry* getInstance() {
        return pSingleton;
    }
private:
    SingletonHungry() { cout << "SingletonHungry starts running!" << endl; }
    static SingletonHungry* pSingleton;
};
SingletonHungry* SingletonHungry::pSingleton = new SingletonHungry;


int main() {
    //SingletonHungry::getInstance()->getInstance()->getInstance();
    //构造比main先执行
    cout << "Main starts running!" << endl;
    return 0;
}

