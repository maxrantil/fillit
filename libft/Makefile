NAME = libft.a
FLAGS = -Wall -Wextra -Werror
HEADER_PATH = libft.h
C_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		  ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c \
		  ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		  ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c \
		  ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
		  ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c \
		  ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		  ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdelone.c \
		  ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_intlen.c ft_lstcount.c ft_lstputnbr.c \
		  ft_lstaddend.c ft_lstputstr.c ft_isspace.c ft_strcdup.c ft_strclen.c ft_strupdate.c
O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo "This is libft!"
	@echo ""
	@echo "██╗     ██╗██████╗ ███████╗████████╗"
	@echo "██║     ██║██╔══██╗██╔════╝╚══██╔══╝"
	@echo "██║     ██║██████╔╝█████╗     ██║"
	@echo "██║     ██║██╔══██╗██╔══╝     ██║"
	@echo "███████╗██║██████╔╝██║        ██║"
	@echo "╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝"   
	@echo ""
	@gcc $(FLAGS) -c $(C_FILES) -I $(HEADER_PATH)
	@ar rc $(NAME) $(O_FILES) 
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"
	
clean:
	@rm -rf $(O_FILES)
	@echo ".o files deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
