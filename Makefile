# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 17:28:15 by mallard           #+#    #+#              #
#    Updated: 2017/10/16 17:46:07 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE = \033[38;5;129m
GREEN = \033[38;5;82m
RED = \033[38;5;208m
DEFAULT = \x1b[0m

NAME = fdf

LIBFT = ./libft/libft.a

MLX = ./minilibx/libmlx.a

SRC = main.c check.c parse.c map.c mlx.c xyz.c draw.c

SRCS = $(addprefix src/, $(SRC));

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wextra -Wall -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

norme :
		@echo "$(RED)     .-') _            _  .-') _   .-')      ('-."
		@echo "    ( OO ) )          ( \( -O ( '.( OO )_  _(  OO)"
		@echo ",--./ ,--,' .-'),-----.,------.,--.   ,--.(,------."
		@echo "|   \ |  |\( OO'  .-.  |   /\`. |   \`.'   | |  .---'"
		@echo "|    \|  | /   |  | |  |  /  | |         | |  |"
		@echo "|  .     |/\_) |  |\|  |  |_.' |  |'.'|  |(|  '--."
		@echo "|  |\    |   \ |  | |  |  .  '.|  |   |  | |  .--'"
		@echo "|  | \   |    \`'  '-'  |  |\  \|  |   |  | |  \`---."
		@echo "\`--'  \`--'      \`-----'\`--' '--\`--'   \`--' \`------'"
		@echo "$(DEFAULT)"
		@norminette ./include libft/include
		@norminette $(SRCS)
		@norminette libft/src

$(MLX) :
	@$(MAKE) -C ./minilibx

$(LIBFT) :
		@$(MAKE) -C ./libft

$(NAME) : $(LIBFT) $(MLX)
		@echo "$(PURPLE)build $(NAME)$(DEFAULT)"
		@gcc -c $(SRCS)
		@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX)

clean :
		@$(MAKE) clean -C ./minilibx
		@$(MAKE) clean -C ./libft
		@rm -f $(OBJ)
		@echo "$(GREEN)clean $(NAME)'s object$(DEFAULT)"

fclean : clean
		@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
		@rm -f $(NAME)

re : fclean all

.PHONY : re all norme clean fclean
