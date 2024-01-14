FLAGS=-Wall -Wextra -Werror
NAME=push_swap
BONUS_NAME=checker
SRC=src/cost_operations.c src/operations_b.c src/operations_a.c src/operations_both.c src/push_swap.c src/small_sort.c src/stack_basics.c src/stack_utils.c src/stacks_init.c src/target_operations.c src/turkish_movements.c src/turkish_setting.c src/turkish_sort.c src/turkish_utils.c src/validations.c src/validations2.c
BONUS_SRC=src/bonus/checker_bonus.c src/bonus/instruction_checker_bonus.c src/stack_utils.c src/operations_a.c src/operations_b.c src/operations_both.c src/stack_basics.c src/validations.c src/stacks_init.c src/validations2.c
LIBFT=libft/libft.a
CC=cc
RED=\e[31m
GREEN=\e[32m
ENDCOLOR=\e[0m
# ARG3:=$(shell ruby -e "puts (-1..1).to_a.shuffle.join(' ')")
# ARG5:=$(shell ruby -e "puts (-2..2).to_a.shuffle.join(' ')")
# ARG100:=$(shell ruby -e "puts (-50..49).to_a.shuffle.join(' ')")
# ARG500:=$(shell ruby -e "puts (-250..249).to_a.shuffle.join(' ')")
ARG3:=$(shell shuf -i 1-10000 -n 3)
ARG5:=$(shell shuf -i 1-10000 -n 5)
ARG100:=$(shell shuf -i 1-10000 -n 100)
ARG500:=$(shell shuf -i 1-10000 -n 500)

all: $(NAME)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)finished compiling push_swap$(ENDCOLOR)"

$(LIBFT):
	cd libft && make

3: $(NAME) checker
	@echo $(ARG3)
	@./$(NAME) $(ARG3); echo "Operations: $(shell ./$(NAME) $(ARG3) | wc -l)"
	@./$(NAME) $(ARG3) | ./checker_linux $(ARG3)

5: $(NAME) checker
	@echo $(ARG5)
	@./$(NAME) $(ARG5); echo "Operations: $(shell ./$(NAME) $(ARG5) | wc -l)"
	@./$(NAME) $(ARG5) | ./checker_linux $(ARG5)

100: $(NAME) checker
	@echo $(ARG100)
	@./$(NAME) $(ARG100); echo "Operations: $(shell ./$(NAME) $(ARG100) | wc -l)"
	@./$(NAME) $(ARG100) | ./checker_linux $(ARG100)

500: $(NAME) checker
	@echo $(ARG500)
	@./$(NAME) $(ARG500); echo "Operations: $(shell ./$(NAME) $(ARG500) | wc -l)"
	@./$(NAME) $(ARG500) | ./checker_linux $(ARG500)

checker:
	curl -L https://cdn.intra.42.fr/document/document/22069/checker_linux -o checker_linux
	chmod 777 checker_linux

clean:
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	@echo "$(GREEN)finished cleaning push_swap$(ENDCOLOR)"

bonus:
	$(CC) $(FLAGS) $(BONUS_SRC) $(LIBFT) -o $(BONUS_NAME)
	@echo "$(GREEN)finished compiling push_swap Checker$(ENDCOLOR)"

fclean: clean
	cd libft && make fclean
	rm -f checker_linux

re: fclean all

.PHONY: clean fclean 3 5 100 500
