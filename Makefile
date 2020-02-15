NAME	= libmy_malloc.so

CC	= gcc

RM	= rm -f

SRCS	= ./src/list.c \
	  ./src/malloc.c \
	  ./src/free.c	\
	  ./src/calloc.c \
	  ./src/realoc.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra -fpic

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) -shared $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
