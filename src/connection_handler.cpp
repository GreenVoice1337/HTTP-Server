#include "connection_handler.hpp"

/*
******** PUBLIC PART ********
*/

Connection_handler::Connection_handler(boost::asio::io_context& io_context)
    : m_ref_io_context(io_context), m_acceptor(io_context, tcp::endpoint(tcp::v4(), 80))
{
    connectionID = 0;
    Start();
}

/*
******** PRIVATE PART ********
*/

void Connection_handler::Start()
{
    Http_server::httpPointer newHttpServer =
        Http_server::CreateInstance(m_ref_io_context);
    
    std::cout << "Ready to accept!\n";

    m_acceptor.async_accept(newHttpServer->GetSocket(),
        boost::bind(&Connection_handler::HandleAccept,
        this, 
        newHttpServer, 
        boost::asio::placeholders::error));
}

void Connection_handler::HandleAccept(
    Http_server::httpPointer newHttpServer, 
    const boost::system::error_code& error
    )
{
    if(!error)
    {
        int connId = connectionID;
        connectionID++;
        if(!fork())
        {
            newHttpServer->Run(connId);
        }
    }

    Start();
}