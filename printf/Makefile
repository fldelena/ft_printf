# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fldelena <fldelena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/31 19:30:21 by fldelena          #+#    #+#              #
#    Updated: 2021/02/01 19:08:41 by fldelena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCFD = src/
SRC =  ft_printf.c accuracy_control.c ft_atoi.c ft_isdigit.c ft_putchar_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c init_of_flags.c left_side_up.c \
out_options.c type_conversion.c type_identification.c width_cont_ast.c \
width_control.c write_symbol.c zero_add.c empty_line.c kostil.c\
type_i_utils.c type_p_utils.c type_u_utils.c type_x_utils.c \
type_c.c type_i.c type_p.c type_s.c type_u.c type_x.c
SRCS = $(addprefix $(SRCFD)/, $(SRC))

OBJFD = obj/
OBJ = $(addprefix $(OBJFD), $(SRC:.c=.o))

HEADFD = include/
HEAD = ft_printf.h
HRDS =  $(addprefix $(HEADFD), $(HEAD)

all: $(NAME)
$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

$(OBJFD)%.o: $(SRCFD)%.c $(HEADFD)/ft_printf.h
	@mkdir -p obj
	@gcc $(FLAG) -I $(HEADFD) -c $< -o $@
clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJFD)
	@echo "OBJ deleted"
fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"
re: fclean all

.PHONY: all, clean, fclean, re
