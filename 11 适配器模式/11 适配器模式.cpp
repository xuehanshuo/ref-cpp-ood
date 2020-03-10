//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
//将已经写好的接口，但是接口不符合要求
//将写好的接口转换成目标接口
//——————————————————————————————————————————————————————————————————————————————————————————
//原类
struct Print {
    void operator()(const int& a,const int& b)const {
        cout << a + b << endl;
    }
};

//目标接口
class TargetPrint {
public:
    virtual void operator()(const int& a)const = 0;
};

//具体实现
class Adapter :public TargetPrint{
public:
    Adapter(const int& a) :param(a){}
    virtual void operator()(const int& a)const {
        print(a, param);
    }
private:
    Print print;
    int param;
};

Adapter MyBind2nd(const int& param) {
    return Adapter(param);
}

int main() {
    vector<int> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyBind2nd(100));

    return 0;
}

/*
 *
 *
 *
 *
 */

