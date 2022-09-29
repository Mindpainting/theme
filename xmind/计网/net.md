应用层：进程到进程的服务

网络层：端（主机）到端（主机）的服务



SSL（Secure Socket Layer）是在传输通信协议（TCP/IP）上实现的一种安全协议，采用公开密钥技术。

SSL协议的优势在于它是与应用层协议独立无关的，SSL协议在应用层协议通信之前就已经完成加密算法、通信密钥的协商以及服务器认证工作。在此之后应用层协议所传送的数据都会被加密，从而保证通信的私密性。

http://www.bilibili.com 未使用SSL协议

https://www.bilibili.com 使用SSL协议

<img src="C:\Users\think\AppData\Roaming\Typora\typora-user-images\image-20220923130853973.png" alt="image-20220923130853973" style="zoom:80%;" />



IP地址是网络设备跟网络接口这个点的标识。一个主机可以有多个IP地址，一个路由器至少有两个IP地址。

子网：IP地址高位相同；分组收发一跳可达，无需路由器接入。
