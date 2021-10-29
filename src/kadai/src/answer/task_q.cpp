/*********************************
質問するプログラム
**********************************/
/**********************************************************************
Include Libraries
**********************************************************************/
#include "ros/ros.h"
#include "std_msgs/Int32.h"
/**********************************************************************
Declare MACRO
**********************************************************************/
#define CTRL_PERIOD 0.02f
/**********************************************************************
Proto_type_Declare functions
**********************************************************************/

/**********************************************************************
Declare variables
**********************************************************************/
int q = 2;//0~2までで変更、c言語の変数宣言(int型),qは自分が勝手に決めていいインスタンス名

std_msgs::Int32 msg_int; //ros特有の変数宣言(std_msgs::Int32型)、msg_intは自分が勝手に決めていいインスタンス名
/**********************************************************************
Main
**********************************************************************/
int main(int argc, char **argv)
{
    ros::init(argc, argv, "publisher");
    ros::NodeHandle n;
    ros::Publisher pub_int_msg = n.advertise<std_msgs::Int32>("question", 100); //int型のメッセージを送る

    ros::Rate loop_rate(1 / CTRL_PERIOD);

    while (ros::ok())
    {
        msg_int.data = q;
        ros::spinOnce();
        pub_int_msg.publish(msg_int);     //送る
        loop_rate.sleep();
    }

    return 0;
}
/*****************************************************************
Functions <Call Back>
*****************************************************************/
