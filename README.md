# sub_pub

A simple ROS 2 package demonstrating a **publisher** and **subscriber** using `std_msgs/msg/String`. 
The publisher sends `"Hello World : <count>"` messages, and the subscriber prints them to the console.

---

## Requirements

- ROS 2 (tested on **Jazzy**) 
- C++17 compatible compiler (GCC or Clang) 
- `colcon` build tool 

Optional: IDE such as VS Code for editing.

---

## Workspace Setup

1. Create a ROS 2 workspace (if you don’t have one):

```bash
mkdir -p ~/ws_sub_pub/src
cd ~/ws_sub_pub/src

2. Clone this repository or copy sub_pub into src:

git clone https://github.com/<your-username>/sub_pub.git

##Build Instructions

From the workspace root:

cd ~/ws_sub_pub
# Clean build (optional)
rm -rf build install log

# Build the workspace
colcon build --symlink-install

# Source the workspace
source install/setup.bash
You must source setup.bash in every new terminal before running nodes.

##Running the Nodes

Open two terminals and source the workspace in both:

source ~/ws_sub_pub/install/setup.bash

#Terminal 1: Run Publisher
ros2 run sub_pub publisher_node


You should see log messages like:

[INFO] [publisher_node]: Published Message : 'Hello World : 1'
[INFO] [publisher_node]: Published Message : 'Hello World : 2'

#Terminal 2: Run Subscriber
ros2 run sub_pub subscriber_node


The subscriber will print messages received:

[INFO] [subscriber_node]: I heard: 'Hello World : 1'
[INFO] [subscriber_node]: I heard: 'Hello World : 2'

# Run Using Docker (Recommended)

Docker builds the ROS 2 workspace and runs both nodes automatically.

Prerequisites

Docker installed

Internet connection (to pull ROS image)

1. Build Docker image

From the repository root:

docker build -t sub_pub_jazzy .

2. Run container (single command)
docker run --rm sub_pub_jazzy





## Ready for review, please check the repo.

