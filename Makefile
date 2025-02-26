
SRC = main.c calcul.c fractol.c events.c utils.c
OBJ = ${SRC:.c=.o}

CC = cc
CFLAGS = -Imlx
LDFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol

RM = rm -f

all: ${NAME}

%.o: %.c fractol.h
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${OBJ} ${LDFLAGS} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
