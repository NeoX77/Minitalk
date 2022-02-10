# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 13:51:08 by wdebotte          #+#    #+#              #
#    Updated: 2022/02/10 15:46:09 by wdebotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN		= \033[0m\033[96m
GREEN		= \033[1m\033[92m

PREFIX		= \n${GREEN}=> ${CYAN}[${GREEN}minitalk${CYAN}] 

NAME_SERVER	= server
NAME_CLIENT	= client

SRCS_SERVER	= srcs/server.c
SRCS_CLIENT	= srcs/client.c

OBJS_SERVER	= ${SRCS_SERVER:.c=.o}
OBJS_CLIENT	= ${SRCS_CLIENT:.c=.o}

CC			= clang
CFLAGS		= -Wall -Wextra -Werror
INCS		= -Ilibft/includes/

RM			= rm -rf
MAKE		= make -C

NORM		= norminette
FLAGC		= -R CheckForbiddenSourceHeader

PATHLIBFT	= libft/
LIBFT		= -L ${PATHLIBFT} -lft

.c.o:
				@echo "${PREFIX}Compiling all ${GREEN}.c ${CYAN}to ${GREEN}.o ${CYAN}..."
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o} $(INCS)

all:		${OBJS_SERVER} ${OBJS_CLIENT}
				${MAKE} ${PATHLIBFT} 
				@echo "${PREFIX}Compiling ${GREEN}minitalk Program ${CYAN}..."
				${CC} ${OBJS_SERVER} ${LIBFT} -o ${NAME_SERVER} $(INCS)
				${CC} ${OBJS_CLIENT} ${LIBFT} -o ${NAME_CLIENT} $(INCS)

clean:
				@echo "${PREFIX}Removing ${GREEN}Objects ${CYAN}files ..."
				${RM} ${OBJS_SERVER}
				${RM} ${OBJS_CLIENT}

fclean:		clean
				${MAKE} ${PATHLIBFT} fclean
				@echo "${PREFIX}Removing ${GREEN}${NAME_SERVER} ${CYAN}& ${GREEN}${NAME_CLIENT} \
program ${CYAN}..."
				${RM} ${NAME_SERVER}
				${RM} ${NAME_CLIENT}

re:			fclean all

norminette:
				@echo "${PREFIX}Checking norminette for ${GREEN}.c ${CYAN}files ..."
				${NORM} ${FLAGC} ${SRCS_SERVER} ${SRCS_CLIENT}

.PHONY:		all clean fclean re norminette
