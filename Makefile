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

NICE = $$'$(BOLD)$(GREEN)[The coding style logs : ]\t$(DEFAULT)'
NICE_END = $$'$(BOLD)$(GREEN)[Coding style logs end ! ]\t$(DEFAULT)'
NICE_SUP =$$'$(BOLD)$(YELLOW)[Please press -> y <- for clean logs.]\t$(DEFAULT)'
NICE_DESTROY = $$'$(BOLD)$(RED)[The logs are cleaned !]\t$(DEFAULT)'
COMPILE = $$'$(BOLD)$(GREEN)[All the project are compiled !]\t$(DEFAULT)'

RM = rm -Rf

SOLVER_CREATE = cd solver && make && cd ../

GENERATOR_CREATE = cd generator && make && cd ../

SOLVER_DESTROY = cd solver && make fclean && cd ../

GENERATOR_DESTROY = cd generator && make fclean && cd ../

SOLVER_UNITS = cd solver && make tests_run && cd ../

GENERATOR_UNITS = cd generator && make tests_run && cd ../

CODING_STYLE = coding-style . .

CODING_STYLE_MORE = cat coding-style-reports.log

CODING_DESTROY = rm coding-style-reports.log

all:
	@$(GENERATOR_CREATE)
	@$(SOLVER_CREATE)
	@echo $(COMPILE)

clean:
	@$(RM) solver/solver
	@$(RM) generator/generator

fclean:	clean
	@$(GENERATOR_DESTROY)
	@$(SOLVER_DESTROY)

re: fclean all

tests_run:
	@$(SOLVER_UNITS)
	@$(GENERATOR_UNITS)

nice:
	@$(CODING_STYLE)
	@echo $(NICE)
	@$(CODING_STYLE_MORE)
	@echo $(NICE_END)
	@echo $(NICE_SUP)
	@$(CODING_DESTROY)
	@echo $(NICE_DESTROY)

.PHONY: all, clean, fclean, re
