#include <iostream>
#include <map>
#include "request.hpp"

char	buf[MAX_SIZE];
char	*msg = "HTTP/1.0 200 OK\r\n\r\nHHHHHHH";
bool	handel_connection(int fd);
std::map<int, Request> requests_map;

int main()
{
	std::cout << getpid() << std::endl;
	Socket srv("192.168.100.11", 9999);
	srv.sock_listen(10);
	int fd;

	fd_set fds;
	fd_set read_fds;
	FD_ZERO(&fds);
	FD_SET(srv.srv_fd, &fds);
	
	while (1)
	{
		read_fds = fds;
		int sel_ret = select(MAX_SIZE, &read_fds, NULL, NULL, NULL);

		for (int i = 2; i < MAX_FDS; ++i)
		{
			if (FD_ISSET(i, &read_fds))
			{
				if (i == srv.srv_fd) {
					fd = srv.sock_accept();
					fcntl(fd, F_SETFL, O_NONBLOCK);
					FD_SET(fd, &fds);
					requests_map.insert (std::make_pair(fd, Request(fd)));
				}
				else{
					if (handel_connection(i))
					{
						FD_CLR(i, &fds);
						close(i);
					}
				}
			}
		}
	}
}


bool	 handel_connection(int fd)
{
	int read_data;

	read_data = read(fd, buf, MAX_SIZE);
	if (read_data < 0)
		return false;
	else if (read_data)
		requests_map[fd].get_line(buf);
	return true;

}
