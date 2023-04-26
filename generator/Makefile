##
## EPITECH PROJECT, 2023
## B-CPE-200-LYN-2-1-dante-pierre.giordano
## File description:
## Makefile
##

#COLORS
RED			=	\e[31m
GREEN		=	\e[32m
YELLOW		=	\e[33m
DEFAULT		=	\e[0m
BOLD		=	\e[1m
VIOLET		=	\e[35m

#TEXTS
COMPILE = $$'$(BOLD)$(YELLOW)[The project: generator is compiled !]\t$(DEFAULT)'
RE_COMPILE = $$'$(BOLD)$(YELLOW)[The project is recompiled !]\t$(DEFAULT)'
CLEAN = $$'$(BOLD)$(RED)[The useless files are removed !]\t$(DEFAULT)'
FCLEAN =$$'$(BOLD)$(RED)[All old created files have been deleted !]\t$(DEFAULT)'
TESTS_COMPILE =$$'$(BOLD)$(VIOLET)[The Units tests are excecuted !]\t$(DEFAULT)'
TESTS_CLEAN = $$'$(BOLD)$(VIOLET)[The tests are cleaned !]\t$(DEFAULT)'

#SHORTCUTS
NAME			=	generator

TEST_NAME		=	unit_tests

SRC				=	$(shell find ./src -name "*.c")

SRCS_NO_MAIN = $(shell find ./src -type f \( -iname "*.c" ! -iname "main.c" \))

TESTS			=	$(shell find ./tests -name '*.c')

USELESS = $(shell find . -type f -name "*~" -o -name "*.gcda" -o -name "*.gcno")

OBJ				= 	$(SRC:.c=.o)

CRITERION		=	--coverage -lcriterion

CFLAGS			=	-g3 -Wall -Wextra -W -lm

WERROR_FLAG		= -Werror

#RULES
all:	$(NAME)

$(NAME):
	@gcc -o $(NAME) $(SRC) $(CFLAGS)
	@echo $(COMPILE)

%.o: %.c
	@gcc -o $@ -c $< -g

tests_run:
	@gcc -o $(TEST_NAME) $(TESTS) $(CRITERION)
	@echo $(TESTS_COMPILE)
	@./$(TEST_NAME)

clean:
	@rm -f $(USELESS) $(OBJ)
	@echo $(CLEAN)

fclean: clean
	@rm -f $(TEST_NAME) $(NAME)
	@echo $(FCLEAN)

re: fclean all
	@echo $(RE_COMPILE)

cleantest: clean
	@rm -f *.g*
	@echo $(TESTS_CLEAN)

.PHONY: all clean fclean re tests_run
