/* ***********************************************************************

  > File Name: TcpSocks.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 06 Feb 2018 02:11:57 PM CST

 ********************************************************************** */

#include <cstdint>
#include <string>

#include "./proto/TcpSegment.pb.h"

class Net;

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
    TcpSock(const char* ip, uint16_t port)
        :mip_(ip), mport_(port){}
    int Send(const std::string & data);
    int Recv(const std::string data);
    int Listen();
    int Connect();
    int Accept();
public:
    Net* ipnet() const;
    uint16_t port() const;
    std::string ip() const;
    int tcp_states() ;
private:
    int first_handshake();    //client 
    int second_handshake();   //server
    int third_handshake();    //client
    int send_data(const std::string & data);
    int send_ack();
private:
    enum TcpStatus tcp_states_;
    std::string  mip_;
    std::string remote_ip_;
    uint16_t mport_;
    uint16_t remote_port_;
    Net* ipnet_;
};

