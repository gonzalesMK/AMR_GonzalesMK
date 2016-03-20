#include <ros/ros.h>

#include <std_msgs/Float64.h>

int main( int argc, char **argv)
{
    ros::init(argc,argv, "Kinect_Controller");
    
    ros::NodeHandle node;
    
    ros::Publisher R_Motor = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorRightSpeed" , 1);   //ADICIONTAR O NOME TOPICO CORRETO
    ros::Publisher L_Motor = node.advertise<std_msgs::Float64>("/vrep/vehicle/motorLeftSpeed" , 1 );
    
    ros::Rate LoopRate(10);
    
    std_msgs::Float64 Vr;
    std_msgs::Float64 Vl;
    std_msgs::Float64 V ;
    std_msgs::Float64 W ;
    
    V.data = 1;
    W.data = 0;
    
    while(ros::ok()) {
        
        Vr.data = V.data + (0.35/2) * W.data ;
        Vl.data = V.data - (0.35/2) * W.data ;
        
        R_Motor.publish(Vr);
        L_Motor.publish(Vl);        
            
        ros::spinOnce();
        LoopRate.sleep();
    }
    
    return 0;
}   