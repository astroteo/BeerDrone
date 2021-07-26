px4_dir=$(pwd)/Firmware


#source $px4_dir/Tools/setup_gazebo.bash $px4_dir $px4_dir/build/posix_sitl_default
source $(pwd)/devel/setup.bash
source $px4_dir/Tools/setup_gazebo.bash $px4_dir $px4_dir/build/px4_sitl_default

#export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)/LuFO-plugins/build
#export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:$(pwd)/LuFO-plugins/models
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/LuFO-plugins/build

echo -e "GAZEBO_PLUGIN_PATH $GAZEBO_PLUGIN_PATH"
echo -e "GAZEBO_MODEL_PATH $GAZEBO_MODEL_PATH"
echo -e "LD_LIBRARY_PATH $LD_LIBRARY_PATH"

#export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$px4_dir
#export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$px4_dir/Tools/sitl_gazebo
source $px4_dir/Tools/setup_gazebo.bash $px4_dir $px4_dir/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$px4_dir
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$px4_dir/Tools/sitl_gazebo
