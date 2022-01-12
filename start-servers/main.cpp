#include <iostream>
#include <vector>
#include <map>
#include "servers-interface.hpp"
#include "server-socket.hpp"


int main()
{
	std::map<int, int> FdToIndex; // i give you fd you give index in ServersInterface vector
	
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

	ServersInterface s(vec); // we will be as refrence
	ServersInterface::iterator	first, last;
	first = s.begin();
	last = s.end();
	int index = 0;
	
	while (first != last)
	{
		FdToIndex.insert(StartServer(first->GetIpPortCommonServer(), index));
		++index;
		++first;
	}

	s.Display();

}
