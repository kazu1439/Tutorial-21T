/*********************************
答えを表示するプログラム
**********************************/
/**********************************************************************
Include Libraries
**********************************************************************/

#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/String.h"
/**********************************************************************
Declare MACRO
**********************************************************************/
#define CTRL_PERIOD 0.02f
/**********************************************************************
Proto_type_Declare functions
**********************************************************************/
inline void cb_msg_int(const std_msgs::Int32::ConstPtr &msg);
/**********************************************************************
Declare variables
**********************************************************************/
int box = 100; //送られてきたものを格納するプログラム, 
//この部分が0だと何も送られて来ていないときに自分の命令が表示してしまうため,0はあまりふさわしくない
//送られてくる数学以外であれば何でもいいと思う
float answer;//答えを格納
/**********************************************************************
Main
**********************************************************************/

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub_msg_int = n.subscribe("question", 100, cb_msg_int);

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    while (ros::ok())
    {
        ros::spinOnce();
        if(box == 0){
            answer = 20;//年齢
        }else if(box == 1){
            answer = 170;//身長
        }else if(box == 2){
            answer = 3;
        }else{
            answer = 0;
        }
        ROS_INFO("%f", answer);
        loop_rate.sleep();
    }
}
/*****************************************************************
Functions <Call Back>
*****************************************************************/
inline void cb_msg_int(const std_msgs::Int32::ConstPtr &msg)
{
    box = msg->data;
}