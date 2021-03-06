# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amalliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 23:55:29 by amalliar          #+#    #+#              #
#    Updated: 2021/01/25 20:19:04 by amalliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL      := /bin/sh
CC         := clang
CFLAGS     := -Wall -Wextra -fdiagnostics-color -g -pipe \
              -march=native -O2 -flto
INCLUDE    := -I./include -I./libft/include
NAME       := minishell
LIBFT      := ./libft/libft.a
LIBS       := -L./libft -lft
SRCDIR     := src
OBJDIR     := .obj
DEPDIR     := .dep

BUILTIN_SRCS := builtin.c \
                env_main.c \
                echo_main.c \
                pwd_main.c \
                cd_main.c \
                export_main.c \
                unset_main.c \
                exit_main.c
BUILTIN_SRCS := $(addprefix builtin/, $(BUILTIN_SRCS))

UTILS_SRCS := error_tools.c \
              strarr_tools.c \
              prompt_tools.c \
              env_tools.c \
              env_tools_2.c \
              fd_tools.c \
              test_tools.c \
              exit_failure.c \
              get_full_name.c \
              handlers.c
UTILS_SRCS := $(addprefix utils/, $(UTILS_SRCS))

LEXER_SRCS := lexer.c \
              lexer_2.c \
	      lexer_utils.c \
	      lexer_utils_2.c
LEXER_SRCS := $(addprefix lexer/, $(LEXER_SRCS))

PARSER_SRCS:= parser.c \
              parser_2.c \
              parser_3.c \
              parser_utils.c \
              parser_utils_2.c
PARSER_SRCS := $(addprefix parser/, $(PARSER_SRCS))

SRCS       := main.c \
              process.c
SRCS       := $(SRCS) $(LEXER_SRCS) $(PARSER_SRCS) $(UTILS_SRCS) $(BUILTIN_SRCS)
SRCS       := $(addprefix src/, $(SRCS))

OBJS       := $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPS       := $(SRCS:$(SRCDIR)/%.c=$(DEPDIR)/%.d)

# Run multiple threads.
MAKEFLAGS  = -j 4 --output-sync=recurse --no-print-directory

# Protect against make incorrectly setting 'last modified' attribute
# when running in parallel (-j flag).
POST_COMPILE = mv -f $(DEPDIR)/$*.tmp $(DEPDIR)/$*.d && touch $@

# Define some colors for echo:
LGREEN     := \033[1;32m
WHITE      := \033[1;37m
NOC        := \033[0m

all: $(NAME)
$(NAME): $(OBJS) $(LIBFT)
	@echo -e "$(LGREEN)Linking executable $(NAME)$(NOC)"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LIBS) -o $@
	@echo -e "Built target $(NAME)"
.PHONY: all

$(LIBFT): NONE
	@$(MAKE) -C ./libft
.PHONY: NONE

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEPDIR)/%.d | $(OBJDIR) $(DEPDIR)
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MF $(DEPDIR)/$*.tmp -c $< -o $@
	@$(POST_COMPILE)
$(OBJDIR):
	@mkdir -p $(dir $(OBJS))
$(DEPDIR):
	@mkdir -p $(dir $(DEPS))
$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

clean:
	@$(MAKE) -C ./libft clean
	@echo -e "$(WHITE)Removing C object files...$(NOC)"
	@-rm -rf $(OBJDIR)
	@echo -e "$(WHITE)Removing make dependency files...$(NOC)"
	@-rm -rf $(DEPDIR)
.PHONY: clean

fclean: clean
	@$(MAKE) -C ./libft fclean
	@echo -e "$(WHITE)Removing executable $(NAME)$(NOC)"
	@-rm -f $(NAME)
.PHONY: fclean

re:
	$(MAKE) fclean
	$(MAKE) all
.PHONY: re

help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... fclean"
	@echo "... re"
.PHONY: help
run: all
	./$(NAME)
.PHONY: run

# Do not include dependency files if the current goal is
# set to clean/fclean/re.
ifeq ($(findstring $(MAKECMDGOALS), clean fclean re),)
    -include $(DEPS)
endif
