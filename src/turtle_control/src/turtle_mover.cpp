#include <chrono>
#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

using namespace std::chrono_literals;

class TurtleMover : public rclcpp::Node {
public:
  TurtleMover() : Node("turtle_mover") {
    // TODO 1: Initialize publisher on "/turtle1/cmd_vel" with queue depth 10
    // Hint: this->create_publisher<MessageType>("topic_name", qos);
    publisher_ = nullptr;

    // TODO 2: Initialize a periodic wall timer running at 10 Hz (100ms)
    // Hint: this->create_wall_timer(100ms, std::bind(&TurtleMover::timer_callback, this));
    timer_ = nullptr;
  }

private:
  void timer_callback() {
    // TODO 3: Construct a geometry_msgs::msg::Twist message
    auto msg = geometry_msgs::msg::Twist();

    // TODO 4: Assign linear.x and angular.z values to drive in a circle

    // TODO 5: Publish the message
    // Hint: publisher_->publish(msg);
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<TurtleMover>());
  rclcpp::shutdown();
  return 0;
}