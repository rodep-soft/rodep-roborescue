FROM osrf/ros:jazzy-desktop

RUN apt-get update && apt-get install -y \
  fish \
  vim \
  git \
  less \
  sudo \
  tmux \
  fzf \
  lsof \
  ccache \
  ros-jazzy-rosbridge-server 
#   && rm -rf /var/lib/apt/lists/*

# RUN echo "tatzv ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

# RUN useradd -ms /usr/bin/bash tatzv
# USER tatzv

# Automatically source ros2 setup
RUN echo "source /opt/ros/jazzy/setup.bash" >> /root/.bashrc

WORKDIR /root/main_ws

COPY ./main_ws /root/main_ws/

CMD ["bash"]

# rosbridge を起動
#ros2 launch rosbridge_server rosbridge_websocket_launch.xml