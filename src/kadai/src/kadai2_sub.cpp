#include "ros/ros.h"
#include "std_msgs/Float32MultiArray.h"

#define CTRL_PERIOD 0.02f

inline void msg_float(const std_msgs::Float32MultiArray::ConstPtr &msg);

std::vector<float> float1_vec = {0};
//送られてきたものを格納するc++の配列の宣言
//これはrosのstd_msgsの型とは違うので注意
int main(int argc, char **argv)
{
    ros::init(argc, argv, "sub");
    ros::NodeHandle n;
    ros::Subscriber sub_float_msg = n.subscribe("one_msg", 100, msg_float);
    // ros::Subscribe インスタンス名 = n.subscribe("トピック名", 100, 対応するコールバック関数);

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    while (ros::ok())
    {
        ros::spinOnce();

        ROS_INFO("%f", float1_vec[0]);
        loop_rate.sleep();
    }
}
inline void msg_float(const std_msgs::Float32MultiArray::ConstPtr &msg)
{
    float1_vec = msg->data;
}
