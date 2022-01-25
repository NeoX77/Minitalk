# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:51:08 by wdebotte          #+#    #+#              #
#    Updated: 2022/01/25 14:11:03 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN		= \033[0m\033[96m
GREEN		= \033[1m\033[92m

PREFIX		= \n${GREEN}=> ${CYAN}[${GREEN}minitalk${CYAN}]

NAME_SERVER	= server
NAME_CLIENT	= client

SRCS_SERVER	= srcs/server.c
SRCS_CLIENT	= srcs/client.c

HEADERS		= \

OBJS_SERVER	= ${SRCS_SERVER:.c=.o}
OBJS_CLIENT	= ${SRCS_CLIENT:.c=.o}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -rf

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader
FLAGH		= -R CheckDefine

.c.o:
				@echo "${PREFIX}Compiling all ${GREEN}.c ${CYAN}files to ${GREEN}.o ${CYAN}..."
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS_SERVER} ${OBJS_CLIENT}
				@echo "${PREFIX}Compiling ${GREEN}minitalk Program ${CYAN}..."
				${CC} ${OBJS_SERVER} -o ${NAME_SERVER}
				${CC} ${OBJS_CLIENT} -o ${NAME_CLIENT}

clean:
				@echo "${PREFIX}Removing ${GREEN}Objects ${CYAN}files ..."
				${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean:		clean
				@echo "${PREFIX}Removing ${GREEN}${NAME_SERVER} ${CYAN}& ${GREEN}${NAME_CLIENT} \
				program ${CYAN}..."
				${RM} ${NAME_SERVER} ${NAME_OBJS}

re:			fclean re

norminette:
				@echo "${PREFIX}Checking norminette for ${GREEN}.c ${CYAN}files ..."
				${NORM} ${FLAGC} ${SRCS_SERVER} ${SRCS_CLIENT}
				@echo "${PREFIX}Checking norminette for ${GREEN}.h ${CYAN}files ..."
				${NORM} ${FLAGH} ${HEADERS}

.PHONY:		all clean fclean re norminette
