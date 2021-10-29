#include <ros/ros.h>
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/String.h"

#define CTRL_PERIOD 0.02f

inline void インスタンス名(const 受け取りたいrosの型::ConstPtr &msg);//例えばrosのint型は, std_msgs::Int32, となる。

int main( int argc, char **argv ){
  ros::init( argc, argv, "ノード名" );
  ros::NodeHandle nh;
  ros::Publisher インスタンス名 = nh.advertise<送りたいrosの型>("トピック名", 100);
  ros::Subscriber インスタンス名 = nh.subscribe("トピック名", 100, コールバック関数);
  ros::Rate loop_rate( 1.0/CTRL_PERIOD );

  while ( ros::ok()){
    ros::spinOnce();
    15行目で宣言したインスタンス名.publish(送りたい変数の名前);
    loop_rate.sleep();
  }
  return 0;
}

inline void 10行目で宣言したインスタンス名(const 受け取りたいrosの型::ConstPtr &msg){
    コールバック関数の中身を書く
}
