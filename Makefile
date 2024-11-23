# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earutiun <earutiun@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 16:13:54 by earutiun          #+#    #+#              #
#    Updated: 2024/11/20 18:23:15 by earutiun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# target
NAME=libft.a

# complier and flags
CC=cc
CFLAGS=-Wall -Wextra -Werror -I$(H_FOLD)

# folders
SRC_FOLD=srcs
OBJ_FOLD=objs
H_FOLD=hdrs

# files
SOURCES=$(wildcard $(SRC_FOLD)/ft*.c)
OBJECTS=$(SOURCES:$(SRC_FOLD)/%.c=$(OBJ_FOLD)/%.o)

# rules
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)

$(OBJ_FOLD):
	mkdir -p $(OBJ_FOLD)

$(OBJ_FOLD)/%.o: $(SRC_FOLD)/%.c | $(OBJ_FOLD)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rmdir $(OBJ_FOLD)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

test:
	$(CC) $(CFLAGS) test_libft.c -L. -lft
	./a.out
