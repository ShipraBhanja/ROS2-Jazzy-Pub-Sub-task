FROM ros:jazzy

SHELL ["/bin/bash", "-c"]

WORKDIR /ros2_ws

# Copy package into workspace
COPY . src/sub_pub

# Install dependencies
RUN apt update && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src -r -y

# Build workspace
RUN source /opt/ros/jazzy/setup.bash && colcon build

# Run both nodes using launch file
CMD ["bash", "-c", \
     "source /opt/ros/jazzy/setup.bash && \
      source /ros2_ws/install/setup.bash && \
      ros2 launch sub_pub sub_pub.launch.py"]

