#include "Session.h"
#include<iostream>
using namespace std;

void Session::Start()
{
	memset(_data, 0, max_length);//把数组置为零

	//异步操作的函数,参数1是数据缓冲区。参数2是回调函数，在操作完成时被调用，使用bind绑定之后就会调用handle_write
	_socket.async_read_some(boost::asio::buffer(_data,max_length),
		std::bind(&Session::handle_read, this, placeholders::_1, placeholders::_2,shared_from_this()));
}

const std::string& Session::Getuuid()
{
	return _uuid;
}

//回声服务器，上面的start函数服务器异步接受到客户端发的消息之后服务器再接受之后回声回复一下
void Session::handle_read(const boost::system::error_code& error, size_t length,std::shared_ptr<Session> _self_shared)
{
	if (!error)//没有错误就输出接受到的数据
	{  
		cout << "sever recive data is" << _data << endl;

		//异步回写数据给客户端
		boost::asio::async_write(_socket, boost::asio::buffer(_data, length),
			std::bind(&Session::handle_write, this, placeholders::_1,_self_shared));
	}
	else
	{
		cout << "read error" << endl;
		_server->ClearSession(_uuid);
	}
}

//上面的回声服务器响应之后继续调用这个函数继续下一次异步读取，循环下去
void Session::handle_write(const boost::system::error_code& error,std::shared_ptr<Session> _self_shared)
{
	if (!error)
	{
		memset(_data, 0, max_length);
		_socket.async_read_some(boost::asio::buffer(_data, max_length),
			std::bind(&Session::handle_read, this, placeholders::_1,placeholders::_2, _self_shared));
	}
	else
	{
		cout << "write error!" << error.value() << endl;
		_server->ClearSession(_uuid);
	}
}

void Server::start_accept()
{
	shared_ptr<Session> new_session = make_shared<Session>(_ioc, this);
	//Session* new_session = new Session(_ioc);

	//有连接时处理对端连接信息,第一个从参数是客户端连接的socket，第二个参数是回调函数，使用bind绑定到了handle_accept，这个函数专门对接Session回调类
	_acceptor.async_accept(new_session->Socket(),
		std::bind(&Server::handle_accept, this, new_session, placeholders::_1));
}

//回调函数的处理
void Server::handle_accept(shared_ptr<Session> new_session, const boost::system::error_code& error)
{
	if (!error)
	{
		new_session->Start();
		_sessions.insert(make_pair(new_session->Getuuid(), new_session));
	}
	else
	{

	}
	start_accept();//异步处理完一个连接后继续监听
}

void Server::ClearSession(std::string uuid)
{
	_sessions.erase(uuid);
}