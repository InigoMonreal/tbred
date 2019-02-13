#include <ros/ros.h>
#include "std_msgs/String.h"


void routeCallback(const std_msgs::String::ConstPtr& msg)
{
    printf("I heard: [%s] \n", msg->data.c_str());
}



int main(int argc, char **argv) {
    ros::init(argc, argv, "trj_pkg_node");
    ros::NodeHandle n("~");
    
    ros::Publisher plan_pub = n.advertise<std_msgs::String>("plan", 1000);
    

    ros::Subscriber sub = n.subscribe("/ptn_pkg_node/route", 1000, routeCallback);
    
    ros::Rate loop_rate(1);
    while (ros::ok()) {


	std_msgs::String msg;
        
        msg.data = "plan";

        plan_pub.publish(msg);	


        ros::spinOnce();
        loop_rate.sleep();
    }
}
