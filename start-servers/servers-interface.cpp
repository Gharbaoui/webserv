#include "servers-interface.hpp"

void	ServersInterface::AddServer(const UniqueServer &srv)
{
	std::vector<CommonServers>::iterator first(aServers.begin());
	std::vector<CommonServers>::iterator last(aServers.end());
	
	while (first != last)
	{
		if (*first == srv)
		{
			first->AddServer(srv);
			return ;
		}
		++first;
	}
	aServers.push_back(srv.GetHostAndPort());
	aServers.back().AddServer(srv);
}


ServersInterface::ServersInterface(const std::vector<UniqueServer> &srvs) : aNotFoundCS(std::make_pair(-1, -1))
{
	std::vector<UniqueServer>::const_iterator first, last;
	
	first = srvs.begin();
	last = srvs.end();
	while (first != last)
	{
		this->AddServer(*first);
		++first;
	}
}

void	ServersInterface::Display() const
{
	std::vector<CommonServers>::const_iterator first(aServers.begin()), last(aServers.end());
	while (first != last)
	{
		first->Display();
		++first;
	}
}

CommonServers	&ServersInterface::operator[](const std::pair<unsigned int, int> &id)
{
	std::vector<CommonServers>::iterator first, last;

	first = aServers.begin();
	last = aServers.end();
	while (first != last)
	{
		if (*first == id)
			return *first;
		++first;
	}
	return aNotFoundCS;
}


ServersInterface::iterator	ServersInterface::begin()
{
	return aServers.begin();
}

ServersInterface::iterator	ServersInterface::end()
{
	return aServers.end();
}
