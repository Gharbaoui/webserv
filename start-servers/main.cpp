#include <iostream>
#include <vector>
#include <map>
#include "servers-interface.hpp"
#include "server-socket.hpp"


int main()
{
	
	std::map<int, ServerSocketLink>	FdToHostInfo;
	int k;
	ServerSocketLink	tmp;
	std::vector<UniqueServer> vec { 
		UniqueServer(std::make_pair(0, 1000)),
		UniqueServer(std::make_pair(0, 9000)),
		UniqueServer(std::make_pair(0, 1000)),
		UniqueServer(std::make_pair(0, 1000)),
		UniqueServer(std::make_pair(0, 4000)),
		UniqueServer(std::make_pair(0, 10000)),
		UniqueServer(std::make_pair(0, 9000)),
		UniqueServer(std::make_pair(0, 10000)),
		UniqueServer(std::make_pair(0, 10000)),
		UniqueServer(std::make_pair(0, 40000))
	};

	ServersInterface s(vec);


	s.Display();
	ServersInterface::iterator first, last;
	first = s.begin();
	last = s.end();
	
	while (first != last)
	{
		tmp = StartServer(first->GetIpPortCommonServer(), k);
		FdToHostInfo.insert(std::make_pair(k, tmp));
		++first;
	}

	std::map<int, ServerSocketLink>::iterator begin, end;
	begin = FdToHostInfo.begin();
	end = FdToHostInfo.end();
	while (begin != end)
	{
		std::cout << "Fd: " <<  begin->second.aFd << " Ip: " << begin->second.aConnectedServerInfo.first << " Port: " << begin->second.aConnectedServerInfo.second << std::endl;
		++begin;
	}

}
