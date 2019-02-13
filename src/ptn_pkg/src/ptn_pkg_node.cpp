#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>


int main(int argc, char **argv) {
    ros::init(argc, argv, "ptn_pkg_node");
    ros::NodeHandle n("~");
    
    ros::Publisher route_pub = n.advertise<std_msgs::String>("route", 1000);
    ros::Publisher stop_pub = n.advertise<std_msgs::String>("emergencyStop", 1000);
    ros::Rate loop_rate(1);
    
    while (ros::ok()) {
        
        std_msgs::String msg;
        std_msgs::String stop_msg;

        //std::stringstream ss;
        //ss << "hello world " << count;
        //msg.data = ss.str();
        msg.data = "path ahead";
        
        //ROS_INFO("%s", msg.data.c_str());
        
        route_pub.publish(msg);

        stop_msg.data = "false";
	stop_pub.publish(stop_msg);
        ros::spinOnce();
        
        loop_rate.sleep();
        
    }
}
