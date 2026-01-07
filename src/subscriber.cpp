#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class SimpleSubscriber : public rclcpp::Node
{
public:
  SimpleSubscriber() : Node("subscriber_node")
  {
    auto callBackFunction =
      [this](const std_msgs::msg::String::SharedPtr msg) -> void
      {
        RCLCPP_INFO(
          this->get_logger(),
          "I heard: '%s'",
          msg->data.c_str());
      };

    subscriptionObject =
      this->create_subscription<std_msgs::msg::String>(
        "communication_topic",
        20,
        callBackFunction);
  }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriptionObject;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimpleSubscriber>());
  rclcpp::shutdown();
  return 0;
}

