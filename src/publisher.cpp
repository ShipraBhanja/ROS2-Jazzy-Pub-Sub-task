#include <string>
#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class SimplePublisher : public rclcpp::Node
{
public:
  SimplePublisher() : Node("publisher_node")
  {
    CounterValue = 0;

    publisherObject =
      this->create_publisher<std_msgs::msg::String>(
        "communication_topic", 20);

    auto callBackFunction = [this]() -> void {
      CounterValue++;

      std_msgs::msg::String message;
      message.data = "Hello World : " + std::to_string(CounterValue);

      RCLCPP_INFO(
        this->get_logger(),
        "Published Message : '%s'",
        message.data.c_str());

      publisherObject->publish(message);
    };

    timerObject =
      this->create_wall_timer(1000ms, callBackFunction);
  }

private:
  rclcpp::TimerBase::SharedPtr timerObject;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisherObject;
  int CounterValue;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<SimplePublisher>());
  rclcpp::shutdown();
  return 0;
}

