PROGRAM = calc 
NAME = libftls.a 
FLAGS = -Wall -Werror -Wextra -g
CC = gcc
OBJSRC = $(patsubst %, %.o, $(SRC))
OBJINC = $(patsubst %, %.o, $(INC))

# LS SOURCE
SRC += src/start
SRC += src/store

# GENERAL LIBFT FUNCTIONS
INC += ft_memalloc
INC += ft_atoi

# FTPRINTF ?
INC += src/libft/ftprintf/conversion_diou
INC += src/libft/ftprintf/dispatcher
INC += src/libft/ftprintf/printflags
INC += src/libft/ftprintf/conversion_sc
INC += src/libft/ftprintf/storeflags
INC += src/libft/ftprintf/conversion_xp
INC += src/libft/ftprintf/misc
INC += src/libft/ftprintf/ulitobase

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
