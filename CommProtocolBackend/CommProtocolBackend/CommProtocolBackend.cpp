// CommProtocolBackend.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "UGVMessage.pb.h"
#include <WinSock2.h>
#include <iostream>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#pragma comment(lib, "Ws2_32.lib")

using namespace google::protobuf::io;
using namespace std;
using namespace UGV;

int main()
{
	/* Coded output stram */

	ArmCommand payload;

	payload.set_id(777);
	payload.set_position(1010);

	cout << "size after serilizing is " << payload.ByteSize() << endl;
	int siz = payload.ByteSize() + 4;
	char *pkt = new char[siz];
	google::protobuf::io::ArrayOutputStream aos(pkt, siz);
	CodedOutputStream *coded_output = new CodedOutputStream(&aos);
	coded_output->WriteVarint32(payload.ByteSize());
	payload.SerializeToCodedStream(coded_output);

	int host_port = 6969;
	char* host_name = "127.0.0.1";

	struct sockaddr_in my_addr;

	//char buffer[1024];
	int bytecount;
	int buffer_len = 0;

	int hsock;
	int * p_int;
	int err;
	WSADATA Data;
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &Data) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	hsock = socket(AF_INET, SOCK_STREAM, 0);
	if (hsock == -1) {
		printf("Error initializing socket %d\n", errno);
		goto FINISH;
	}

	p_int = (int*)malloc(sizeof(int));
	*p_int = 1;

	if ((setsockopt(hsock, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1) ||
		(setsockopt(hsock, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1)) {
		printf("Error setting options %d\n", errno);
		free(p_int);
		goto FINISH;
	}
	free(p_int);

	my_addr.sin_addr.s_addr = inet_addr(host_name);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(host_port);

	memset(&(my_addr.sin_zero), 0, 8);
	if (connect(hsock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
		if ((err = errno) != EINPROGRESS) {
			fprintf(stderr, "Error connecting socket %d\n", errno);
			goto FINISH;
		}
	}

	for (int i = 0; i<10000; i++) {
		for (int j = 0; j<10; j++) {

			if ((bytecount = send(hsock, pkt, siz, 0)) == -1) {
				fprintf(stderr, "Error sending data %d\n", errno);
				goto FINISH;
			}
			printf("Sent bytes %d\n", bytecount);
			Sleep(1);
		}
	}
	delete pkt;

FINISH:
	closesocket(hsock);
	WSACleanup();
	cin.get();
    return 0;
}

