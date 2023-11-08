#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "mouse_node");
  ros::NodeHandle nh;

  // Create a publisher for the /mouse_node topic
  ros::Publisher mouse_pub = nh.advertise<std_msgs::Int32>("/mouse_node", 10);  // Adjust the message type

  // Open the mouse device file
  const char *mouse_device = "/dev/input/mouse0";
  int mouse_fd = open_mouse_device(mouse_device);  // You can reuse your open_mouse_device function

  if (mouse_fd == -1) {
    ROS_ERROR("Failed to open the mouse device");
    return 1;
  }

  std_msgs::Int32 mouse_data;

  // Read and publish mouse input
  char event[3];

  while (ros::ok()) {
    if (read(mouse_fd, event, sizeof(event)) == sizeof(event)) {
      // Decode and process the mouse movement data here
      int rel_x = (signed char)event[1];
      int rel_y = (signed char)event[2];

      // Publish the mouse data (example: relative X and Y)
      mouse_data.data = (rel_x << 16) | (rel_y & 0xFFFF);  // Combine X and Y data into a single Int32
      mouse_pub.publish(mouse_data);
    }

    ros::spinOnce();  // Handle ROS callbacks
  }

  // Close the mouse device file when done
  close(mouse_fd);
  return 0;
}
