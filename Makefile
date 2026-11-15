NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I inc
RM          = rm -f
AR          = ar rcs


ROOT_SRCS   = ft_printf.c
ROOT_BONUS  = ft_printf_bonus.c

SRC_SRCS    = src/ft_putnbr.c \
              src/ft_putstr.c \
              src/ft_put_un_int.c \
              src/ft_puthex.c \
              src/ft_putptr.c

SRC_BONUS   = src/ft_putnbr_bonus.c \
              src/ft_puthex_bonus.c

SRCS        = $(ROOT_SRCS) $(SRC_SRCS)
BONUS_SRCS  = $(ROOT_BONUS) $(SRC_BONUS)

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus