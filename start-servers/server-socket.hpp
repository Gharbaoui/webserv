#ifndef __SERVER_SOCKET__
#define __SERVER_SOCKET__

#include <utility>

std::pair<int, int>	StartServer(const std::pair<unsigned int, int> &srv_info, int index);

#endif
