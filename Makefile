NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

SRCS        = ft_printf.c \
              ft_putnbr.c \
              ft_putstr.c \
              ft_put_un_int.c \
              ft_puthex.c \
              ft_putptr.c

BONUS_SRCS  = ft_printf_bonus.c \
              ft_putnbr_bonus.c \
              ft_puthex_bonus.c

OBJS        = $(SRCS:.c=.o)
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS) .bonus

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: .bonus

.bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	@touch .bonus

.PHONY: all clean fclean re bonus