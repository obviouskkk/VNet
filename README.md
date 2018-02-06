# VNet
## 在软件层面尽可能的模拟tcp/ip网络行为
- 在函数调用层，为调用者提供类似connet,send等行为的接口
- 分层实现，模拟tcp/ip的分层

### 2018年2月6日14:25:56
- 创建项目
- 暂时使用protobuf代替报文的字符流
- 定义TCP UDP报文结构
### 2018年2月6日23:01:41
- 三次握手，代码结构调整
- Tcpdump抓了一下包，确定写的代码没有严重逻辑问题
- TODO 最简单的形式，使用两个多线程
- TODO CMake and 编译
- Coding at home so cold
