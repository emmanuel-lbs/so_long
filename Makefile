#############################  MAKEFILE MINITALK  #############################

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elabasqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 14:01:13 by elabasqu          #+#    #+#              #
#    Updated: 2021/06/23 14:01:13 by elabasqu         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

##############################  SOURCE & OBJETS  ###############################

SRCS = src/so_long.c \
	   src/parsing/parsing.c \
	   src/parsing/create_map.c \
	   src/parsing/check_map.c \
	   src/parsing/parsing_utils.c \
	   src/key.c \
	   src/display.c \
	   src/move.c \
	   src/first.c \
	   src/resize.c \

OBJS = $(SRCS:.c=.o)

################################  VARIABLES  ###################################

NAME = so_long

INCLUDE = includes/so_long.h includes/structure.h

RM = rm -f

GCCF = gcc -Wall -Wextra -g #-Werror

##################################  RULES  #####################################

all :	libf $(NAME)


$(NAME):	$(INCLUDE) $(OBJS)
	${MAKE} -C mlx
	ln -sf mlx/libmlx.dylib
	$(GCCF) $(OBJS) libmlx.dylib libft.a -o $(NAME)

%.o: %.c	$(INCLUDE) 
	${GCCF} -c $< -o $@

libf:
	$(MAKE) -C libft
	ln -sf libft/libft.a

############################  CLEAN & RE & phony  ##############################

clean:
	${MAKE}  -C libft/ fclean
	${MAKE}  -C mlx/ clean
	$(RM) libft.a
	$(RM) libmlx.dylib
	${RM} ${OBJS} 

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus libf

#################################### FIN  ######################################
