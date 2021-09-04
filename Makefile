NAME	=	fdf

LIST	=	draw.c	main.c	read_file.c	action.c	rotation.c

HEADER	=	fdf.h

GCC		=	gcc -Wall -Wextra -Werror

OBJ		=	$(@patsubst %.c, %.o, $(LIST))

all		:	$(NAME) $(HEADER)

$(NAME)	:	$(OBJ) $(HEADER)
	@$(MAKE) -C ./libft
	@$(GCC) $(LIST) ./libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit -o $(NAME)
	@echo "project created / updated"

clean		:
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@echo "project clean done"

fclean		:	clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME) $(OBJ)
	@echo "project fclean done"
	
re			:	fclean all

.PHONY		:	all clean fclean re