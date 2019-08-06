#include "Server_Class.h"


Server_C::Server_C()
{}

void Server_C::Server_Start()
{
	boost::system::error_code error_c;

	tcp::acceptor Acceptor(myIO_serv, tcp::endpoint(tcp::v4(), 7447));
	/*
	for (;;)
	{
		tcp::socket Socket(myIO_serv);
		Acceptor.accept(Socket);
		boost::asio::streambuf buff;
		char buf[1024];
		//boost::asio::read(Socket, boost::asio::buffer(buf,3), error_c);
		size_t len = Socket.read_some(boost::asio::buffer(buf), error_c);
		//const char * text = boost::asio::buffer_cast<const char*>(buff.data());
		boost::asio::write(Socket, boost::asio::buffer("Hi! obtain"));
		std::cout << "len: " << len << " " << buf;
		Socket.close();
	}
	*/
	//

	tcp::socket Socket(myIO_serv);
	Acceptor.accept(Socket);
	char buf[1024];
	boost::asio::write(Socket, boost::asio::buffer("Hi! obtain"));
	size_t len;
	for (;Socket.is_open();)
	{

		size_t len = Socket.read_some(boost::asio::buffer(buf), error_c);
		if (error_c) {
			std::cout << error_c; break;
		}
		std::cout << "len: " << len << " " << buf << "is_open: " << Socket.is_open() << '\n';
		
	}
	system("pause");
	



}