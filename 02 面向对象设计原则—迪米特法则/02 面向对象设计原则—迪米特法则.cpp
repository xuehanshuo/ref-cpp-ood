//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//迪米特法则 又叫最少知识原则
//暴露接口，减少细节暴露
//——————————————————————————————————————————————————————————————————————————————————————————
//楼盘抽象类
class AbsBuilding {
public:
    virtual void sale()const = 0;
    virtual const string& getID()const {
        return mID;
    }
public:
    string mID;
};

//楼盘A 高品质
class BuildingA:public AbsBuilding {
public:
    BuildingA(){
        AbsBuilding::mID="(High Quality)";
    }
    virtual void sale()const {
        cout << "The building A " << mID << " has already been saled!" << endl;
    }
};

//楼盘B 低品质
class BuildingB :public AbsBuilding {
public:
    BuildingB() {
        AbsBuilding::mID = "(High Quality)";
    }
    virtual void sale()const {
        cout << "The building B " << mID << " has already been saled!" << endl;
    }
};

//中介类
//用户应该通过中介提供的接口找房源，中介则应该分别与实现层耦合，汇总数据到容器中供查找
//汇总数据应该存放父类指针，根据多态特性，指向子类对象
//如果在构造函数中要new，则应该在析构函数中delete
class Mediator {
public:
    Mediator() {
        AbsBuilding* p = new BuildingA;
        v.push_back(p);
        p = new BuildingB;
        v.push_back(p);
    }

    //接口
    AbsBuilding* getResult(const string& request) {
        for (vector<AbsBuilding*>::iterator it = v.begin(); it != v.end(); ++it) {
            if ((*it)->mID == request) {
                return *it;
            }
        }
        return NULL;
    }

    ~Mediator(){
        for (vector<AbsBuilding*>::iterator it = v.begin(); it != v.end(); ++it) {
            if (*it != NULL) {
                delete* it;
                *it = NULL;
            }
        }
    }
public:
    vector<AbsBuilding*> v;
};

//客户端
void test01(){
    Mediator* p = new Mediator;
    AbsBuilding* ret=p->getResult("(High Quality)");
    if (ret != NULL) {
        ret->sale();
    }
    else {
        cout << "No such building left!" << endl;
    }
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

