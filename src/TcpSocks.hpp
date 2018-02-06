/* ***********************************************************************

  > File Name: TcpSocks.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 06 Feb 2018 02:11:57 PM CST

 ********************************************************************** */

#include <cstdint>
#include <string>

class TcpSock;

enum TcpStatus{
  CLOSED         = 1,
  LISTEN         = 2,
  SYN_SENT       = 3,
  SYN_RECIEVED   = 4,
  ESTABLISHED    = 5,
  FIN_WAIT_1     = 6,
  FIN_WAIT_2     = 7,
  CLOSE_WAIT     = 8,
  LAST_ACK       = 9,
  TIME_WAIT      = 10,
};

class TcpSock
{
public:
    TcpSock();
    int Send(TcpSock* conn, const std::string & data);
    int Recv(const std::string data);
    int Connect(const char* ip, const uint16_t port);
    int Accept();
private:
    
};

