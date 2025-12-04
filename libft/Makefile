# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabrsouz <gabrsouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 20:48:58 by gabrsouz          #+#    #+#              #
#    Updated: 2025/07/22 15:09:21 by gabrsouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FILES := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
      ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
      ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
      ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlcat.c ft_strlcpy.c \
      ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
      ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
      ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	  ft_printf.c ft_printf_utils.c ft_is_unsigned_int.c \
	  get_next_line.c get_next_line_utils.c
OBJS := $(FILES:%.c=%.o)
HEADER = libft.h
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs
.PHONY: all clean fclean re
$(NAME): $(OBJS) $(HEADER)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
all: $(NAME)

clean:
	@echo "Removing object files"
	$(RM) $(OBJS)

fclean: clean
				@echo "Removing the library"
				$(RM) $(NAME)
re: fclean all
		@echo "Removing and recreating everything"
