#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>


class USBCameraNode : public rclcpp::Node {
    public:
        USBCameraNode() : Node("usb_camera_node") {
            image_pub_ = this->create_publisher<sensor_msgs::msg::Image>("camera/iamge_raw", 10);

            cap_.open(0); // first camera
            if (!cap_.isOpened()) {
                RCLCPP_ERROR(this->get_logger(), "Failed to open USB camera");
                rclcpp::shutdown();
                return;
            }
        }
    
    private:

        void captureFrame() {
            cv::Mat frame;
            cap_ >> frame;

            if (!frame.empty()) {
                std_msgs::msg::Header header;
                header.stamp = this->now();
                auto image_msg = cv_bridge::CvImage(header, "bgr8", frame).toImageMsg();
                image_pub_->publish(*image_msg);
            }
        }



        rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr image_pub_;
        rclcpp::TimerBase::SharedPtr timer_;
        cv::VideoCapture cap_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<USBCameraNode>());
    rclcpp::shutdown();
    return 0;
}
