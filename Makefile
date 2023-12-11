NAME =  pipex
CFLAGS = -Werror -Wextra -Wall
SRC = main.C
SRC_O = {SRC:.c=.o}
LIBFT = -L libft -lft
MAKE = make -C
all: ${NAME}

${NAME} : ${SRC_O}
		${MAKE} ${LIBFT}
		cc ${CFLAGS} ${SRC} -o ${NAME}
clean:
	rm -f ${OBJ}
	${MAKE} libft clean

fclean: all
	rm -f ${NAME}	   
	${MAKE} libft clean

re : fclean all

.PHONY: fclean clean re all