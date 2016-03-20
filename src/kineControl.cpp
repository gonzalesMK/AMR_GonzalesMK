#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Twist.h>

    std_msgs::Float64 Vr;
    std_msgs::Float64 Vl;
    ros::Publisher R_Motor;
    ros::Publisher L_Motor; 

void callback(const geometry_msgs::TwistConstPtr& vel)
{               
        Vr.data = vel->linear.x + (0.35/2) * vel->angular.z ;
        Vl.data = vel->linear.x - (0.35/2) * vel->angular.z ;
        R_Motor.publish(Vr);
        L_Motor.publish(Vl);        
    
}

int main( int argc, char **argv)
{
    ros::init(argc,argv, "Kinect_Controller");
    
    ros::NodeHandle node;
    
    R_Motor = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorRightSpeed" , 1);   
    L_Motor = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorLeftSpeed" , 1 );
    ros::Subscriber s = node.subscribe("/sonarController",1, callback); 
     
    ros::spin();
}   