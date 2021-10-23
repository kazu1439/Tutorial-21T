#include <ros/ros.h>
#include <std_msgs/Int32MultiArray.h>

inline void chatterCallback(const std_msgs::Int32MultiArray& msg)
{
  int num = msg.data.size();
  ROS_INFO("I subscribed [%d]", num);
  for (int i = 0; i < num; i++)
  {
    ROS_INFO("[%d]:%d", i, msg.data[i]);
  }
}

int main(int argc, char** argv)
{

  ros::init(argc, argv, "basic_array_listener");
  ros::NodeHandle nh;
  ros::Subscriber sub = nh.subscribe("array", 1000, chatterCallback);
  while(ros::ok())
  {
  ros::spinOnce();
  }
  return 0;
}