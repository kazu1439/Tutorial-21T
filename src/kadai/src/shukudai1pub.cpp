
#include "ros/ros.h"
#include "std_msgs/Int32MultiArray.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Int32.h"

#define CTRL_PERIOD 0.02f

std_msgs::Int32 msga_int;
std_msgs::Float32 msg_float;
std_msgs::Int32MultiArray msg_int;
std_msgs::Float32MultiArray msg_float;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1pub");
    //ここは理解せずコピペでいい、俺も理解してない
    // pubはファイル名.cppのファイル名のところを一応入力

    ros::NodeHandle n;
    //ここもあまり理解せずコピペでOK
    //ただ、nのところはプログラムによってnhになってたりする、そしてこのnやnhは次のプログラムに必要になってくる

    ros::Publisher pub_int_msg = n.advertise<std_msgs::Int32>("one_msg", 100);
    // ros::Publisher インスタンス名 = n.advertise<送りたい変数の型>("トピック名", 100);
    //  ＝ の次にあるnは55行目で決めたやつもし55行目でros::NodeHandle nh;と書かれて居たらnがnhになるだけ
    //一番最後の100は多分何でもいい、コピペ元を参考にしよう

    ros::Rate loop_rate(1 / CTRL_PERIOD);

    msga.int.data = 78;

    while (ros::ok())
    {
        ros::spinOnce();
        // ros::spinOnce関数によってコールバック関数が読み込まれる
        //コールバック関数はsubscribeするときに必要な関数である。
        //今回のプログラムではpublishするだけなので必要のないものだけど、いつも脳死で書いていいと思う

        pub_int_msg.publish(msga_int);
        //ここでは実際に宣言した変数のpublishを実行している
        // 59行目で決めたインスタンス名.publish(送りたい変数のインスタンス名);

        loop_rate.sleep();
        //定めた制御周期を実行している
    }

    return 0;
    //これは気にしなくていいと思う
    //気になればc++の関数の戻り値とかで調べるといいと思う
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1pub");
    ros::NodeHandle n;
    ros::Publisher pub_float_msgb = n.advertise<std_msgs::Float32>("two_msg", 100);
    ros::Rate loop_rate(1 / CTRL_PERIOD);

    msgb.float.data = 3.14;
    while (ros::ok())
    {
        ros::spinOnce();

        pub_float_msgb.publish(msgb_float);

        loop_rate.sleep();
    }

    return 0;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1pub");
    ros::NodeHandle n;
    ros::Publisher pub_int_msgc = n.advertise<std_msgs::Int32MultiArray>("three_msg", 100);
    ros::Rate loop_rate(1 / CTRL_PERIOD);
    msgc_int.data.resize(3);
    msgc_int.data[0] = 1994;
    msgc_int.data[1] = 4;
    msgc_int.data[2] = 1;

    while (ros::ok())
    {
        ros::spinOnce();

        pub_int_msgc.publish(msgc_int);

        loop_rate.sleep();
    }

    return 0;
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "shukudai1pub");
    ros::NodeHandle n;
    ros::Publisher pub_float_msgd = n.advertise<std_msgs::Float32MultiArray>("four_msg", 100);
    ros::Rate loop_rate(1 / CTRL_PERIOD);
    msgd_float.data.resize(2);

    msgd_float.data[0] = 174.5;

    msgd_float.data[1] = 78.0;

    while (ros::ok())
    {
        ros::spinOnce();

        pub_float_msgd.publish(msgd_float);

        loop_rate.sleep();
    }

    return 0;
}