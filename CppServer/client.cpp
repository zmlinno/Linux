#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>


int main()
{
    int sockfd = socket(AF_INET,SOCK_STREAM,0);
    /*
    AF_INET：指定使用IPv4地址。
    SOCK_STREAM：指定使用面向连接的TCP协议。
    0：协议参数，通常为0表示使用默认协议。
    */

    //地址结构体初始化
    struct sockaddr_in serv_addr;
    //这是来存储IPv4地址信息的结构体
    bzero(&serv_addr,sizeof(serv_addr));
    //sin_family地址族，设置为AF_INET
    serv_addr.sin_family = AF_INET;
    //ip地址，使用inet_addr函数将点分十进制的ip地址
    //转换为网络字节序的整数表示
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //将字符串形式的ip地址转换为in_addr_t类型(32为整数)
    //以网络字节序表示
    serv_addr.sin_port = htons(8888);
    //端口号，使用htons函数将主机字节序的端口号
    //转换为网络字节序


    //连接到服务器
    connect(sockfd,(sockaddr*)&serv_addr,sizeof(serv_addr));
    //connect用于将套接字连接到指定的服务器
    //sockfd是之前创建的套接字描述符
    
    //connect(sockfd,(sockaddr*)&serv_addr
    //：指向服务器地址信息的指针，
    //强制转换为struct sockaddr类型。

    //sizeof(serv_addr)
    //地址结构体大小
    return 0;
}