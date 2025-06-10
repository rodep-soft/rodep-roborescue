使い方

.git/hooks以下にpre-commitファイルを作成し、sudo chmod +x pre-commitで実効権限を与えること。コミット時に自動で.cpp/.hppのコードをformatしてくれる。
project全体のformatをかける場合は
$ find ./ -type f ( -name ".cpp" -o -name ".c" -o -name ".hpp" -o -name ".h" ) -exec clang-format -i {} +
以上を実行する。
