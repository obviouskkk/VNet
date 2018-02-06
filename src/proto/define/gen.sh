#########################################################################
# File Name: gen.sh
# Author: zzy
# mail: 942744575@qq.com
# Created Time: Tue 06 Feb 2018 01:50:26 PM CST
#########################################################################
#!/bin/bash
protoc -I=./ --cpp_out=../ ./TcpSegment.proto
