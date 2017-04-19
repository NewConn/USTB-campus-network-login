#include <cstdlib>
#include <iostream>
#include <WINSOCK2.H>
#include <WS2tcpip.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;
int main(int argc, char *argv[])
{
	int err, i = 5;//i为发送消息的次数，只发送1次可能不成功，暂时不知道原因，所以设为连续发送5次 

				   //在这里设置用户名和密码！！！ 
	char *username = "41524636", *password = "******";
	WORD versionRequired;
	char str1[1000], str2[1000], *str3, *str4;
	const char *constant_str1, *constant_str2;
	constant_str1 = "POST / HTTP/1.1\r\nHost: 202.204.48.66\r\nConnection: keep-alive\r\nReferer: http://202.204.48.66/\r\nContent-Length: 50\r\nCache-Control: max-age=0\r\nOrigin: http://202.204.48.82\r\nContent-Type: application/x-www-form-urlencoded\r\nAccept: application/xml,application/xhtml+xml,text/html;q=0.9,text/plain;q=0.8,image/png,*/*;q=0.5\r\nUser-Agent: Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US) AppleWebKit/534.10 (KHTML, like Gecko) Chrome/8.0.552.215 Safari/534.10\r\nAccept-Encoding: gzip,deflate,sdch\r\nAccept-Language: zh-CN,zh;q=0.8\r\nAccept-Charset: UTF-8,*;q=0.5\r\nCookie: myusername=";
	constant_str2 = "DDDDD=";
	WSADATA wsaData;
	versionRequired = MAKEWORD(2, 2);
	err = WSAStartup(versionRequired, &wsaData);//协议库的版本信息
	if (!err)
	{
		//donothing 
	}
	else
	{
		printf("客户端的嵌套字打开失败!\n");
		return -1; //结束
	}
	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN clientsock_in;
	clientsock_in.sin_addr.S_un.S_addr = inet_pton(AF_INET,"202.204.48.66",0);
	clientsock_in.sin_family = AF_INET;
	clientsock_in.sin_port = htons(80);
	connect(clientSocket, (SOCKADDR*)&clientsock_in, sizeof(SOCKADDR));//开始连接
	 strcpy_s(str1, constant_str1);
	strcat_s(str1, username);
	strcat_s(str1, "; username=");
	strcat_s(str1, username);
	strcat_s(str1, "; smartdot=");
	strcat_s(str1, password);
	strcat_s(str1, "\r\n\r\n");
	strcpy_s(str2, constant_str2);
	strcat_s(str2, username);
	strcat_s(str2, "&upass=");
	strcat_s(str2, password);
	strcat_s(str2, "&0MKKey=123456789&v6ip=");
	while (i) {
		send(clientSocket, str1, strlen(str1), 0);

		send(clientSocket, str2, strlen(str2), 0);

		i--;
	}

	closesocket(clientSocket);
	WSACleanup();
	printf("如果登录失败，请检查用户名密码是否正确\n");
	return EXIT_SUCCESS;
}