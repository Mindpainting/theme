### 安装软件

一、使用dpkg命令安装deb安装包文件

Debian软件包命名遵循下列约定: -.deb

安装步骤：

1、找到相应的软件包，比如xx.deb，下载到本机某个目录；

2、cd xx.deb所在的目录；

3、sudo dpkg -i xx.deb。

卸载步骤:1、sudo dpkg -r xxSoftName。

使用apt在线安装、卸载  sudo apt install 

sudo apt remove 

二、使用rpm命令安装rpm安装包文件

安装步骤：

1、找到相应的软件包，比如xx.rpm，下载到本机某个目录；

2、cd xx.rpm所在的目录；

3、sudo rpm -ivh xx.rpm 。(安装并显示正在安装的文件信息及安装进度)

卸载步骤:1、sudo rpm -e xxSoftName。(-e 可以用–earse代替)

使用yum在线安装、卸载sudo yum install 

sudo yum remove 

三、编译安装

1、找到相应的软件包，比如xx.tar.gz，下载到本机某个目录；

2、cd xx.tar.gz所在的目录；

3、解压缩： tar -xvf xx.tar.gz ；

4、cd进解压后的文件及： cd xx；

5、配置文件： ./configure；

6、开始编译： make；

7、安装生成的二进制文件：make install。

注意：具体安装方法以软件源代码中的README等帮助文件为准。

卸载步骤:

1、在源代码包目录中,终端执行：make uninstall。

### 打开终端

`Ctrl + Alt + T`



|                               |                                                  |
| ----------------------------- | ------------------------------------------------ |
| pwd                           |                                                  |
| ls                            |                                                  |
| ls -l                         | 以列表形式列出当前目录下的所有文件（除隐藏文件） |
| ls -a                         | 列出当前目录下的所有文件，含隐藏文件             |
| ls - h                        | 列出文件的大小以字节为单位                       |
| ls -la    ls -lh    ls -lah等 |                                                  |
| ls *.odt                      | 列出以.odt结尾的所有文件                         |
| ls ???.odt                    | 列出三个字符文件名且以.odt结尾的所有文件         |
| cd .                          | 进入当前目录                                     |
| cd ..                         | 进入上一级目录                                   |
| cd ~                          | 回到家目录                                       |
| cd -                          | 当前目录和上一个目录之间来回切换                 |
| clear                         | 清屏                                             |
| touch a.txt                   | 创建文件                                         |
| mkdir a/b                     | 创建文件夹（多级）                               |
| rm a.txt                      | 删除文件                                         |
| rm -d/-r a                    | 删除文件夹                                       |
|                               |                                                  |
|                               |                                                  |
|                               |                                                  |
|                               |                                                  |

`* 匹配任意多个字符`

`? 匹配任意一个字符`

`[...] 匹配中括号内出现的任意一个字符 [123] [a-z]`

`[!...] 不匹配中括号内出现的任意一个字符`

cd 命令是用来代开目录的

touch 只能创建文件

`sudo apt install vim`安装vim编译器

### vim

通过命令`vim ~/.vimrc`编辑 vimrc 文件对 vim 进行设置，编辑模式下在 vimrc 文件输入以下语句进行设置

- `syntax on` 设置语法高亮

- `set number` 设置行号 



`:wq` 保存并退出

`:q!` 不保存退出

