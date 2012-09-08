files=./src/Ip.cpp ./src/cleanup.cpp ./src/init.cpp ./src/logic.cpp ./src/Net.cpp 
options= -Wall -lSDL -lSDL_net

all: client server

server:
	g++ ./src/server.cpp $(files) -o ./bin/server $(options)
client:
	g++ ./src/client.cpp $(files) -o ./bin/client $(options)
clean:
	rm ./bin/client ./bin/server 
