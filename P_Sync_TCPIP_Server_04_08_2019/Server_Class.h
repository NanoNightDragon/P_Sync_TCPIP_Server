#pragma once


#ifndef __SERVER_CLASS__
#define __SERVER_CLASS__

#include <iostream>

#include <boost/asio.hpp>


using boost::asio::ip::tcp;

class Server_C {
private:
	boost::asio::io_service myIO_serv;
	
public:
	Server_C();
	void Server_Start();





};





#endif // !__SERVER_CLASS__
