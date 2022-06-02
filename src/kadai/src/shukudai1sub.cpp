/*********************************
 daichiofuchi
3つの配列を受け取るプログラム

pub.cppで説明している所は省いた
**********************************/
/**********************************************************************
Include Libraries
**********************************************************************/
#include "ros/ros.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"
/**********************************************************************
Declare MACRO
**********************************************************************/
#define CTRL_PERIOD 0.02f
/**********************************************************************
Proto_type_Declare functions
**********************************************************************/

inline void cb_msga_int(const std_msgs::Int32::ConstPtr &msg1);
inline void cb_msgb_int(const std_msgs::Float32::ConstPtr &msg2);
inline void cb_msgc_int(const std_msgs::Int32MultiArray::ConstPtr &msg3);
inline void cb_msgd_int(const std_msgs::Float32MultiArray::ConstPtr &msg4);
//コールバック関数を含む関数は宣言を最初にして関数の中身はmain文の後に書こう！
//理由はコードが見やすくなるからです。初めはめんどくさいと思うけど先輩たちが使っているフォーマット通りに書こう
//この１行でコールバック関数の宣言を行っている。「プログラムは上から順番に実行」という大原則がある
//この1行を書かないとmain文でコールバック関数が現れたときにプログラムは上から実行されて行っているので
//コンピュータ側で関数が定義されていないと考えてしまいます

/**********************************************************************
Declare variables
**********************************************************************/

std::vector<int> int1_vec = {0};
std::vector<float> float2_vec = {0};
std::vector<int> int3_vec = {0, 0, 0};
std::vector<float> float4_vec = {0, 0};
//送られてきたものを格納するc++の配列の宣言
//これはrosのstd_msgsの型とは違うので注意

/**********************************************************************
Main
**********************************************************************/

int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1sub");
    ros::NodeHandle n;

    ros::Subscriber sub_msga_int = n.subscribe("one_msg", 100, cb_msga_int);

    // ros::Subscribe インスタンス名 = n.subscribe("トピック名", 100, 対応するコールバック関数);

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    while (ros::ok())
    {
        ros::spinOnce();

        ROS_INFO("%d,", int1_vec[0]);
        // ROS_INFO("%d, %f, %s", int型の値or変数, float型の値or変数, string型の文字列or変数);
        //表示させたい型によって対応する%d,%f,%sが異なってくるから注意

        loop_rate.sleep();
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sub");
    ros::NodeHandle n;
    ros::Subscriber sub_msgb_float = n.subscribe("two_msg", 100, cb_msgb_int);
    // ros::Subscribe インスタンス名 = n.subscribe("トピック名", 100, 対応するコールバック関数);

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    while (ros::ok())
    {
        ros::spinOnce();

        ROS_INFO("%f,", float2_vec[0], );
        // ROS_INFO("%d, %f, %s", int型の値or変数, float型の値or変数, string型の文字列or変数);
        //表示させたい型によって対応する%d,%f,%sが異なってくるから注意

        loop_rate.sleep();
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1sub");
    ros::NodeHandle n;

    ros::Subscriber sub_msgc_int = n.subscribe("three_msg", 100, cb_msgc_int);
    // ros::Subscribe インスタンス名 = n.subscribe("トピック名", 100, 対応するコールバック関数);

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    while (ros::ok())
    {
        ros::spinOnce();

        ROS_INFO("%d, %d, %d", int3_vec[0], int3_vec[1], int3_vec[2], );
        // ROS_INFO("%d, %f, %s", int型の値or変数, float型の値or変数, string型の文字列or変数);
        //表示させたい型によって対応する%d,%f,%sが異なってくるから注意

        loop_rate.sleep();
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1sub");
    ros::NodeHandle n;

    ros::Subscriber sub_msgd_float = n.subscribe("four_msg", 100, cb_msgd_int);
    // ros::Subscribe インスタンス名 = n.subscribe("トピック名", 100, 対応するコールバック関数);

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    while (ros::ok())
    {
        ros::spinOnce();

        ROS_INFO("%f, %f", float4_vec[0], float4_vec[1]);
        // ROS_INFO("%d, %f, %s", int型の値or変数, float型の値or変数, string型の文字列or変数);
        //表示させたい型によって対応する%d,%f,%sが異なってくるから注意

        loop_rate.sleep();
    }
}
/*****************************************************************
Functions <Call Back>
*****************************************************************/
inline void cb_msg_int(const std_msgs::Int32::ConstPtr &msg)
{
    int1_vec = msg->data;
}
inline void cb_msgb_int(const std_msgs::Float32::ConstPtr &msgb)
{
    float2_vec = msgb->data;
}
inline void cb_msgc_int(const std_msgs::Int32MultiArray::ConstPtr &msgc)
{
    int3_vec = msgc->data;
}
inline void cb_msgd_int(const std_msgs::Float32MultiArray::ConstPtr &msgd)
{
    float4_vec = msgd->data;
}
//最初に宣言したコールバック関数の定義を書く
//そのあと中格好を追加しコールバック関数の中身を書く