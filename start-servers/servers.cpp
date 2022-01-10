#include "servers.hpp"

UniqueServer::UniqueServer(int host, int port) : aHost(host), aPort(port) {}
bool	UniqueServer::operator==(const UniqueServer &rhs)
{
	if (aHost == rhs.aHost)
	{
		if (aPort == rhs.aPort)
			return true;
	}
	return false;
}


std::pair<int, int>	UniqueServer::GetHostAndPort() const
{
	return std::make_pair(aHost, aPort);
}


void	 UniqueServer::Display() const
{
	std::cout << "Host :" << aHost << " Port: " << aPort << std::endl; 
}
