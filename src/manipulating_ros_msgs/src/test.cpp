#include "ros/ros.h"
#include "./freq_publisher.cpp"
#include <gtest/gtest.h>

// Declare a test
TEST(ManipulatingMsgs, floatingPointTesterLess)
{
    bool lessThanHalf = false;
    bool moreThanHalf = false;

    auto lessThanHalfFunc = [&lessThanHalf] (float rand_float){
        lessThanHalf = true;
    };

    auto moreThanHalfFunc = [&moreThanHalf] (float rand_float){
        moreThanHalf = true;
    };
    manipulating_msgs::floatingPointTester(0.1, lessThanHalfFunc, moreThanHalfFunc);
    EXPECT_TRUE(lessThanHalf && !moreThanHalf);

}
// Declare a second test
TEST(ManipulatingMsgs, floatingPointTesterMore)
{
    bool lessThanHalf = false;
    bool moreThanHalf = false;

    auto lessThanHalfFunc = [&lessThanHalf] (float rand_float){
        lessThanHalf = true;
    };

    auto moreThanHalfFunc = [&moreThanHalf] (float rand_float){
        moreThanHalf = true;
    };
    manipulating_msgs::floatingPointTester(0.6, lessThanHalfFunc, moreThanHalfFunc);
    EXPECT_TRUE(!lessThanHalf && moreThanHalf);

}
//TODO complete this test
//TEST(FreqPub, floatingPointPublisher)
//{
//    bool lessThanHalf = false;
//    bool moreThanHalf = false;

//    auto lessThanHalfFunc = [&lessThanHalf] (std_msgs::Float32::ConstPtr& msg){
//        lessThanHalf = true;
//    };

//    auto moreThanHalfFunc = [&moreThanHalf] (std_msgs::Float32::ConstPtr& msg){
//        moreThanHalf = true;
//    };
//    ros::NodeHandle nh;
//    std_msgs::Float32::ConstPtr& msg;
//    ros::Publisher more_half_pub = nh.advertise<std_msgs::Float32>("more_than_half", 1000);
//    ros::Publisher less_half_pub = nh.advertise<std_msgs::Float32>("less_than_half", 1000);
//    ros::Subscriber sub_more_half = nh.subscribe("/more_than_half", 1000, moreThanHalfFunc);
//    ros::Subscriber sub_less_half = nh.subscribe("/less_than_half", 1000, lessThanHalfFunc);

//    EXPECT_TRUE(!lessThanHalf && moreThanHalf);
//}

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "utest");

  return RUN_ALL_TESTS();
}
