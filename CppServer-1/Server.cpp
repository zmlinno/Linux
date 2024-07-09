#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include "until.h"


int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr));

    listen(sockfd, SOMAXCONN);
    
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_len = sizeof(clnt_addr);
    bzero(&clnt_addr, sizeof(clnt_addr));

    int clnt_sockfd = accept(sockfd, (sockaddr*)&clnt_addr, &clnt_addr_len);

    printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));
    
    while(true)
    //在这里的话是无限循环，直到程序被手动终止
    //它的目的是持续读取来自客户端的数据
    {
        char buf[1024];
        //定义一个缓冲区
        //定义一个字符数组buf，大小为1024字节，
        //来储存从客户端接受到的数据
        bzero(&buf,sizeof(buf));
        //将缓冲区buf的所有字节清零
        //bzero函数指定内存区域设置为0，
        //这样做的目的是确保缓冲区每次读取操作之前都是干净的
        //不包含旧数据
        ssize_t read_bytes = read(clnt_sockfd,buf,sizeof(buf));
        //read函数从指定的文件描述符clnt_sockfd中读取数据到缓冲区 buf中
        //clnt_sockfd表示客户端套接字文件描述符
        //buf是接收数据的缓冲区
        //sizeof(buf)表示缓冲区大小，即最多读取1024字节数据
        //read函数返回值 read_bytes 表示实际读取的字节数
        //如果read返回 0 ，表示客户端关闭了连接，
        //如果返回 -1 表示读取数据时发生了错误


        if(read_bytes > 0)
        {
            printf("message from client fd &d: &s\n",clnt_sockfd,buf);
            write(clnt_sockfd,buf,sizeof(buf));

        }
        else if(read_bytes == 0)
        {
            printf("client fd &d disconnected\n",clnt_sockfd);
            close(clnt_sockfd);
            break;
        }
        else if(read_bytes == -1)
        {
            close(clnt_sockfd);
            errif(true,"socket read error");
        }

    }
    close(sockfd);
    return 0;
}