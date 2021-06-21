#include <ros/ros.h>
#include <std_msgs/Int32.h>


int main(int argc, char ** argv) {
    // create/initialise ROS node
    ros::init(argc, argv, "liu_talker"); //node name, not the same as topic name and executable name
    // ::ros::init(argc, agrv, "name"); for local same namespace and function recognition

   // create node handler
   ros::NodeHandle nh; //global/relative node handler
   ros::NodeHandle private_nh("~"); //private node handler

    auto global_pub = nh.advertise<std_msgs::Int32>("chatter", 1); // topic name = chatter
    auto private_pub = private_nh.advertise<std_msgs::Int32>("chatter", 1);

    // create a msg to send
    std_msgs::Int32 msg;
    msg.data = 0;


    // execution rate
    ros::Rate r(2);

    // main execution loop
    while(ros::ok()){
        // publish messages into queue
        global_pub.publish(msg);
        private_pub.publish(msg);

        // Increse data count
        ++msg.data;

        // (good practice) to receive callbacks
        ros::spinOnce();

        // sleep else it will take much resources (to free resource)
        r.sleep();
    }

    return 0;
}