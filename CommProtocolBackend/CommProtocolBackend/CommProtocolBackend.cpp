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

bool initSocket(int& hsocket, char* host_name, int host_port);
bool sendPacket(int& socket, char* packet, int pktSize, ArmCommand& payload);// , CodedOutputStream *coded_output);
int main()
{
	/* Coded output stram */

	 int defaultSize = 1024;
	ArmCommand payload;
	int host_port = 6969;
	char* host_name = "127.0.0.1";

	payload.set_id(777);
	payload.set_position(1010);

	//cout << "size after serilizing is " << payload.ByteSize() << endl;

	//int siz = payload.ByteSize() + 4;
	char *pkt = new char[defaultSize];
	int hsock;

	//google::protobuf::io::ArrayOutputStream aos(pkt, siz);
	//CodedOutputStream *coded_output = new CodedOutputStream(&aos);
	//coded_output->WriteVarint32(payload.ByteSize());
	//payload.SerializeToCodedStream(coded_output);

	//char buffer[1024];
	//int bytecount;
	//int buffer_len = 0;

	
	
	if (initSocket(hsock, host_name, host_port) == false)
	{
		delete pkt;
		closesocket(hsock);
		WSACleanup();
		return -1;
	}



	/*for (int i = 0; i<10000; i++) {
		for (int j = 0; j<10; j++) {

			if ((bytecount = send(hsock, pkt, siz, 0)) == -1) {
				fprintf(stderr, "Error sending data %d\n", errno);
				delete pkt;
				closesocket(hsock);
				WSACleanup();
				return -1;
			}
			printf("Sent bytes %d\n", bytecount);
			Sleep(1);
		}
	}*/

	int id = 0;
	int pos = 1111;
	for (int i = 0; i < 100000; ++i,++id,++pos)
	{

		payload.set_id(id);
		payload.set_position(pos);
		int pktSize = payload.ByteSize() + 4;
		cout << "count " << i + 1 << endl;
		if (sendPacket(hsock, pkt, pktSize, payload)==false) //,coded_output) == false)
		{
			delete pkt;
			closesocket(hsock);
			WSACleanup();
			return -1;
		}
		Sleep(50);
	}

	
	delete pkt;

//FINISH:
	closesocket(hsock);
	WSACleanup();
	cin.get();
    return 0;
}


bool initSocket(int& hsocket, char* host_name, int host_port)
{

	struct sockaddr_in my_addr;
	int *p_int;
	int err;

	WSADATA Data;
	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &Data) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}
	hsocket = socket(AF_INET, SOCK_STREAM, 0);
	if (hsocket == -1) {
		printf("Error initializing socket %d\n", errno);
		return false;
	}

	p_int = (int*)malloc(sizeof(int));
	*p_int = 1;

	if ((setsockopt(hsocket, SOL_SOCKET, SO_REUSEADDR, (char*)p_int, sizeof(int)) == -1) ||
		(setsockopt(hsocket, SOL_SOCKET, SO_KEEPALIVE, (char*)p_int, sizeof(int)) == -1)) {
		printf("Error setting options %d\n", errno);
		free(p_int);
		return false;
	}
	free(p_int);

	my_addr.sin_addr.s_addr = inet_addr(host_name);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(host_port);

	memset(&(my_addr.sin_zero), 0, 8);
	if (connect(hsocket, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
		if ((err = errno) != EINPROGRESS) {
			fprintf(stderr, "Error connecting socket %d\n", errno);
			return false;
		}
	}
	return true;
}

bool sendPacket(int& socket, char* packet, int pktSize, ArmCommand& payload)//, CodedOutputStream * unused_coded_output)
{
	
	google::protobuf::io::ArrayOutputStream aos(packet, pktSize);
	CodedOutputStream *coded_output = new CodedOutputStream(&aos);
	coded_output->WriteVarint32(payload.ByteSize());
	payload.SerializeToCodedStream(coded_output);

	int bytecount = 0;
	if ((bytecount = send(socket, packet, pktSize, 0)) == -1) {
		fprintf(stderr, "Error sending data %d\n", errno);
		return false;
	}
	
	return true;
}

