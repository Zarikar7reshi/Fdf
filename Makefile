NAME = fdf#program name


LIB = ./lib/libfdf.a#fdf files
FTPRINTF = ./lib/libftprintf.a#libft + printf
GNL = ./lib/libgnl.a#getnextline
MINILIBX = ./lib/libmlx.a#minilibx-linux

LIBNAME = libfdf.a
FTPRINTF_NAME = libftprintf.a#libft + printf
GNL_NAME = libgnl.a#getnextline
MINILIBX_NAME = libmlx.a#minilibx-linux

CFLAGS = -Wall -Wextra -Werror

SRC = fdf_utils.c fdf_init.c fdf_view.c fdf_math.c
MAIN = fdf.c
OBJ = $(SRC:.c=.o)

$(NAME): $(LIB) $(FTPRINTF) $(GNL) $(MAIN) $(MINILIBX) 
	cc $(CFLAGS) -g $(MAIN) $(SRC) $(LIB) $(FTPRINTF) $(GNL) $(MINILIBX) \
	-lXext -lX11 -lm -lz -o $(NAME)

$(LIB): $(OBJ)
	ar -rcs $(LIB) $(OBJ)

$(OBJ): $(SRC)
	cc $(CFLAGS) -c -g $^

$(FTPRINTF):
	$(MAKE) -C ./lib/printf
	cp ./lib/printf/$(FTPRINTF_NAME) $(FTPRINTF)

$(GNL):
	$(MAKE) -C ./lib/get_next_line
	cp ./lib/get_next_line/$(GNL_NAME) $(GNL)

$(MINILIBX):
	$(MAKE) -C ./lib/minilibx
	cp ./lib/minilibx/$(MINILIBX_NAME) $(MINILIBX)

all: $(NAME)

clean:
	rm -f $(OBJ) $(MAIN_OBJ)
	$(MAKE) clean -C ./lib/get_next_line
	$(MAKE) clean -C ./lib/printf

fclean:
	rm -f $(LIBNAME) $(NAME)
	rm -f $(LIB) $(FTPRINTF) $(GNL) $(MINILIBX)
	$(MAKE) fclean -C ./lib/get_next_line 
	$(MAKE) fclean -C ./lib/printf


re: fclean all

# bonus: all

.PHONY: all clean fclean re bonus
