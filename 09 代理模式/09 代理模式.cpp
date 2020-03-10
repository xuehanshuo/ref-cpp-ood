//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;
//为其他对象提供一种代理(类对象)以控制对这个对象的访问
//强调需要有一个统一接口，约束代理行为，保证重写
//——————————————————————————————————————————————————————————————————————————————————————————
class AbsInterface {
public:
    virtual void run()const = 0;
};

class System :public AbsInterface{
public:
    virtual void run()const {
        cout << "Now the system starts running! Bingo!" << endl;
    }
};

class SystemProxy :public AbsInterface {
public:
    SystemProxy(const string& name, const string& word) :mUsername(name), mPassword(word) {
        this->sys = new System;
    }; 
    virtual void run()const {
        if (Check()) {
            cout << "Correct!" << endl;
            this->sys->run();
        }
        else {
            cout << "Wrong Input! ByeBye!" << endl;
        }
    }
private:
    bool Check()const {
        if (mUsername == "admin" && mPassword == "admin") {
            return true;
        }
        return false;
    }
    System* sys;
    string mUsername;
    string mPassword;
};

void case01() {
    SystemProxy* proxy = new SystemProxy("admin","admin");
    proxy->run();
    delete proxy;
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

