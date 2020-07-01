#pragma once
#include <stdio.h>	
#include <WinSock2.h>
#include <stdlib.h>
#include "netWork.h"
#include "client.h"	
#pragma comment(lib, "Ws2_32.lib")

int main() {
	
	static int err;
	static WORD sockVersion = (WORD)0x0202;
	static char bfr[1024] = { 0 };
	WSADATA sockMSG;
	err = WSAStartup(sockVersion, &sockMSG);
	if (SOCKET_ERROR == err) {
		printf("can^t start net working,err code: %d\n", WSAGetLastError());
		return getchar();
	}
	
	const char server_host[] = "192.168.43.110";
	USHORT prot = 42512;
	unsigned int server = connectTCP(server_host, 15, prot);
	if (0 == SockErrDo(server, INVALID_SOCKET, "connectTCP", 11)) {
		closesocket(server);
		return getchar();
	}	

	Client_Talking(server, "#commend = exit", 16);
	closesocket(server);
	return getchar();
	//*/
	

}
