FROM osrf/ros:humble-desktop

RUN apt update && apt upgrade -y && \
    apt install -y \
    nano vim fish git curl wget htop tmux sudo less \
    build-essential cmake python3-pip openssh-client \
    python3-opencv && \
    apt clean && rm -rf /var/lib/apt/lists/*
