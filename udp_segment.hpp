/* ***********************************************************************

  > File Name: udp_segment.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 05 Feb 2018 06:03:05 PM CST

 ********************************************************************** */
#ifndef __UDP_SEGMENT_HPP__
#define __UDP_SEGMENT_HPP__ 

class UdpSegment
{
public:

private:
    //udp header 8 char
    short int source_port_; //源端口
    short int dest_port_;   //目的端口
    short int length_;      //长度,包含header和data
    short int checksum_;    //校验和,首部和数据都要校验
};


#endif //__UDP_SEGMENT_HPP__
