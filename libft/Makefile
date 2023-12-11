# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-jesu <fde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 21:29:48 by fde-jesu          #+#    #+#              #
#    Updated: 2023/10/04 19:15:06 by fde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = libft.h
CFLAGS = -Wall -Werror -Wextra

FUN = ft_isalpha.c \
      ft_isdigit.c \
      ft_isalnum.c \
      ft_isascii.c \
      ft_isprint.c \
      ft_strlen.c \
      ft_memset.c \
      ft_bzero.c \
      ft_memmove.c \
      ft_memcpy.c \
      ft_strlcpy.c \
      ft_strlcat.c \
      ft_toupper.c \
      ft_tolower.c \
      ft_strchr.c \
      ft_strrchr.c \
      ft_strncmp.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_strnstr.c \
      ft_atoi.c \
      ft_calloc.c \
      ft_strdup.c \
      ft_split.c \
      ft_substr.c \
      ft_strjoin.c \
      ft_strtrim.c \
      ft_split.c \
      ft_strmapi.c \
      ft_striteri.c \
      ft_putchar_fd.c \
      ft_putstr_fd.c \
      ft_putendl_fd.c \
      ft_putnbr_fd.c \
      ft_itoa.c \
      get_next_line.c \
      get_next_line_utils.c \
      ft_printf.c \
      ft_check_specifier.c \
      ft_hexa_xs.c \
      ft_hexa_p.c \
      ft_printf_putnbr.c \
      ft_putnbr_u.c \
      ft_putchar.c \
      ft_writing.c
      

#FUN_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstmap.c
OBJ = ${FUN:.c=.o}
#OBJ_BONUS = ${FUN_BONUS:.c=.o}

all: $(NAME)

$(NAME):
	      cc -g ${CFLAGS} -c -I. ${HEADER} ${FUN}
		ar rcs ${NAME} ${OBJ}

#bonus:	${OBJ_FUN} ${OBJ}
#		ar rcs ${NAME} ${OBJ} ${OBJ_BONUS}

clean:
	rm -f $(OBJ) 
      #$(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
      
re: fclean all

.PHONY: all clean fclean re
.SILENT: