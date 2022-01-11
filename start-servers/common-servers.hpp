#ifndef __COMMON_SERVERS__
#define __COMMON_SERVERS__
#include <vector>
#include "servers.hpp"

class	CommonServers
{
	public:
		CommonServers(const std::pair<unsigned int, int> &ID);
		void	AddServer(const UniqueServer &server);
		bool	operator==(const UniqueServer &server);
		bool	operator==(const std::pair<unsigned int, int> &id);
		std::pair<unsigned int, int> GetIpPortCommonServer() const;
		void	Display() const;
	private:
		std::pair<unsigned int, int>	aCSID; // common server id (host, port)
		std::vector<UniqueServer> aServers;
	private:
		CommonServers() {}
		CommonServers&operator=(const CommonServers &){return *this;}
};

#endif
