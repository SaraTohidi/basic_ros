#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float32.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <dynamic_reconfigure/server.h>
#include <manipulating_ros_msgs/ManipulatingRosMsgsConfig.h>
using namespace std;

namespace manipulating_msgs {


//LEVEL 1 UNIT TESTABLE
void floatingPointTester(float rand_float, std::function<void(float)> lessThanHalfFunc , std::function<void(float)> moreThanHalfFunc)
{
    if (rand_float <= 0.5){
        lessThanHalfFunc(rand_float);
    }else{
        moreThanHalfFunc(rand_float);
    }
}

//LEVEL 2 UNIT TESTABLE
void floatingPointPublisher(float rand_float, const ros::Publisher& more_half_pub, const ros::Publisher& less_half_pub){

    auto lessThanHalfFunc = [&less_half_pub] (float rand_float){
        ROS_INFO_STREAM("random float less than half: " << rand_float);
        std_msgs::Float32 float_point;
        float_point.data = rand_float;
        less_half_pub.publish(float_point);
    };
    auto moreThanHalfFunc = [&more_half_pub] (float rand_float){
        ROS_INFO_STREAM("random float more than half: " << rand_float);
        std_msgs::Float32 float_point;
        float_point.data = rand_float;
        more_half_pub.publish(float_point);
    };

    floatingPointTester(rand_float, lessThanHalfFunc, moreThanHalfFunc);
}
}

