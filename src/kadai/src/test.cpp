/*********************************
publiserとsubscriberのプログラムの練習1
**********************************/
/**********************************************************************
Include Libraries
**********************************************************************/

#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/String.h"
/**********************************************************************
Declare MACRO
**********************************************************************/
#define CTRL_PERIOD 0.02f
/**********************************************************************
Proto_type_Declare functions
**********************************************************************/
inline void cb_msg_int(const std_msgs::Int32MultiArray::ConstPtr &msg);

/**********************************************************************
Declare variables
**********************************************************************/
std::vector<int> c = {0, 0, 0}; //65行目のような代入方法を用いる時は，配列は普通の配列ではなく動的なvector配列を用いる
int sum = 0;
/**********************************************************************
Main
**********************************************************************/

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub_msg_int = n.subscribe("int_signal", 100, cb_msg_int);

    ros::Rate loop_rate(1 / CTRL_PERIOD);

    while (ros::ok())
    {
        ros::spinOnce();
        sum = c[0] + c[1] + c[2];
        // 演算子

        ROS_INFO("%d, %d, %d, %d", c[0], c[1], c[2], sum);

        loop_rate.sleep();
    }
}
/*****************************************************************
Functions <Call Back>
*****************************************************************/
inline void cb_msg_int(const std_msgs::Int32MultiArray::ConstPtr &msg)
{
    //配列の一括代入ができる
    c = msg->data;


}