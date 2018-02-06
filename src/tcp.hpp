/* ***********************************************************************

  > File Name: tcp.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 05 Feb 2018 02:00:42 PM CST

 ********************************************************************** */

#ifndef __TCP_HPP__
#define __TCP_HPP__

#include "TcpSocks.hpp"


TcpSock* Socket(int type);
ssize_t Send(TcpSock* sockfd, const void * buf, size_t len, int flags);
ssize_t Recv(TcpSock* sockfd, void *buf, size_t len, int flags);
int     Connect(TcpSock* sockfd, const char * ip, const uint16_t port);
int     Accept(TcpSock* sockfd, const char * ip, const uint16_t port);
int     Listen(TcpSock* sockfd, int backlog);


















#endif  //__TCP_HPP__
