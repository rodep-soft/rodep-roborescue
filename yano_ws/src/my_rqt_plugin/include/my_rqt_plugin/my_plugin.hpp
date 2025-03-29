#include <rqt_gui_cpp/plugin.h>
#include <rclcpp/rclcpp.hpp>
#include <QWidget>

namespace my_rqt_plugin {

class MyPlugin : public rqt_gui_cpp::Plugin
{
  Q_OBJECT

public:
  MyPlugin();
  void initPlugin(qt_gui_cpp::PluginContext& context) override;
  void shutdownPlugin() override;

private:
  rclcpp::Node::SharedPtr node_;
  QWidget* widget_;
};

} // namespace my_rqt_plugin