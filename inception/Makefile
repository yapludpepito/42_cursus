GREEN=\033[0;32m

all:
	@mkdir -p /home/pdubacqu/data/www /home/pdubacqu/data/database
	@docker compose -f srcs/docker-compose.yml build
	@docker compose -f srcs/docker-compose.yml up
clean:
	@docker compose -f srcs/docker-compose.yml down
	@rm -rf /home/pdubacqu/data/*/* /home/pdubacqu/data/www/.done
stop:
	@docker compose -f srcs/docker-compose.yml down
fclean:
	@docker compose -f srcs/docker-compose.yml down
	@rm -rf /home/pdubacqu/data/*/* /home/pdubacqu/data/www/.done
	@docker system prune -af
info:
	@echo "\n$(GREEN)[Containers currently running]\n"
	@echo "$(GREEN)------------------------------------------------------------------------------\n"
	@docker ps
	@echo "\n$(GREEN)[Docker images existing]"
	@echo "$(GREEN)------------------------------------------------------------------------------"
	@docker image ls
	@echo "\n$(GREEN)[Docker volumes existing]"
	@echo "$(GREEN)------------------------------------------------------------------------------"
	@docker volume ls
	@echo "\n$(GREEN)[Docker network existing]"
	@echo "$(GREEN)------------------------------------------------------------------------------"
	@docker network ls
