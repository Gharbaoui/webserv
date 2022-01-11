#include "servers.hpp"

UniqueServer::UniqueServer(const std::pair<unsigned int, int> &srv)
{
	aServerInfo = srv;
}


bool	UniqueServer::operator==(const UniqueServer &rhs)
{
	return (aServerInfo == rhs.aServerInfo);
}


std::pair<unsigned int, int>	UniqueServer::GetHostAndPort() const
{
	return aServerInfo;
}


void	 UniqueServer::Display() const
{
	std::cout << "Host :" << aServerInfo.first << " Port: " << aServerInfo.second << std::endl; 
}
