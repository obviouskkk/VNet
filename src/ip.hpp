/* ***********************************************************************

  > File Name: ip.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Thu 08 Feb 2018 09:51:07 PM CST

 ********************************************************************** */

#ifndef __IP_H__
#define __IP_H__

#include <stdint.h>
#include <stdio.h>


//
class Ip
{
public:
    char * ip();
    uint16_t port();
public:
    int init_client();
    int init_server();
    int Send(const char* buf, size_t len);
    int Recv(size_t len, char* buf_in);
private:
    char * ip_;
    uint16_t port_;
};

#endif  // __IP_H__
