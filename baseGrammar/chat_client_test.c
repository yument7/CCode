#include <stdio.h>
#include <winsock.h>

int main(int argc, char const *argv[])
{
    char Sendbuf[100];
    char Receivebuf[100];
    int SendLen;
    int ReceiveLen;

    SOCKET socket_send;         /* 客户端socket套接字 */
    SOCKADDR_IN Server_add;     /* 服务器地址信息结构 */

    WORD wVersionRequested;     /* windows socket版本, WORD == unsigned short*/
    WSADATA wsaData;
    int error;

    wVersionRequested = MAKEWORD(2, 2);              /* */
    error = WSAStartup(wVersionRequested, &wsaData); /* 用于初始化Ws2_32.dll动态链接库，使用套接字前，一定要初始化Ws2_32.dll动态链接库 */
    if (error != 0)
    {
        printf("加载套接字失败！");
        return 0;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        WSACleanup();
        return 0;
    }

    Server_add.sin_family = AF_INET;
    Server_add.sin_addr.S_un.S_addr = inet_addr("127.0.0.1"); /* inet_addr函数将字符串地址转换成32位无符号长整型数据*/
    Server_add.sin_port = htons(5000);

    socket_send = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(socket_send, (SOCKADDR *)&Server_add, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        printf("连接失败！\n");
    }

    while (1)
    {
        printf("please enter message:");
        scanf("%s", Sendbuf);
        SendLen = send(socket_send, Sendbuf, 100, 0);
        if (SendLen < 0)
        {
            printf("发送失败！\n");
        }

        ReceiveLen = recv(socket_send, Receivebuf, 100, 0);
        if (ReceiveLen < 0)
        {
            printf("接收失败\n");
            printf("程序退出");
            break;
        }
        else
        {
            printf("Server say: %s\n", Receivebuf);
        }
    }

    closesocket(socket_send);
    WSACleanup();
    return 0;
}
