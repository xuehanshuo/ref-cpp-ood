//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//开闭原则
//对扩展开放，对修改关闭
//增加功能是通过增加代码实现的，而不是修改源代码
//-----------------------------------------
//计算器
//抽象层提供传入数据和返回结果两个接口
//使用时利用父类指针new指向一个子类对象，调用父类接口完成操作
//记得delete

//抽象类
class AbstractCalculator {
public:
    virtual int getResult()const = 0;
    virtual void setValue(const int& a, const int& b) = 0;
};

//加法类
class AddCalculator :public AbstractCalculator{
public:
    void setValue(const int& a, const int& b) {
        this->a = a;
        this->b = b;
    }
    virtual int getResult()const {
        return a + b;
    }
private:
    int a;
    int b;
};

//减法类
class MinusCalculator :public AbstractCalculator {
public:
    void setValue(const int& a, const int& b) {
        this->a = a;
        this->b = b;
    }
    virtual int getResult()const {
        return a - b;
    }
private:
    int a;
    int b;
};

//乘法类
class MultiplyCalculator :public AbstractCalculator {
public:
    void setValue(const int& a, const int& b) {
        this->a = a;
        this->b = b;
    }
    virtual int getResult()const {
        return a * b;
    }
private:
    int a;
    int b;
};

int main() {
    AbstractCalculator* calculator = new AddCalculator;
    calculator->setValue(6, 10);
    cout << calculator->getResult() << endl;
    delete calculator;

    //delete 删除的只是new指向的堆部分，而不是指针本身，指针存放于栈中，最后由系统回收
    calculator=new MinusCalculator;
    calculator->setValue(6, 10);
    cout << calculator->getResult() << endl;
    delete calculator;
    return 0;
}

/*
 *
 *
 *
 *
 */

