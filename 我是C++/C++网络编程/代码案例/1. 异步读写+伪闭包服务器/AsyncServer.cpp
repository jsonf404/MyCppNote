#include <iostream>
#include<boost/asio.hpp>
#include"Session.h"
int main()
{
    try
    {
        using namespace std;
        boost::asio::io_context ioc;

        Server s(ioc, 10086);
        ioc.run();
    }
    catch(std::exception& e)
    {
        std::cerr << "Exception:" << e.what() << std::endl;
    }
    return 0;
}

