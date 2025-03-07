# Operator ノード

このプロジェクトは ROS 2 (Robot Operating System 2) 上で動作する `Operator` ノードです。本ノードは、ジョイスティックの入力を受け取り、ロボットの駆動速度を制御するためのメッセージを送信します。また、サービスを介して動作モードを変更できます。

## 必要な依存関係

- ROS 2 (Humble, Iron など)
- `sensor_msgs` パッケージ
- `custom_interfaces` パッケージ（`DriverVelocity` メッセージおよび `SetMode` サービスを含む）

## ビルド方法

```sh
colcon build --packages-select operator
source install/setup.bash
```

## 使用方法

### ノードの実行

```sh
ros2 run operator operator
```

### ジョイスティック操作

- **ボタン 4 (L1)** を押すと `STOP` モードに変更
- **ボタン 6 (R1)** を押すと `DRIVE` モードに変更
- **左スティック (axes[1])** と **右スティック (axes[3])** でロボットの速度を制御

### サービスを使用してモードを変更

```sh
ros2 service call /set_mode custom_interfaces/srv/SetMode "{mode: 'STOP'}"
ros2 service call /set_mode custom_interfaces/srv/SetMode "{mode: 'DRIVE'}"
```

## トピック

| トピック名  | 型 | 説明 |
|-------------|----------------------------|------------------------------|
| `/joy`      | `sensor_msgs/msg/Joy`      | ジョイスティックの入力を購読 |
| `/driver`   | `custom_interfaces/msg/DriverVelocity` | モータの速度をパブリッシュ |

## サービス

| サービス名  | 型 | 説明 |
|-------------|----------------------------|------------------------------|
| `/set_mode` | `custom_interfaces/srv/SetMode` | モード (`STOP` / `DRIVE`) を設定 |

## 実装の概要

- `joy_callback`: ジョイスティックの入力を処理し、モードの切り替えや速度計算を行う。
- `set_mode_callback`: `/set_mode` サービスのリクエストを処理し、モードを変更。
- `applyDeadzone`: スティックのデッドゾーンを適用。
- `main`: ROS 2 ノードを初期化し、`Operator` ノードを起動。

## ライセンス

MIT License
