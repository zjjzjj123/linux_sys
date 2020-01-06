## 基本构成
+ linux中都是文件,一切都看作文件,设备文件
+ ~:家目录 - 就是当前用户的目录
- /: 根目录
- /bin/:存放一些二进制的应用脚本程序
/etc/:存放环境
/include/:
/lib/:
/mnt/:空文件夹 可以进行挂在u盘等,18版本的linux都会自动检测u盘,有的时候挂载可能会出现问题

## 当地命令终端执行
修改~/.bashrc 添加alias name='path'即可  这种方法最简单方便
### 目录操作
​	cd pwd
### 文件操作
​	mkdir 
​	rm -rf 
​	ls -lha
​	unzip 解压．zip　zip压缩
​	tar -zxfv 压缩和解压
​	ln oldname newname 建立硬链接 文件夹不能建立硬链接,
​	ln -s oldname newname 建立软连接 不同文件路径可以通过这个链接访问同一个文件 能够节省内存空间	
​	mount 挂载u外部存储设备
​	umask 设置建立文件时的权限 文件的权限分为读写执行 

### 符号代表的文件含义
​	c -- 字符文件
​	d -- 目录文件
​	b -- 块文件
​	r -- 可读文件
​	w -- 可写文件
​	x -- 可执行文件
​	s -- socket文件

### 进程查看和删除
​	ps -aux -ajx
​	ps 
​	top
​	htop
​	kill -9 PID

###　软件安装
​	1.命令行安装
​	2.压缩包deb安装

### 状态切换
​	sudo 临时成为超级用户
​	su 切换成超级用户
​	exit 退出当前状态

