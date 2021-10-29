#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/String.h"

#define CTRL_PERIOD 0.02f

inline void cb_int(const std_msgs::Int32::ConstPtr &msg);

int msg_sub = 0;
std_msgs::Int32 msg_int;

int main( int argc, char **argv ){
  ros::init( argc, argv, "template2");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("chatter", 100);
  ros::Subscriber sub = nh.subscribe("chatter", 100, cb_int);
  ros::Rate loop_rate( 1.0/CTRL_PERIOD );

  while ( ros::ok()){
    ros::spinOnce();
    msg_int.data = 1;
    ROS_INFO("%d", msg_sub);
    pub.publish(msg_int);
    loop_rate.sleep();
  }
  
  return 0;
}

inline void cb_int(const std_msgs::Int32::ConstPtr &msg){
    msg_sub = msg->data;
}
