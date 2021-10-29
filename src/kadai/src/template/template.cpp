#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/String.h"
#define CTRL_PERIOD 0.02f

int main( int argc, char **argv ){
  ros::init( argc, argv, "ノード名" );
  ros::NodeHandle nh;
  ros::Rate loop_rate( 1.0/CTRL_PERIOD );

  while ( ros::ok()){
    ros::spinOnce();
    loop_rate.sleep();
  }
  
  return 0;
}