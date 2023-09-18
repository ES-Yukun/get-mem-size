NAME	:= getmem
CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror
SRCS	:= main.c
BIN		:= /usr/local/bin

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(NAME)

re: clean all

install: $(BIN)
	install $(NAME) $(BIN)