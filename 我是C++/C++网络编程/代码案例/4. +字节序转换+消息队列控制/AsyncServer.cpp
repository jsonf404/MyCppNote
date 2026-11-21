#include <iostream>
#include "CServer.h"
using namespace std;

int main()
{
    try {
        boost::asio::io_context  io_context;//所有的异步事件都会放入ioc队列中，自动轮询异步
        CServer s(io_context, 10086);
        io_context.run();//必须run，让所有操作开始执行
    }
    catch(std::exception & e){
        std::cerr << "Exception: " << e.what() <<  endl;
    }
    boost::asio::io_context io_context;
}