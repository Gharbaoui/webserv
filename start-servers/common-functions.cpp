#include <iostream>

void	print_arror(char *str)
{
	std::cout << "\033[1;31m" << str << "\033[0m\n";
}
