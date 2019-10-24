#include <stdio.h>
#include <winsock.h>

int main(int argc, char const *argv[])
{
    char Sendbuf[100];
    char Receivebuf[100];
    int SendLen;
    int ReceiveLen;
    int Length;

    SOCKET socket_server;
    SOCKET socket_receive;

    SOCKADDR_IN Server_add;
    SOCKADDR_IN Client_add;

    WORD wVersionRequested;
    WSADATA wsaData;
    int error;

    wVersionRequested = MAKEWORD(2, 2);
    error = WSAStartup(wVersionRequested, &wsaData);
    if (error != 0)
    {
        printf("加载套接字失败！\n");
        return 0;
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)
    {
        WSACleanup();
        return 0;
    }

    Server_add.sin_family = AF_INET;
    Server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    Server_add.sin_port = htons(5000);

    socket_server = socket(AF_INET, SOCK_STREAM, 0);
    if (bind(socket_server, (SOCKADDR *)&Server_add, sizeof(SOCKADDR)) == SOCKET_ERROR)
    {
        printf("绑定失败\n");
    }

    if (listen(socket_server, 5) < 0)
    {
        printf("监听失败\n");
    }

    Length = sizeof(SOCKADDR);
    socket_receive = accept(socket_server, (SOCKADDR *)&Client_add, &Length);
    if (socket_receive == SOCKET_ERROR)
    {
        printf("接受连接失败\n");
    }

    while (1)
    {
        ReceiveLen = recv(socket_receive, Receivebuf, 100, 0);
        if (ReceiveLen < 0)
        {
            printf("接收失败\n");
            printf("程序退出\n");
            break;
        }
        else
        {
            printf("client say: %s\n", Receivebuf);
        }

        printf("please enter message:");
        scanf("%s", Sendbuf);
        SendLen = send(socket_receive, Sendbuf, 100, 0);
        if (SendLen < 0)
        {
            printf("发送失败\n");
        }
    }

    closesocket(socket_receive); /*释放处理客户端数据的套接字资源*/
    closesocket(socket_server);  /*释放服务器套接字资源*/

    WSACleanup(); /*关闭动态链接库*/
    return 0;
}
