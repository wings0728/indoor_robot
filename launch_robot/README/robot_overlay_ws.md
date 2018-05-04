overlay_ws:
	contains the edited move_base

todo:
	1. in overlay_ws:
		$ catkin_make
	2. include the following line in ~/.bashrc:
		source ~/overlay_ws/devel/setup.bash
	3. in the home directory:
		$ source ~/.bashrc
		$ roscd move_base
	4. check that the result should be:
		/home/t001/overlay_ws/src/move_base
	   and not:
		/opt/ros/kinetic/share/move_base
