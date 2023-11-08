# Mouse Node ROS Package

## Overview

This ROS package, named "mouse_node," is designed to read mouse input from the `/dev/input/mouse0` device and publish the mouse movement data to a ROS topic. It provides a simple example of creating a ROS node for processing input data and publishing it to a topic.

## Prerequisites

- ROS (Robot Operating System): Make sure you have ROS installed. This package was developed and tested on [ROS Noetic](http://wiki.ros.org/noetic/Installation).

## Installation

1. Clone the repository to your ROS workspace:

   ```bash
    git clone https://github.com/merttkrkmazz/mouse_node.git

Build the package:

cd your-ros-workspace/

catkin_make

## Usage

Run the ROS node:


roscore  #Start the ROS core (if not already running)

rosrun mouse_node mouse_node

## ROS Topics

    Published Topic:
        /mouse_node (std_msgs/Int32)
            Published data format: Int32 (example: combined X and Y data)
