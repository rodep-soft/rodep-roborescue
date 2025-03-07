# このDockerfileはRos2:humbleの環境構築用です。
#
# 以下注意点
#
# WARNINGが出てくると思いますが、取り敢えず全部無視してください。
# また、Docker-CLIの使い方はここで示しませんが、https://docs.docker.com/を参考に。
# docker build / docker run / docker ps / docker images あたりはよく使います。
# rmやdeviceなども知っておく必要がありそうです。困ったらAIに投げればヒントをくれると思います。
#
# 以下権限まわりの話
# 「最小権限の原則(PoLP)」を意識すること！
# gitを積極的に使いましょう。
# rootでの作業をなるべく避けること！危険です。
# /dev(device)以下のファイル等扱うときは--deviceを使いましょう。
# また、この場合--previledgedも使えますが、セキュリティ上問題があるので必要性が無いなら避けましょう。
#
# ssh認証まわり
# $ ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
# ~/.ssh/id_rsa（秘密鍵）
# ~/.ssh/id_rsa.pub（公開鍵）
# ssh test
# RUN ssh -T git@github.com
#
# 
# example usage
# $ docker build --build-arg USERNAME=myuser --build-arg PASSWORD=mypassword \
# --build-arg SSH_PRIVATE_KEY="$(cat ~/.ssh/id_rsa)" \
# --build-arg GIT_USERNAME="mygituser" \
# --build-arg GIT_EMAIL="mygituser@example.com" \
# -t my_ros_image .


# ベースイメージ
FROM osrf/ros:humble-desktop

# 必要なパッケージをインストール
RUN apt update && apt upgrade -y && \
    apt install -y \
    nano vim fish git curl wget htop tmux sudo \
    build-essential cmake python3-pip openssh-client && \
    apt clean && rm -rf /var/lib/apt/lists/*

# 一般ユーザーの追加、パスワード設定（yourname と yourpassword は環境変数または build-arg で渡すべき）
ARG USERNAME=yourname
ARG PASSWORD=yourpassword
RUN useradd -ms /usr/bin/bash $USERNAME && \
    echo "$USERNAME:$PASSWORD" | chpasswd && \
    echo "$USERNAME ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# SSHディレクトリを作成
RUN mkdir -p /home/$USERNAME/.ssh && \
    chmod 700 /home/$USERNAME/.ssh

# ローカルマシンのSSH鍵をコンテナにコピー（build時に --build-arg SSH_PRIVATE_KEY=<秘密鍵> を使う）
ARG SSH_PRIVATE_KEY
RUN echo "$SSH_PRIVATE_KEY" > /home/$USERNAME/.ssh/id_rsa && \
    chmod 600 /home/$USERNAME/.ssh/id_rsa

# SSH設定ファイルを作成（リモートのホストの確認を無視するため）
RUN echo "Host github.com\n\tStrictHostKeyChecking no\n" >> /home/$USERNAME/.ssh/config

# .bashrcにROS2の環境設定を追加
RUN echo "source /opt/ros/humble/setup.bash" >> /home/$USERNAME/.bashrc

# 必要な権限を変更
RUN chown -R $USERNAME:$USERNAME /home/$USERNAME/.ssh

# Gitのユーザー名とメールアドレスをARGで渡す
ARG GIT_USERNAME=yourusername
ARG GIT_EMAIL=youremail@example.com

# Gitの設定
RUN git config --global user.name "$GIT_USERNAME" && \
    git config --global user.email "$GIT_EMAIL" && \
    git config --global core.sshCommand "ssh -i /home/$USERNAME/.ssh/id_rsa"

# alias
RUN echo "alias ll='ls -la'" >> /home/$USERNAME/.bashrc && \
    echo "alias gs='git status'" >> /home/$USERNAME/.bashrc && \
    echo "alias gst='git stash'" >> /home/$USERNAME/.bashrc && \
    echo "alias gcl='git clone'" >> /home/$USERNAME/.bashrc && \
    echo "alias ..='cd ..'" >> /home/$USERNAME/.bashrc && \
    echo "alias ...='cd ../../'" >> /home/$USERNAME/.bashrc


# 一般ユーザーに切り替え
USER $USERNAME
WORKDIR /home/$USERNAME
SHELL ["/usr/bin/bash", "-c"]
