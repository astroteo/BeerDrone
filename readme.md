## Beer-Drone

### descriprion:
A project for an indoor drone carrying me a beer.<br>

building blocks:
1. Stereo cameras-slam based on particle filter ([High Level explnation here](  https://www.kudan.io/archives/433))
2. Beer-release sensor for decting when the beer is released 


 

#### Simulator: 
1. Gazebo with PX4 in the loop, 
2. deactivate GPS via script ( study the finite state machine inn PX4) 
3. create a ROS node suitable for performing SLAM navigation via stereo cameras:
	* stream cameras' output to RVIZ<br> 
	* stream information about position estimate to offb<br> 
	* exploit already available resources [ROS node for Stereo-Vision SLAM SRV-balearic university](https://github.com/srv/stereo_slam), ["Official" ROS package, melodic supported](http://wiki.ros.org/orb_slam2_ros) <br>
	
4. Modify the IRIS drone by adding tHE "BEER-REALEASE" actuators
#### Hardware: 
[1](https://docs.modalai.com/voxl-m500-functional-description/#high-level-specs) <br> 

Sensors:<br>

1. SLAM on stereo cameras [2](https://www.modalai.com/products/stereo-camera-pair-and-flex-cable-kit-mkit-00009)
2. 3rd camera used to recognize myself [3](https://www.modalai.com/products/mkit-00010?variant=31584526630963)
3. !NOT IN MODAL A.I. DEVICE! a port is free in the drone() 

#### Algorithm study:
1. Notebook folder all benchmark algos are assessed in Python.
2. Create dataset
Important algorithm 

### run:

