#include <iostream>
#include <vector>
#include "servers-interface.hpp"

int main()
{

	std::vector<UniqueServer> vec { 
		UniqueServer(1, 10),
		UniqueServer(1, 9),
		UniqueServer(1, 1),
		UniqueServer(1, 1),
		UniqueServer(1, 4),
		UniqueServer(1, 10),
		UniqueServer(1, 9),
		UniqueServer(1, 10),
		UniqueServer(1, 10),
		UniqueServer(1, 40)
	};

	ServersInterface s(vec);

	ServersInterface::iterator first, last;
	first = s.begin();
	last = s.end();

	while (first != last)
	{
		first->Display();
		++first;
	}

}
