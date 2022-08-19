# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-hous <mel-hous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/17 10:13:18 by mel-hous          #+#    #+#              #
#    Updated: 2022/08/18 15:23:14 by mel-hous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
		ft_isdead.c\

OBJ = ${SRC:.c=.o}

all : ${NAME}

${NAME} :	${OBJ} ${HEADER}
			${CC} ${CFLAGS} ${OBJ} -o ${NAME}

clean :
		${RM} ${OBJ}

fclean :
	${RM} ${OBJ} ${NAME}

re : fclean all