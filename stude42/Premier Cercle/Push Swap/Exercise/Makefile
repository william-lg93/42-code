NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = operation.c \
	reverse_operation.c \
	switch_operation.c \
	push_operation.c \
	parsing.c \
	parsing_error.c \
	parsing_flags.c \
	ranck.c \
	lst_utils.c \
	bench_output.c \
	bench_utils.c \
	algo_simple.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
