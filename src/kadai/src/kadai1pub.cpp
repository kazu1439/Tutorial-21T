/*********************************
daichi ofuchi
3つの配列をpubするプログラム

プログラム
//上のプログラムの簡単な説明

という感じに書いてます、参考にしてね！！

説明で出てくる用語の補足
・インスタンス名とは、数学の問題で回答者がとりあえず分からないものをxという名前の変数で置くように、
　プログラム作成者が勝手に決めていい名前
　ただ、見返してある程度分かるように変数もxやy,zという名前ではなく意味のある変数の名前を付けた方がいいと思う
**********************************/
/**********************************************************************
Include Libraries
**********************************************************************/

#include "ros/ros.h"
// rosをする上で必要なinclude
#include "std_msgs/Int32MultiArray.h"
// publishしたいrosの型のinclude,今回はstd_msgs::Int32MultiArray型をinclude

/**********************************************************************
Declare MACRO
**********************************************************************/

#define CTRL_PERIOD 0.02f
//制御周期とはコンピュータ上で読み込まれる時間
//例えばmain文の中のwhile文は0.02秒に1回の周期で読み込まれている
//だからROS_INFOで見ると約0.02秒周期で値が表示されていることが分かる

/**********************************************************************
Proto_type_Declare functions
**********************************************************************/

/**********************************************************************
Declare variables
**********************************************************************/

std_msgs::Int32MultiArray msg_int;
// ros特有の変数宣言，今回はrosのstd_msgs::Int32MultiArray型である。
//そして，msg_intは自分が勝手に決めていいインスタンス名

/**********************************************************************
Main
**********************************************************************/

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub");
    //ここは理解せずコピペでいい、俺も理解してない
    // pubはファイル名.cppのファイル名のところを一応入力

    ros::NodeHandle n;
    //ここもあまり理解せずコピペでOK
    //ただ、nのところはプログラムによってnhになってたりする、そしてこのnやnhは次のプログラムに必要になってくる

    ros::Publisher pub_int_msg = n.advertise<std_msgs::Int32MultiArray>("three_msg", 100);
    // ros::Publisher インスタンス名 = n.advertise<送りたい変数の型>("トピック名", 100);
    //  ＝ の次にあるnは55行目で決めたやつもし55行目でros::NodeHandle nh;と書かれて居たらnがnhになるだけ
    //一番最後の100は多分何でもいい、コピペ元を参考にしよう

    ros::Rate loop_rate(1 / CTRL_PERIOD);
    // ちょっと前に決めた制御周期を参照し制御周期の宣言を行っている

    msg_int.data.resize(3);
    // 41行目で宣言した配列の要素数を決めている
    //配列とは、複数の値を添え字を付けて保存できる変数
    // rosの変数のインスタンス名.data.resize(n);
    //とやることで使う配列の要素数をnと定めることができる
    //添え字とは、配列の要素の番号である。添え字番号0が一番最初の要素を指している、添え字番号1は
    //先頭から2番目の配列の要素を指している

    msg_int.data[0] = 2001;
    //配列msg_intの添え字番号0(一番最初の要素)に2001が代入されている

    msg_int.data[1] = 10;
    //配列msg_intの添え字1(2番目の要素)に10が代入されている

    msg_int.data[2] = 11;
    //配列msg_intの添え字2（3番目の要素）に11が代入されている

    while (ros::ok())
    {
        ros::spinOnce();
        // ros::spinOnce関数によってコールバック関数が読み込まれる
        //コールバック関数はsubscribeするときに必要な関数である。
        //今回のプログラムではpublishするだけなので必要のないものだけど、いつも脳死で書いていいと思う

        pub_int_msg.publish(msg_int);
        //ここでは実際に宣言した変数のpublishを実行している
        // 59行目で決めたインスタンス名.publish(送りたい変数のインスタンス名);

        loop_rate.sleep();
        //定めた制御周期を実行している
    }

    return 0;
    //これは気にしなくていいと思う
    //気になればc++の関数の戻り値とかで調べるといいと思う
}
/*****************************************************************
Functions <Call Back>
*****************************************************************/