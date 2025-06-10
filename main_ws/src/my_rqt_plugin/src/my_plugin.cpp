#include "my_rqt_plugin/my_plugin.hpp"

namespace my_rqt_plugin {

MyPlugin::MyPlugin()
  : rqt_gui_cpp::Plugin()
  , widget_(nullptr)
{
  setObjectName("MyPlugin");
}

void MyPlugin::initPlugin(qt_gui_cpp::PluginContext& context)
{
  node_ = std::make_shared<rclcpp::Node>("my_rqt_node");
  
  widget_ = new QWidget();
  
  if (context.serialNumber() > 1) {
    widget_->setWindowTitle(
      widget_->windowTitle() + " (" + QString::number(context.serialNumber()) + ")");
  }
  
  context.addWidget(widget_);
  
  RCLCPP_INFO(node_->get_logger(), "Plugin initialized");
}

void MyPlugin::shutdownPlugin()
{
  RCLCPP_INFO(node_->get_logger(), "Plugin shutdown");
}

} // namespace my_rqt_plugin

#include <pluginlib/class_list_macros.hpp>
PLUGINLIB_EXPORT_CLASS(my_rqt_plugin::MyPlugin, rqt_gui_cpp::Plugin)