#include <sys/socket.h>
#include <fcntl.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <utility>


#define MAX_SIZE 1024
#define MAX_FDS 100

struct Request
{
	int 	fd;
	int	new_line_index;
	std::string cur_str;
	Request() {}

	Request(int fd)
	{
		this->fd = fd;
	}

	void	get_line(const std::string &buf)
	{
		if (buf.size())
		{
			new_line_index = buf.find("\r\n", 0);

			if (new_line_index > buf.size())
				cur_str += buf;
			else
			{
				/// parsed
				cur_str.insert(cur_str.end(), buf.begin(), buf.begin() + new_line_index);
				get_line(buf.c_str() + new_line_index + 2);
			}
		}
	}
};


struct Socket
{
	Socket(const char *IP, int port)
	{
		srv_info.sin_family = AF_INET;
		srv_info.sin_port = htons(port);
		inet_aton(IP, &srv_info.sin_addr);
		srv_fd = socket(AF_INET, SOCK_STREAM, 0);
		bind (srv_fd, (struct sockaddr *)&srv_info, sizeof(srv_info));
	}

	int	sock_listen(int backlog) const 
	{
		return listen(srv_fd, backlog);
	}

	int	sock_accept() const
	{
		return accept(srv_fd, NULL, NULL);
	}
	int srv_fd;
	struct sockaddr_in srv_info;
};
