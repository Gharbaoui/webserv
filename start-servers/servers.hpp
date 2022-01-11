#ifndef __SERVERS__
#define __SERVERS__
#include <utility>
#include <iostream>
#include "common-headers.hpp"

class UniqueServer
{
	public:
		UniqueServer(const std::pair<unsigned int, int> &);
		bool	operator==(const UniqueServer &rhs);
		std::pair<unsigned int, int>	GetHostAndPort() const;
		void	Display() const;
	private:
		std::pair<unsigned int, int> aServerInfo;// ip , port in this order
};

#endif 
