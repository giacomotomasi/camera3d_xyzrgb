/*
 * Project: Object detection                    
 * Author: Giacomo Tomasi              
 * E-Mail: giacomo.tomasi@unibz.it         
 * Date: April 2022                        
 * File: bbox_node.cpp                          */
 
#include <iostream>
#include "ros/ros.h"
#include "camera3d_xyzrgb/Bbox.h"

int main(int argc, char** argv){
    // ROS initialization
    ros::init(argc, argv, "bbox_node");
    
    ros::NodeHandle n;
    // Moment of inertia method
    BoundingBox b(&n);
    // Principal Component Analisys method
    // BoundingBox_pca b(&n);
    
    ros::spin();
    return 0;
    }