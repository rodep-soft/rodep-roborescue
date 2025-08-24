
# docker commands

docker-dev:
	docker compose up -d
	docker compose exec -it robocup bash

up:
	docker compose up -d

down:
	docker compose down

build:
	docker compose build

exec:
	docker compose exec -it robocup bash


# git commands

commit:
	@git add .
	@git commit -m "$(msg)"
