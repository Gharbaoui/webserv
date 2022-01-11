#ifndef __SERVERS_INTERFACE__
#define __SERVERS_INTERFACE__

#include "common-servers.hpp"

class ServersInterface
{
	public:
		typedef	std::vector<CommonServers>::iterator	iterator;
		ServersInterface(const std::vector<UniqueServer> &srvs);
		void	AddServer(const UniqueServer &srv);
		void	Display() const;
		// operator [] i will give it host , port pair and will return refernce 
		CommonServers	&operator[](const std::pair<unsigned int, int> &id);
		iterator	begin();
		iterator	end();
	private:
		CommonServers			aNotFoundCS; // not found common server will be use in operator[] because i awnt to return refernce i will return it if i could not found in my servers variable
		std::vector<CommonServers>	aServers;
};

#endif
