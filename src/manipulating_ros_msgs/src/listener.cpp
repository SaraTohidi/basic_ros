#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float32.h>

void lessThanHalfCallback(const std_msgs::Float32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%f]", msg->data);
}
void moreThanHalfCallback(const std_msgs::Float32::ConstPtr& msg)
{
  ROS_INFO("I heard: [%f]", msg->data);
}
int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

 
  ros::Subscriber sub_less_half = n.subscribe("/less_than_half", 1000, lessThanHalfCallback);
  ros::Subscriber sub_more_half = n.subscribe("/more_than_half", 1000, moreThanHalfCallback);


  ros::spin();

  return 0;
}
