//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//纯虚函数+多态
//——————————————————————————————————————————————————————————————————————————————————————————
class MagicTemplate {
public:
    virtual void DrawEnergy()const = 0;
    virtual void Prepare()const = 0;
    virtual void Sing()const = 0;
    virtual void Cast()const = 0;
    //子类不会改变算法步骤次序
    void DoTheTrick()const {
        DrawEnergy();
        Prepare();
        Sing();
        Cast();
    }
};

class FrostMaster :public MagicTemplate {
public:
    virtual void DrawEnergy()const {
        cout << "The Ice gives me power!" << endl;
    }
    virtual void Prepare()const {
        cout << "I am ready to use ice to kick you ass!" << endl;
    }
    virtual void Sing()const {
        cout << "ICE A~~~~~~~!" << endl;
    }
    virtual void Cast()const {
        cout << "BOOM shakalaka!" << endl;
    }
};

void case01() {
    MagicTemplate* magician = new FrostMaster;
    magician->DoTheTrick();
    delete magician;

    //Do the trick成员方法被继承下来了
    FrostMaster* magician2 = new FrostMaster;
    magician2->DoTheTrick();
    delete magician2;
}
int main() {

    case01();
    system("pause");
    return 0;
}

/*
 *
 *
 *
 *
 */

