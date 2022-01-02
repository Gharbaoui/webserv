#include <sys/socket.h>
#include <fcntl.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#include <string>
#include <iostream>


int main(int argc, char **argv)
{
	std::string str;
	int port = std::stoi(argv[1]);
	int srv_fd;
	int read_fd;
	struct sockaddr_in srv_info;
	

	srv_info.sin_family = AF_INET;
	srv_info.sin_port = htons(port);
	inet_aton("192.168.100.11", &srv_info.sin_addr);
	srv_fd = socket(AF_INET, SOCK_STREAM, 0);

	read_fd = connect(srv_fd, (struct sockaddr*)&srv_info, sizeof(srv_info));
	std::cout << read_fd << std::endl;
	std::cout << "connection established\n";
	while (1)
	{
		std::cin >> str;
		if (str == "exit")
			break ;
		write(srv_fd, str.c_str(), str.size());
	}
	close(read_fd);
}
