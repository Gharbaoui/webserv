#ifndef __SERVERS__
#define __SERVERS__
#include <utility>
#include <iostream>
#include "common-headers.hpp"

class UniqueServer
{
	public:
		UniqueServer(int host, int port);
		bool	operator==(const UniqueServer &rhs);
		std::pair<int, int>	GetHostAndPort() const;
		void	Display() const;
	private:
		int	aHost;
		int	aPort;
};

#endif 
