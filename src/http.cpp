#include "http.hpp"

/*
******** PUBLIC PART ********
*/

Http_server::httpPointer Http_server::CreateInstance(boost::asio::io_context& io_context)
{
    return httpPointer(new Http_server(io_context));
}

tcp::socket& Http_server::GetSocket()
{
    return m_socket;
}

void Http_server::Run(int connectionId)
{
    std::string messageForRemote = "Your Connection ID: " + std::to_string(connectionId) + '\n';
    boost::asio::const_buffer buff(messageForRemote.data(), messageForRemote.length());
    std::cout << "Connection from: " << m_socket.remote_endpoint().address().to_string() << '\n';
    std::cout << "Sending something back!\n";
    for(int i = 0; i < 10; ++i)
    {
        m_socket.write_some(buff);
        sleep(1); 
    }
}


/*
******** PRIVATE PART ********
*/

Http_server::Http_server(boost::asio::io_context& io_context) : m_socket(io_context)
{

}