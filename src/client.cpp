/* ***********************************************************************

  > File Name: client.c
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Wed 07 Feb 2018 01:19:34 PM CST

 ********************************************************************** */

#include "common.h"
#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, const char * argv[])
{
    if(argc != 3)
        err_exit("Usage: %s ipaddr port\n", argv[0]);
    struct sockaddr_in peer;
    memset(&peer, 0, sizeof(peer));
    const char * ip = argv[1];
    if(inet_pton(AF_INET, ip, &peer.sin_addr) <= 0)
        err_exit("ipaddr error");
    int port = atoi(argv[2]);
    peer.sin_family  = AF_INET;
    peer.sin_port    = htons(port);

    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
        err_exit("scoket error");
    if(connect(sockfd, (const struct sockaddr* )&peer, 
            sizeof(peer)) == -1){
        err_exit("connect error:%s", strerror(errno));
    }
    char buf[4096];
    while(1){
        fgets(buf, 4096, stdin);
        if(buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';
        write(sockfd, buf, strlen(buf) + 1);

        int len = read(sockfd, buf, 4096);
        if(len <= 0){
            err_exit("read erro:%s", strerror(errno));
        }
        printf("%s", buf);
    }
}
