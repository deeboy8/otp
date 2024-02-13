CC = gcc
CFLAGS  += -Wall -Werror -Wextra -g3 -Wunused-parameter # -E for preprocessor output
SANITIZE = -fsanitize=address
MAIN = otp
SRCS = $(wildcard *.c) munit/munit.c 
INCLUDES := $(INCLUDES) munit/munit.h
OBJS = $(SRCS:.c=.o)

ALL: $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(SANITIZE) -o $@ $(LINKERFLAG) $^


debugger: $(SRCS)
	$(CC) $(CFLAGS) $(SANITIZE) -g -o $@ $(LINKERFLAG) $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(MAIN) $(DEBUG)

re: fclean all