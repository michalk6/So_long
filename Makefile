# Nazwa pliku utworzonego po kompilacji
NAME	:= so_long
# Okreslenie ktory kompilator ma zostac uzyty
CC	:= gcc
# Zmienna przechowujaca Flagi czyli opcje kompilacji
CFLAGS	:= -Wall -Wextra -Werror -Iheaders/
# Zmienna z Opcjami Linkera
MXFLAGS	:= -L../minilibx-linux -lmlx_Linux -lX11 -lXext
# Zmienna przechowujaca sciezke do plikow zrodlowych .c z folderu game_functions
SOURCE	:= test.c map_load.c map_rules.c map_validation.c


# -||- gnl
# GNL	:= get_next_line/*.c
# -||- libf
# LIBFT	:= libft/*.c
# -||- printf
# PRINTF	:= ft_printf/*.c
# Zmienna przechowujaca sciezke do folderu minilibx-linux
MLIBX	:= ../minilibx-linux/
LIBFT	:= ./libftprintf/libftprintf.a
# Cele
all:
	# wykonuje make w folderze minilibx-linux
	make -C $(MLIBX)
	# kompiluje wszystkie pliki zrodlowe i linkuje je razem z bibliotekami tworzac plik wykonwywalny
	$(CC) $(CFLAGS) $(SOURCE) $(MXFLAGS) $(LIBFT) -o $(NAME)
# wykonuje polecenie make clean i usuwa pliki tymczasowe oraz obiektowe 
clean:
	make clean -C $(MLIBX)
	rm -rf *.o
# to samo co clean + usuwa plik wykonywalny
fclean: clean
	rm -rf $(NAME)
# usuwanie + ponowna kompilacja projektu od poczatku
re: fclean all