PROGRAM = calc 
NAME = libftls.a 
FLAGS = -Wall -Werror -Wextra -g
CC = gcc
OBJSRC = $(patsubst %, %.o, $(SRC))
OBJINC = $(patsubst %, %.o, $(INC))

# LS SOURCE
SRC += src/start
SRC += src/store
SRC += src/operations
SRC += src/addition
SRC += src/substraction
SRC += src/multiplication
SRC += src/rpn
SRC += src/stack
SRC += src/linked_list
SRC += src/print
SRC += src/tools
SRC += src/cleanup
SRC += src/validation

# GENERAL LIBFT FUNCTIONS
INC += src/libft/ft_memalloc
INC += src/libft/ft_bzero
INC += src/libft/ft_memdel
INC += src/libft/ft_memset
INC += src/libft/ft_strcat
INC += src/libft/ft_strcmp
INC += src/libft/ft_strcpy
INC += src/libft/ft_strlen
INC += src/libft/ft_strnew
INC += src/libft/ft_putstr

all: $(NAME)

$(NAME): $(OBJINC) $(OBJSRC)
	@ echo "Building static library..."
	@ ar -rcs $(NAME) $(OBJSRC) $(OBJINC)
	@ echo "Compiling calc program"
	@ $(CC) $(FLAGS) -L . -l ftls -o $(PROGRAM)

%.o: %.c
	@ echo "Compiling $<..."
	@ $(CC) $(FLAGS) -c $< -o $@

clean:
	@ /bin/rm -f $(OBJSRC)
	@ /bin/rm -f $(OBJINC)
	@ echo "Cleaning folders of object files..."

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(PROGRAM)
	@ echo "Removing library file and binary..."

re: fclean all
	@ echo "Program Remade"
