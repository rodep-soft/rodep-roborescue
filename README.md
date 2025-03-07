# Test WS

ROS2のワークスペースです。

## 概要

レスキューロボットのソースコード等

## 主な管理方法

-   **課題管理・バグ報告:** Issues
-   **進捗状況:** Projects

## 重要事項

-   Dockerの導入により、開発環境と本番環境の一貫性を確保。

## Git clone時の設定（SSH認証）

1.  **SSH鍵の生成**

    ターミナルで以下のコマンドを実行:

    ```bash
    ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
    ```

    -   ファイルの保存場所はデフォルトで `~/.ssh/id_rsa`。変更不要であればEnterキーを押下。
    -   パスフレーズは任意で設定。

2.  **公開鍵の確認**

    以下のコマンドで公開鍵を確認し、コピー:

    ```bash
    cat ~/.ssh/id_rsa.pub
    ```

    -   出力された文字列（`ssh-rsa` で始まる長い文字列）をコピー。

3.  **GitHubに公開鍵を追加**

    GitHubの設定に公開鍵を追加:

    1.  GitHubにログインし、右上のプロフィールアイコンからSettingsを選択。
    2.  左側のメニューからSSH and GPG keysを選択。
    3.  New SSH keyをクリック。
    4.  Titleに任意の名前を付け、Keyにコピーした公開鍵を貼り付け。
    5.  Add SSH keyをクリックして保存。

4.  **接続確認**

    以下のコマンドを実行して、正しく設定されたか確認:

    ```bash
    ssh -T git@github.com
    ```

    -   正常に接続されれば、「Hi \[username]\! You've successfully authenticated...」と表示。

5.  **リポジトリをクローン**

    SSH接続成功後、以下のコマンドでリポジトリをクローン:

    ```bash
    git clone git@github.com:username/repository.git
    ```

## ファイル構成

Test_WS/  
├── resources/ # Dockerfile など（本プロジェクトには直接関係なし）  
└── src/ # ROS2 パッケージ  


## 備考

-   ネットワーク周りは未定。今後検討予定。

## 補足
-   ROS2のワークスペースの構築、ROS2のパッケージのビルド、ROS2のネットワークの設定などは、ROS2の公式ドキュメントに詳しく記載されているため参照のこと。
-   ROS2の公式ドキュメント[ROS 2 Documentation: Welcome\!](https://docs.ros.org/en/humble/index.html)
