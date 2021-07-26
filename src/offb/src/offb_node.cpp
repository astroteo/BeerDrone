/////////////////////////////////////////////////////////////////////////////ROS
#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/State.h>


#include <mavros_msgs/ExtendedState.h>
#include <mavros_msgs/CommandVtolTransition.h>
/*
#include <mavros_msgs/ExtendedState.h>
#include <mavros_msgs/CommandHome.h>
#include <mavros_msgs/OverrideRCIn.h>
#include <mavros_msgs/RCIn.h>
#include <mavros_msgs/RCOut.h>/setpoint_position/
#include <mavros_msgs/CommandVtolTransition.h>
#include <mavros_msgs/PositionTarget.h>
#include <mavros_msgs/ParamSet.h>
#include <mavros_msgs/ParamPush.h>
#include "std_msgs/String.h"
#include <mavros_msgs/WaypointClear.h>
#include "mavros_msgs/WaypointSetCurrent.h"
#include "mavros_msgs/CommandCode.h"
#include <geometry_msgs/TwistStamped.h>
#include <mavros_msgs/WaypointList.h>
#include <mavros_msgs/WaypointPull.h>
#include <mavros_msgs/WaypointPush.h>
*/
#define VTOL false;
////////////////////////////////////////////////////////////////standard Library
#include <queue>
#include <vector>
#include <math.h>

///////////////////////////////////////////////////////////////////////////Boost
#include <boost/thread/thread.hpp>

///////////////////////////////////////////////////////////////////////////Other
using namespace std;
#define flight_height 2;

/******************************************************************************/
mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}

geometry_msgs::PoseStamped current_pose;
void pose_cb(const geometry_msgs::PoseStamped::ConstPtr& msg){
    current_pose = *msg;
}
/******************************************************************************/


int main(int argc, char **argv)
{

    geometry_msgs::PoseStamped home_pose;
    home_pose.pose.position.x = 0;
    home_pose.pose.position.y = 0;
    home_pose.pose.position.z = flight_height;

    /**************************************************************************/
    vector<geometry_msgs::PoseStamped> wp_queue;
    wp_queue.push_back(home_pose);
    int i_wp =0;

    // 50m est
    geometry_msgs::PoseStamped wp_pose_px;
    wp_pose_px.pose.position.x =3;
    wp_pose_px.pose.position.y = 0;
    wp_pose_px.pose.position.z = flight_height;

    wp_queue.push_back(wp_pose_px);

    //  50m est,50m north
    geometry_msgs::PoseStamped wp_pose_pxy;
    wp_pose_pxy.pose.position.x = 3;
    wp_pose_pxy.pose.position.y = 3;
    wp_pose_pxy.pose.position.z =  flight_height;

    wp_queue.push_back(wp_pose_pxy);

    //50m north
    geometry_msgs::PoseStamped wp_pose_py;
    wp_pose_py.pose.position.x = 3;
    wp_pose_py.pose.position.y = 3;
    wp_pose_py.pose.position.z = flight_height;

    wp_queue.push_back(wp_pose_py);

    //Back-home
    geometry_msgs::PoseStamped wp_pose_home;
    wp_pose_home.pose.position.x = 3;
    wp_pose_home.pose.position.y = 0;
    wp_pose_home.pose.position.z = flight_height;
    wp_queue.push_back(wp_pose_home);

    /**************************************************************************/
    ros::init(argc, argv, "offb_node");
    ros::NodeHandle nh;
    //the setpoint publishing rate MUST be faster than 2Hz
    ros::Rate rate(20.0);

    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 10, state_cb);
    ros::Subscriber pose_sub = nh.subscribe<geometry_msgs::PoseStamped>
            ("mavros/local_position/pose", 10, pose_cb);
    ros::Publisher local_pos_pub = nh.advertise<geometry_msgs::PoseStamped>
            ("mavros/setpoint_position/local", 10);
    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");
    /**************************************************************************/

    // wait for FCU connection
    while(ros::ok() && !current_state.connected){
        ros::spinOnce();
        rate.sleep();
    }



    //send a few setpoints before starting
    for(int i = 100; ros::ok() && i > 0; --i){
        local_pos_pub.publish(home_pose);
        ros::spinOnce();
        rate.sleep();
    }

    mavros_msgs::SetMode offb_set_mode;
    offb_set_mode.request.custom_mode = "OFFBOARD";

    mavros_msgs::CommandBool arm_cmd;
    arm_cmd.request.value = true;

    ros::Time last_request = ros::Time::now();

    while(ros::ok())
    {
        if( current_state.mode != "OFFBOARD" &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(offb_set_mode) &&
                offb_set_mode.response.mode_sent){
                ROS_INFO("Offboard enabled");
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }

    if(sqrt(pow(current_pose.pose.position.x - wp_queue[i_wp].pose.position.x ,2) +
           (pow(current_pose.pose.position.y - wp_queue[i_wp].pose.position.y ,2)))
          < 0.5
          )
          {
            i_wp+1 < wp_queue.size() ?  i_wp += 1 : i_wp =0;
          }

        if( abs(current_pose.pose.position.x) > 320 ||
            abs(current_pose.pose.position.y) > 320)
        {
            ROS_INFO("NOT FOLLOWING STUPID WAYPOINTS");
        }



        local_pos_pub.publish(wp_queue[i_wp]);

        ros::spinOnce();
        rate.sleep();
    }

    return 0;
}
