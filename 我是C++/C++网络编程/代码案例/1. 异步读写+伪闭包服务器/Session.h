#pragma once
#include<iostream>
#include<boost/asio.hpp>
#include<map>
#include<boost/uuid/uuid_generators.hpp>
#include<boost/uuid/uuid_io.hpp>
#include<string>
#include<memory>
using boost::asio::ip::tcp;

class Server;
//服务器端的接受请求和回声逻辑
class Session:public std::enable_shared_from_this<Session>
{
public:
	Session(boost::asio::io_context& ioc,Server* server) :_socket(ioc),_server(server) //接受上下文引用，用于创建socket
	{ 
		//生成唯一ID，两个括号是因为构造一个函数对象再加括号就是调用函数对象,random_generator相当于一个匿名对象
		boost::uuids::uuid a_uuid = boost::uuids::random_generator()(); 
		_uuid = boost::uuids::to_string(a_uuid);//转化类型写入
	};
	
	
	tcp::socket& Socket()//返回socket的引用，允许外部访问socket
	{
		return _socket;
	}

	void Start();//开始对话的窗口
	const std::string& Getuuid();//获取唯一ID

private:
	//异步读完成的回调函数，参数是错误操作码和实际读取的字节数
	void handle_read(const boost::system::error_code& error, size_t length,std::shared_ptr<Session> _self_shared);
	//异步写完成回调函数
	void handle_write(const boost::system::error_code& error, std::shared_ptr<Session> _self_shared);

	tcp::socket _socket;//socket对象
	enum {max_length=1024};//定义缓冲区的大小
	char _data[max_length];//数据缓冲区

	Server* _server;
	std::string _uuid;
};

//服务器端点
class Server
{
public://监听所有指定端口的所有信息
	Server(boost::asio::io_context& ioc, short port) :_ioc(ioc), _acceptor(ioc, tcp::endpoint(tcp::v4(), port)) 
	{
		start_accept();
	};

	void ClearSession(std::string uuid);
private:
	void start_accept();//启动监听

	//对方有连接就触发回调函数循环,参数是回调类Session和错误提示
	void handle_accept(std::shared_ptr<Session> new_session,const boost::system::error_code& error);

	boost::asio::io_context& _ioc;//上下文操作不允许拷贝操作

	tcp::acceptor _acceptor;//监听同意的acceptor对象

	std::map<std::string, std::shared_ptr<Session>> _sessions;//智能指针管理Session，保证生命周期
};