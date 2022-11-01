#include <iostream>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <unistd.h>
#include <stdlib.h>

using namespace boost::asio::ip;

class Http_server
{
private:
    tcp::socket m_socket;
public:
    typedef boost::shared_ptr<Http_server> httpPointer;

    static httpPointer CreateInstance(boost::asio::io_context&);

    tcp::socket& GetSocket();

    void Run(int connectionID);

private:


    Http_server(boost::asio::io_context& io_context);

};