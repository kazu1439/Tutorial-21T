#include <stdio.h>
#include <ros/ros.h>
#include "std_msgs/Int32MultiArray.h"
#define CTRL_PERIOD 1.0f

inline void chatterCallback(const std_msgs::Int32MultiArray& msg);

int main(int argc, char** argv)
{
    ros::init(argc, argv, "JK_Park_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("a",1000,chatterCallback);
    // ros::Rate loop_rate(1 / CTRL_PERIOD);
    while(ros::ok())
    {
        ros::spinOnce();
        // loop_rate.sleep();
    }
}
inline void chatterCallback(const std_msgs::Int32MultiArray& msg)
{
    // int a = msg.data[0];
    int a = 0;

    if (a == 0)
    {ROS_INFO("170");}
    else if(a == 1)
    {ROS_INFO("150");}
    else if (a == 2)
    {ROS_INFO("130");}
}