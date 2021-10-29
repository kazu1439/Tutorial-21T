#include <ros/ros.h>
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