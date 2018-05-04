# catkin_ws:
	|----devel
	|----build
	|----src:
		|-----auto_shutdown
		|-----flashgo
		|-----t3_sendGoals
		|-----launch_robot
		|-----turtlebot3
		|-----turtlebot3_msgs


## auto_shutdown:
>	clone the folder from github:
>		$ git clone https://github.com/chengyuen93/auto_shutdown
>	this node receives a signal from openCR and shudown the system
>	please follow the instructions in the file sudoShutdown_woPasswd.txt before this node can be run successfully

## flashgo:
>	clone the folder from github:
>		$ git clone https://github.com/wings0728/flashgo
>	this node runs the lidar mounted on the robot

## t3_sendGoals:
>	clone the folder from github:
>		$ git clone https://github.com/wings0728/t3_sendGoals
>	this node works from Qt to send goals to the robot

## launch_robot:
>	clone the folder from github:
>		$ git clone https://github.com/chengyuen93/launch_robot
>	this folder contains the following essential items:
>		- maps 		- maps for navigation
>		- params 	- params required for move_base
>		- urdf		- urdf of the robot
>		- launch	- launch file for amcl
>				- launch file for starting up openCR
>				- launch file to run all the essential nodes
>					- urdf
>					- openCR
>					- lidar
>					- map_server
>					- amcl
>					- move_base
>					- t3_sendGoals
>					- auto_shutdown

## t3_description:
> git clone https://github.com/wings0728/t3_description

## imu_serial:
> sudo apt-get install ros-kinetic-serial
> git clone https://github.com/wings0728/imu_serial

## turtlebot3 & turtlebot3_msgs:
>	follow instructions from the following website: 
>		http://xiaoyatec.com/2017/07/07/turtlebot3-%e5%85%a5%e9%97%a8%e6%95%99%e7%a8%8b-%e7%9b%ae%e5%bd%95/


## 端口定义
> [定义方法](http://blog.163.com/zhang_hu_0728/blog/static/24688806720175111326630/)
```shell
#查看端口号
ls -l /dev/
#查看端口名称，有ID_SERIAL_SHORT的记录此数据，没有的就记录ID_SERIAL
udevadm info /dev/ttyUSB0
#打开sudo vi /etc/udev/rules.d/****.rules，增加一行
SUBSYSTEM=="tty",ENV{ID_SERIAL_SHORT}=="A1051JVT",SYMLINK+="ttyUSBname"
```
- 陀螺转角仪：ttyIMU
- OpenCR: ttyOpenCR
- 激光雷达：ttyLidar


## 同步时间
```shell
sudo nano /etc/crontab
#加入
*/10 * * * * root  ntpdate -u ntp.api.bz
```

