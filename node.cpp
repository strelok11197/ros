#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
using namespace std;

int main(int args, char** argv)
{
	ros::init(int argc, argv, "node");
	ros::NodeHandle n;
	ros::Publisher pub = n.advertise<std_msgs::String>("/topic", 1000);

	ros::Rate loop_rate(1);
	int a;
	while (cin >> a)
	{
		std_msgs::String msg;

		msg.data = a;

		ROS_INFO("%s", msg.data.c_str());
		pub.publish(msg);
		loop_rate.sleep();
	}
	ros::spinOnce();
	return 0;
}