HEADER = philo.h

NAME = philo

CC	= gcc

CFLAGS = -g -Wextra -Wall -Werror

RM = rm -rf

SRC =	main.c\
		args_check.c\
		start.c\
		routine.c\
		routine1.c\

OBJ = ${SRC:.c=.o}

all : ${NAME}

${NAME} :	${OBJ}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
		${RM} ${OBJ}

fclean :
	${RM} ${OBJ} ${NAME}

re : fclean all