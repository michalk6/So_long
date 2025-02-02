NAME	= libftprintf

SRCDIR = src

INCDIR = include

SRCS	=	$(SRCDIR)/ft_printf \
			$(SRCDIR)/ft_putchar \
			$(SRCDIR)/ft_putdecimal \
			$(SRCDIR)/ft_puthex_upper \
			$(SRCDIR)/ft_puthex \
			$(SRCDIR)/ft_putint \
			$(SRCDIR)/ft_putptr \
			$(SRCDIR)/ft_putstr \
			$(SRCDIR)/ft_putunsignedhex_upper \
			$(SRCDIR)/ft_putunsignedhex \
			$(SRCDIR)/ft_putunsignedint \
			$(SRCDIR)/ft_putunsignednum_base \
			$(SRCDIR)/get_next_line \

CC	= cc

FLAGS	= -Wall -Wextra -Werror

LIB	= $(NAME).a

CFILES	= $(SRCS:%=%.c)

OFILES	= $(SRCS:%=%.o)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB): $(OFILES)
	$(MAKE) -C ./libft
	cp libft/libft.a $(LIB)
	ar -rc $(LIB) $(OFILES)

all: $(LIB)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OFILES)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re