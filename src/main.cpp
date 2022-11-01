#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

#include "connection_handler.hpp"

using namespace boost::asio::ip;


int main()
{
    try {
        boost::asio::io_context io_context;
        Connection_handler conectionHandler(io_context);
        io_context.run();
    } catch(std::exception& e)
    {
        std::cerr << e.what() << '\n' ;
    }
    return 0;
}