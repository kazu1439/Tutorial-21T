#include <stdio.h>
#include <ros/ros.h>
#include "std_msgs/Int32MultiArray.h"
#define CTRL_PERIOD 1.0f

int main(int argc, char** argv)
{
    ros::init(argc, argv, "JK_Park_pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::Int32MultiArray>("a",10);

    ros::Rate loop_rate(1 / CTRL_PERIOD);

    while(ros::ok())
    {
        std_msgs::Int32MultiArray array;
        int a = 2;

        if (a == 0)
        {ROS_INFO("170");}
        else if (a == 1)
        {ROS_INFO("150");}
        else if (a == 2)
        {ROS_INFO("130");}
        
        // array.data.resize(1);
        // array.data[0] = 2;
        // pub.publish(array);

        ros::spinOnce();
        loop_rate.sleep();
    }
}