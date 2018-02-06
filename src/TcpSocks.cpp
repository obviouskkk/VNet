/* ***********************************************************************

  > File Name: TcpSocks.cpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Tue 06 Feb 2018 02:31:35 PM CST

 ********************************************************************** */

#include "TcpSocks.hpp"
#include "Net.hpp"

//client
int TcpSock::first_handshake()
{
    ipnet()->net_send();
    this->tcp_states_ =  SYN_SENT;
    return 0;
}

int TcpSock::Connect(){
    if(tcp_states_ == CLOSED){
        first_handshake();
        return 0;
    }
    return -1;
}

//以下是server
int TcpSock::Listen(){   
    if(tcp_states_ == CLOSED)
        this->tcp_states_ = LISTEN;
    else
        return -1;
    return 0;
}

int TcpSock::Accept()
{
    if(tcp_states_ == LISTEN){
        second_handshake();
        tcp_states_ = SYN_RECIEVED;
        return 0;
    }
    return -1;
}

int TcpSock::Send(const std::string & data){
    TcpSegment::TcpSegment TcpSeg;
    TcpSeg.set_tcpdata(data);
    TcpSegment::TcpSegmentHeader * tcp_header_ =TcpSeg. mutable_tcpheader();
    tcp_header_->set_source_port(mport_);
    tcp_header_->set_dest_port(remote_port_);
    tcp_header_->set_offset(data.size() );

    return 0;
}
