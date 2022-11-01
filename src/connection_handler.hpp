#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include "http.hpp"


using namespace boost::asio::ip;

class Connection_handler
{
public:
    Connection_handler(boost::asio::io_context&);
private:
    int connectionID;
    boost::asio::io_context& m_ref_io_context;
    tcp::acceptor m_acceptor;

    void Start();
    void HandleAccept(Http_server::httpPointer newHttpServer, const boost::system::error_code& error);
};