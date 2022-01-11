#ifndef __SERVER_SOCKET__
#define __SERVER_SOCKET__

#include <utility>
#include "common-headers.hpp"


// this class it's primary goal is to identify which server shoudl serve the requist
class	ServerSocketLink
{
	public:
		ServerSocketLink();
		ServerSocketLink(const std::pair<unsigned int, int> &, int fd);
		ServerSocketLink(const ServerSocketLink &);
		ServerSocketLink	&operator=(const ServerSocketLink &rhs);
		bool	operator<(const ServerSocketLink &rhs);
//	private:
		std::pair<unsigned int, int> aConnectedServerInfo;
		int	aFd;
};

ServerSocketLink	StartServer(const std::pair<unsigned int, int> &srvinfo, int &key);

#endif
