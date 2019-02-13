#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sstream>


void planCallback(const std_msgs::String::ConstPtr& msg)
{
    printf("I heard: [%s] \n", msg->data.c_str());
}

void emergencyStopCallback(const std_msgs::String::ConstPtr& msg)
{
    printf("I heard: [%s] \n", msg->data.c_str());
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "hctr_pkg_node");
    ros::NodeHandle n("~");
    
    ros::Publisher movement_pub = n.advertise<std_msgs::String>("movement", 1000);
    ros::Subscriber sub = n.subscribe("/trj_pkg_node/plan", 1000, planCallback);
    ros::Subscriber esub = n.subscribe("/ptn_pkg_node/emergencyStop", 1000, emergencyStopCallback);
    
    ros::Rate loop_rate(1);
    int count = 0;
    
    while (ros::ok()) {
        
        std_msgs::String msg;

        msg.data = "turn left ";
        movement_pub.publish(msg);
        
        ros::spinOnce();
        
        loop_rate.sleep();
    }
}
