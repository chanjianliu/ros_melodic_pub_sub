#include <ros/ros.h>
#include <std_msgs/Int32.h>

void chatterCallback(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("I heard: [%d]", msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "listener");

	ros::NodeHandle n;

	ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback); // arg (topic name, message queue size, callbackFunction (what to do after receiving))
	// message queue, old message are removed for new ones if message queue exceeds 1000

	ros::spin();

	return 0;
}