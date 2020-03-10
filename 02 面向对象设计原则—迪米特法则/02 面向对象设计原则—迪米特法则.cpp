//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//�����ط��� �ֽ�����֪ʶԭ��
//��¶�ӿڣ�����ϸ�ڱ�¶
//������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//¥�̳�����
class AbsBuilding {
public:
    virtual void sale()const = 0;
    virtual const string& getID()const {
        return mID;
    }
public:
    string mID;
};

//¥��A ��Ʒ��
class BuildingA:public AbsBuilding {
public:
    BuildingA(){
        AbsBuilding::mID="(High Quality)";
    }
    virtual void sale()const {
        cout << "The building A " << mID << " has already been saled!" << endl;
    }
};

//¥��B ��Ʒ��
class BuildingB :public AbsBuilding {
public:
    BuildingB() {
        AbsBuilding::mID = "(High Quality)";
    }
    virtual void sale()const {
        cout << "The building B " << mID << " has already been saled!" << endl;
    }
};

//�н���
//�û�Ӧ��ͨ���н��ṩ�Ľӿ��ҷ�Դ���н���Ӧ�÷ֱ���ʵ�ֲ���ϣ��������ݵ������й�����
//��������Ӧ�ô�Ÿ���ָ�룬���ݶ�̬���ԣ�ָ���������
//����ڹ��캯����Ҫnew����Ӧ��������������delete
class Mediator {
public:
    Mediator() {
        AbsBuilding* p = new BuildingA;
        v.push_back(p);
        p = new BuildingB;
        v.push_back(p);
    }

    //�ӿ�
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

//�ͻ���
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

