#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>

using namespace std::chrono_literals;
class SimplePublisher : public rclcpp::Node
{
public:
    SimplePublisher() : Node("simple_publisher")
    {
        publisher_ = create_publisher<std_msgs::msg::String>("chatter", 10);
        timer_ = create_wall_timer(500ms, std::bind(&SimplePublisher::timer_callback, this));
        RCLCPP_INFO(this->get_logger(), "Simple Publisher Node has been started.");
    }

    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(counter_++);
        publisher_->publish(message);
    }
private:
    unsigned int counter_ = 0;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SimplePublisher>());
    rclcpp::shutdown();
    return 0;
}