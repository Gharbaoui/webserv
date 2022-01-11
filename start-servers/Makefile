./objs/common-functions.o: common-functions.cpp
	clang++ -c common-functions.cpp -o ./objs/common-functions.o 

./objs/common-servers.o: common-servers.cpp
	clang++ -c common-servers.cpp -o ./objs/common-servers.o

./objs/main.o: main.cpp
	clang++ -c main.cpp  -o ./objs/main.o

./objs/servers-interface.o: servers-interface.cpp
	clang++ -c servers-interface.cpp -o ./objs/servers-interface.o

./objs/servers.o: servers.cpp
	clang++ -c servers.cpp -o ./objs/servers.o

./objs/server-socket.o: server-socket.cpp
	clang++ -c server-socket.cpp -o ./objs/server-socket.o

OBJS = 	./objs/common-functions.o	\
	./objs/common-servers.o		\
	./objs/main.o			\
	./objs/servers-interface.o	\
	./objs/servers.o		\
	./objs/server-socket.o		\


run: $(OBJS)
	clang++	./objs/*.o -o run

clearobj:
	rm ./objs/*

clean: clearobj
	rm run
