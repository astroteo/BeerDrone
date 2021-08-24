#!/bin/bash
echo "--------------------------------------------------------"

echo "adding gazebo plugins:"


$(pwd)
export GAZEBO_PLUGIN_PATH=$GAZEBO_PLUGIN_PATH:$(pwd)/Tools/build
export GAZEBO_MODEL_PATH=$GAZEBO_MODEL_PATH:${SRC_DIR}/Tools/models
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)/Tools/build_gazebo


cd Tools/build/

cmake ..
make

cd -

cp ./Tools/build/libgazebo_motor_connect.so ../Firmware/build/px4_sitl_default/build_gazebo/

cd models

cp standard_vtol/standard_vtol.sdf ../../Firmware/Tools/sitl_gazebo/models/standard_vtol/

cd -

cd worlds

cp luFO.world ../../Firmware/Tools/sitl_gazebo/worlds/
cp test_world.world ../../Firmware/Tools/sitl_gazebo/worlds/
cd -
