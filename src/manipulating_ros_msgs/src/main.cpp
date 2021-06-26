#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Float32.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <dynamic_reconfigure/server.h>
#include <manipulating_ros_msgs/ManipulatingRosMsgsConfig.h>
#include "./freq_publisher.cpp"
#include "ros/time.h"
#include <manipulating_ros_msgs/message.h>

int freq = 0;

void callback(manipulating_ros_msgs::ManipulatingRosMsgsConfig &config, uint32_t level) {
  freq = config.frequency_config;
  ROS_INFO_STREAM("Frequency is setting : " << freq);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "manipulating_msgs");
  ros::NodeHandle n;
  ros::Publisher ros_msgs_pub = n.advertise<manipulating_ros_msgs::message>("ros_message", 1000);
  ros::Publisher more_half_pub = n.advertise<std_msgs::Float32>("more_than_half", 1000);
  ros::Publisher less_half_pub = n.advertise<std_msgs::Float32>("less_than_half", 1000);
  dynamic_reconfigure::Server<manipulating_ros_msgs::ManipulatingRosMsgsConfig> server;
  dynamic_reconfigure::Server<manipulating_ros_msgs::ManipulatingRosMsgsConfig>::CallbackType f;
  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ros::Rate loop_rate(freq);

  srand (static_cast <unsigned> (time(0)));
  int count = 0;

  while (ros::ok())
  {

    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    manipulating_msgs::floatingPointPublisher(r, more_half_pub, less_half_pub);

    manipulating_ros_msgs::message ros_msg;
    std_msgs::String msg;
    std::stringstream ss;
    ss << "Counting: " << count;
    msg.data = ss.str();
    ros_msg.message = msg.data;
    ros_msg.header.stamp =  ros::Time::now();
    ros_msgs_pub.publish(ros_msg);
    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}

