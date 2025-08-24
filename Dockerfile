FROM osrf/ros:jazzy-desktop

RUN apt-get update && apt-get install -y \
    less \
    git \
    vim \
    fish \
    tmux \
    

COPY  ./main_ws /main_ws


CMD ["bash"]


