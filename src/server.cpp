/* ***********************************************************************

  > File Name: server.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 07 Feb 2018 01:55:02 PM CST

 ********************************************************************** */

#include "common.h"
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdint.h>

int main(int argc, const char* argv[])
{
    if (argc != 3)
        err_exit("usage: %s ip port");
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        err_exit("socket error");
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family  = AF_INET;
    servaddr.sin_port    = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1)
        err_exit("bind error:%s", strerror(errno));
    if (listen(sockfd, 0) < 0)
        err_exit("listen error:%s", strerror(errno));
    socklen_t servaddr_size = sizeof(servaddr);
    if (accept(sockfd, (struct sockaddr*)&servaddr, &servaddr_size) == -1)
        err_exit("accept error");

    return 0;
}

