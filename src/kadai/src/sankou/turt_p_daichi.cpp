/**********************************************************************
Define MACROES
**********************************************************************/
#define CTRL_PERIOD 0.02f
/**********************************************************************
Include Libraries
**********************************************************************/
#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Int32.h>
#include <vector>
/**********************************************************************
Declare variables
**********************************************************************/
geometry_msgs::Twist twist;

int judge = 0;

float first_var = 5.544445;

float t = 0.2;

float set_var_x = 0.0f;     //目標値
float pro_var_x = 0.0f;     //計測値
float set_var_y = 0.0f;     //目標値
float pro_var_y = 0.0f;     //計測値
float set_var_theta = 0.0f; //目標値
float pro_var_theta = 0.0f; //計測値
float e_x = 0.0f;           //偏差
float e_y = 0.0f;           //偏差
float e_theta = 0.0f;       //偏差
float kp = 10;
float kp_theta = 10;

bool next_judge_theta = 0;
bool next_judge_x = 0;
bool next_judge_y = 0;
bool next_pro = 0;

std::vector<float> set_vec_x{1.50 * first_var, 1.50 * first_var, first_var, first_var};
std::vector<float> set_vec_y{first_var, 1.50 * first_var, 1.50 * first_var, first_var};
std::vector<float> set_vec_theta{0, 1.57, 3.14, -1.57};
int i = 0;
/**********************************************************************
Proto_type_Declare functions
**********************************************************************/
void cB_turtle_pose(const turtlesim::Pose::ConstPtr &msg_pose);
void judge_cd(const std_msgs::Int32::ConstPtr &msg);
float move_theta(); //目標値になったら1を出力
float move_x();
float move_y();
void reset();
/**********************************************************************
Declare Instances
**********************************************************************/

/**********************************************************************
Main
**********************************************************************/
int main(int argc, char **argv)
{
    ros::init(argc, argv, "turt1");
    ros::NodeHandle nh;
    ros::Rate loop_rate(1.0 / CTRL_PERIOD);
    ros::Subscriber sub_turtle_pose = nh.subscribe("turtle1/pose", 1, cB_turtle_pose);
    ros::Subscriber sub_judge = nh.subscribe("start_flag", 100, judge_cd);
    ros::Publisher pub_turtle_cmd = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel", 5);

    set_var_theta = set_vec_theta[i];
    set_var_x = set_vec_x[i];
    set_var_y = set_vec_y[i];

    while (ros::ok())
    {
        ros::spinOnce();

        if (judge)
        {
            e_x = set_var_x - pro_var_x;
            e_y = set_var_y - pro_var_y;
            e_theta = set_var_theta - pro_var_theta;

            if (e_x < 0)
            {
                e_x *= -1;
            }
            if (e_y < 0)
            {
                e_y *= -1;
            }
            if (e_theta < 0)
            {
                e_theta *= -1;
            }

            twist.angular.z = move_theta();
            if (next_judge_theta && next_pro == 0)
            {
                twist.linear.x = move_x();
                if (i == 0)
                {
                    twist.linear.y = move_y();
                }
                if (i == 2)
                {
                    twist.linear.y = move_y();
                }

                if (next_judge_x && next_judge_y)
                {
                    reset();
                }
            }
            else if (next_judge_theta && next_pro == 1)
            {
                twist.linear.x = move_y();
                if (i == 1)
                {
                    twist.linear.y = move_x();
                }
                if (i == 3)
                {
                    twist.linear.y = move_x();
                }

                if (next_judge_x && next_judge_y)
                {
                    reset();
                }
            }

            // ROS_INFO("%s,%f,%s,%f,%s,%f,\n","x:", pro_var_x,"y:",pro_var_y,"theta:",pro_var_theta);
            ROS_INFO("%s,%f,%s,%f,%s,%f,\n,%s,%f,%s,%f,%s,%f,\n", "e_x", e_x, "e_y", e_y, "e_theta", e_theta, "set_x", set_var_x, "set_y", set_var_y, "set_theta", set_var_theta);
            pub_turtle_cmd.publish(twist);
            loop_rate.sleep();
        }
    }

    return 0;
}

/**********************************************************************
Functions
**********************************************************************/
void cB_turtle_pose(const turtlesim::Pose::ConstPtr &msg_pose)
{
    pro_var_x = msg_pose->x;
    pro_var_y = msg_pose->y;
    pro_var_theta = msg_pose->theta;
}

void judge_cd(const std_msgs::Int32::ConstPtr &msg)
{
    judge = msg->data;
}

float move_theta()
{
    if (set_var_theta + 0.001 > pro_var_theta && set_var_theta - 0.001 < pro_var_theta)
    {
        next_judge_theta = 1;
        return 0;
    }
    else
    {
        next_judge_theta = 0;
        return e_theta * kp_theta * t;
    }
}

float move_x()
{
    if (set_var_x + 0.001 > pro_var_x && set_var_x - 0.001 < pro_var_x)
    {
        next_judge_x = 1;
        return 0;
    }
    else
    {
        next_judge_x = 0;
        return e_x * kp * t;
    }
}

float move_y()
{
    if (set_var_y + 0.001 > pro_var_y && set_var_y - 0.001 < pro_var_y)
    {
        next_judge_y = 1;
        return 0;
    }
    else
    {
        next_judge_y = 0;
        return e_y * kp * t;
    }
}

void reset()
{
    next_judge_theta = !next_judge_theta;
    next_judge_x = !next_judge_x;
    next_judge_y = !next_judge_y;
    next_pro = !next_pro;
    if (i == 3)
    {
        i = -1;
    }
    i += 1;
    set_var_theta = set_vec_theta[i];
    set_var_x = set_vec_x[i];
    set_var_y = set_vec_y[i];
}
