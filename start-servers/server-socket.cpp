#include "server-socket.hpp"

std::pair<int, int>	StartServer(const std::pair<unsigned int, int> &srv_info, int index)
{
	int fd;
	struct sockaddr_in	srv_addr;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
	{
		print_arror("socket() StartServer() fail");
	}
	srv_addr.sin_family = AF_INET;
	srv_addr.sin_port = srv_info.second;
	srv_addr.sin_addr.s_addr = srv_info.first;
	
	if (bind(fd, (struct sockaddr*)&srv_addr, sizeof(srv_addr)) < 0)
	{
		print_arror("bind() StartServer() fail");
	}
	if (listen(fd, MAX_BACK_LOG) < 0)
	{
		print_arror("listen() StartServer() fail maybe backlog");
	}
	return std::make_pair(fd, index);
}
