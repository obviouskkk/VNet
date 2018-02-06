/* ***********************************************************************

  > File Name: TcpSegmentHeader.hpp
  > Author: zzy
  > Mail: 942744575@qq.com 
  > Created Time: Mon 05 Feb 2018 06:26:44 PM CST

 ********************************************************************** */

#ifndef __TCP_SEGMENT_HEADER_HPP__
#define __TCP_SEGMENT_HEADER_HPP__


#include <bitset>
class TcpSegmentHeader
{
public:
    unsigned int offset();

private:
    //tpc header 20+4n char
    unsigned short int source_port_; //源端口
    unsigned short int dest_port_;   //目的端口
    unsigned int seq_num_;              //序号seq
    unsigned int ack_num_;              //确认号ack
    unsigned short int ssets_;          //4bit Offset + 6bit 保留 +
    unsigned short int window_size_;    //窗口大小
    unsigned short int check_sum_;      //校验和
    
};


#endif  // __TCP_SEGMENT_HEADER_hPP__
