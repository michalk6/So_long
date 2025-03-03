NAME	= 	so_long

SRCDIR 	= 	src

INCDIR 	= 	include

SRCS	=	$(SRCDIR)/control_utils \
			$(SRCDIR)/control \
			$(SRCDIR)/free_elements \
			$(SRCDIR)/graph_assets \
			$(SRCDIR)/graph_render \
			$(SRCDIR)/init_data_utils \
			$(SRCDIR)/init_data \
			$(SRCDIR)/map_load \
			$(SRCDIR)/map_rules \
			$(SRCDIR)/map_validation \
			$(SRCDIR)/play_game \
			$(SRCDIR)/so_long \

CC			= cc

FLAGS		= -Wall -Wextra -Werror

CFILES		= $(SRCS:%=%.c)

OFILES		= $(SRCS:%=%.o)

LIBFTDIR	= ./libftprintf

MLIBXDIR	= ../minilibx-linux/

LIBFT		= -L ./libftprintf -lftprintf

MLIBX		= -L ../minilibx-linux -lmlx_Linux -lX11 -lXext

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLIBXDIR)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME) $(LIBFT) $(MLIBX)

all: $(NAME)

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f $(OFILES)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus