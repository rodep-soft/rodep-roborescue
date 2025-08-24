# Robocup repo

## RULES

### branch rules

- 大会直前までmainへの直接pushは禁止とする。必ずブランチを切って、PRを作成し、CIパスを確認してからマージすること。
- ブランチの命名はprefix+suffixの構造にし、prefixは適宜使い分けること

feat/     → 新機能追加          (feature)
fix/      → バグ修正            (bugfix)
hotfix/   → 緊急修正            (hotfix)
ci/       → CI/CDや自動化       (ci)
chore/    → 環境設定・雑務       (devやmiscをまとめる)
docker/   → Docker             (ci以外のDocker関連作業全般)
docs/     → ドキュメント修正
refactor/ → リファクタリング
test/     → テスト追加/修正
dev/      → 開発中              (曖昧。推奨はしないが管理が難しければ使ってよい)

### commit message rules

