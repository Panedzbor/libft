SRCS			=	ft_split.c ft_calloc.c

SRCS_BONUS 		=	ft_tolower.c

OBJS	=	${SRCS:.c=.o}
BONUS_OBJ	= ${SRCS_BONUS:.c=.o}

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):  $(OBJS)
				ar rcs $@ $^

bonus:			$(OBJS) $(BONUS_OBJ)
				ar rcs ${NAME} $(OBJS) $(BONUS_OBJ)

clean:
				$(RM) $(OBJS) $(BONUS_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus