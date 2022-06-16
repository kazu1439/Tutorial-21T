#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"

#define CTRL_PERIOD 0.02f

std_msgs::Float32MultiArray msg_float;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub");

    ros::NodeHandle n;
    ros::Publisher pub_float_msg = n.advertise<std_msgs::Float32MultiArray>("one_msg", 100);

    ros::Rate loop_rate(1 / CTRL_PERIOD);

    msg_float.data.resize(1);

    msg_float.data[0] = 3.14;

    while (ros::ok())
    {
        ros::spinOnce();
        pub_float_msg.publish(msg_float);
        loop_rate.sleep();
    }
    return 0;
}
