#include "server-socket.hpp"


ServerSocketLink::ServerSocketLink() {}

ServerSocketLink::ServerSocketLink(const std::pair<unsigned int, int> &srvInfo, int fd)
{
	aConnectedServerInfo = srvInfo;
	aFd = fd;
}

ServerSocketLink::ServerSocketLink(const ServerSocketLink &cp)
{
	*this = cp;
}

ServerSocketLink	&ServerSocketLink::operator=(const ServerSocketLink &rhs)
{
	aConnectedServerInfo = rhs.aConnectedServerInfo;
	aFd = rhs.aFd;
	return *this;
}


void	IntilizeStruct(const std::pair<unsigned int, int> &srvinfo, struct sockaddr_in *srv_addr)
{
	// i assumed that srvinfo already in byte order before it got to this point
	srv_addr->sin_family = AF_INET;
	srv_addr->sin_port = srvinfo.second;
	srv_addr->sin_addr.s_addr = srvinfo.first;
}

bool	ServerSocketLink::operator<(const ServerSocketLink &rhs)
{
	// this is needed for the map to work with
	return (aFd < rhs.aFd);
}


ServerSocketLink	StartServer(const std::pair<unsigned int, int> &srvinfo, int &key)
{
	int	fd;
	struct sockaddr_in	srv_addr;

	fd = socket(AF_INET, SOCK_STREAM, 0);
	key = fd; // key will not be used here
	if (fd < 0)
		print_arror("socket() fail while trying to start server");
	IntilizeStruct(srvinfo, &srv_addr);
	if (bind(fd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0)
	{
		close(fd);
		print_arror("bind() maybe something is wrong with ip or port");
	}
	if (listen(fd, MAX_BACK_LOG) < 0)
	{
		print_arror("listen() something gone wrong trying to listen check backlog number");
		close(fd);
	}
	return ServerSocketLink(srvinfo, fd);
}
