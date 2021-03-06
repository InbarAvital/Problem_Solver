//
// Created by Inbar on 21/01/2020.
//
#ifndef PROJ2_SERVER_H
#define PROJ2_SERVER_H
#include "../protocol/ClientHandler.h"
#include "../protocol/MyTestClientHandler.h"
#include "../protocol/StringReverser.h"
#include "../cache/FileCacheManager.h"
#include "../protocol/Solver.h"

namespace server_side {
	class Server {
    public:
        bool stop_server;
	    Server(){
	        stop_server = false;
	    }
	    virtual ~Server(){}
		/***************************************************
		*
		* Opens a server on port 'port' and wait for clients
		*
		****************************************************/
		virtual void open(int port, ClientHandler* c) = 0;

		/***************************************************
		*
		* Closes the socketfd
		*
		****************************************************/
		virtual void stop() = 0;
    };
    namespace boot {
        class Main {
        public:
            int main(int argc, char *argv[]);
        };
    }
}
#endif