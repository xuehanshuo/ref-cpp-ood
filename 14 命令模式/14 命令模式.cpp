//This is a C++ program
//Designed and supported by Hodor
//High cohesion & Low coupling
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<Windows.h>

using namespace std;
//协议处理类，服务器类，处理接口，具体协议类
//queue
//——————————————————————————————————————————————————————————————————————————————————————————
//协议处理类
class HandleClientProtocal {
public:
    void AddMoney()const {
        cout << "Money is added!" << endl;
    }
    void AddLevel() const{
        cout << "Level is raised!" << endl;
    }
};

//处理接口
class Interface {
public:
    virtual void Handle() const= 0;
};

//具体协议1
class AddMoneyCommand: public Interface{
public:
    AddMoneyCommand(HandleClientProtocal* protocal) {
        this->protocal = protocal;
    }
    virtual void Handle()const {
        protocal->AddMoney();
    }
public:
    HandleClientProtocal* protocal;
};


//具体协议2
class AddLevelCommand : public Interface {
public:
    AddLevelCommand(HandleClientProtocal* protocal) {
        this->protocal = protocal;
    }
    virtual void Handle() const {
        protocal->AddLevel();
    }
public:
    HandleClientProtocal* protocal;
};

//服务器类
class Server {
public:
    void AddRequest(Interface* request) {
        mRequest.push(request);
    }
    void HandleRequest() {
        while (!mRequest.empty()) {
            //模拟服务器2s处理一个协议
            Sleep(2000);
            Interface* p = mRequest.front();
            p->Handle();
            mRequest.pop();
        }
    }
public:
    queue<Interface*> mRequest;
    
};

void case01() {
    //这个协议处理类的对象生成放在外面是有意义的，可能是不同的协议处理类，又可以实现一层多态
    HandleClientProtocal* protocal = new HandleClientProtocal;
    Interface* request1 = new AddMoneyCommand(protocal);
    Interface* request2 = new AddLevelCommand(protocal);
    Server* server1 = new Server;
    server1->AddRequest(request1);
    server1->AddRequest(request2);
    //此处不用delete，统一指针换指向考虑delete
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

