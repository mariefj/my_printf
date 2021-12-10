NAME	=	printf

SRCS	=	src/main.c			\
		src/my_printf.c			\
		src/is_flag.c			\
		src/set_flags.c			\
		src/conversion_func.c		\
		src/conversion_base_func.c	\
		src/my_put_ptr_address_va.c	\
		src/my_struct_spec.c


OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-g -Wall -Werror -W -Wextra -I./include -I./lib/my

LDFLAGS	=	-L./lib/my -lmy

CC	=	gcc

RM	=	rm -rf

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all: clean fclean $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all debug test clear fclean re