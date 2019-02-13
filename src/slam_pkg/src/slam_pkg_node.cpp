#include <ros/ros.h>
#include "std_msgs/String.h"


void movementCallback(const std_msgs::String::ConstPtr& msg)
{
    printf("I heard: [%s] \n", msg->data.c_str());
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "slam_pkg_node");
    ros::NodeHandle n("~");
    
    ros::Publisher plan_pub = n.advertise<std_msgs::String>("location", 1000);
    

    ros::Subscriber sub = n.subscribe("/hctr_pkg_node/movement", 1000, movementCallback);
    
    ros::Rate loop_rate(1);
    while (ros::ok()) {


	std_msgs::String msg;
        
        msg.data = "location";

        plan_pub.publish(msg);	


        ros::spinOnce();
        loop_rate.sleep();
    }
}
