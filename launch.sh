#!/bin/bash
echo "--------------------------------------------------------"

echo "disabling OpenGL support [Only for VM purposes] "

export SVGA_VGPU10=0

#echo "Launching GCS: "
#./QGroundControl.AppImage &

echo "--------------------------------------------------------"
px4_dir=$(pwd)/Firmware
#source px4_dir/Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default


echo "Launching vehicle: "


px4_dir=$(pwd)/Firmware
source ./devel/setup.bash
source ./launch_setup.sh


roslaunch offb offb.launch


echo "firmware-path: ".$px4_dir
echo "-------------------------------------------------"
