NAME = uls

INC =  uls.h

SRC = *.c

SRCS = $(addprefix src/, $(SRC))

OBJ = $(SRC:%.c=%.o)

CFLAGS = -std=c11 -Wall -Werror -Wextra -Wpedantic -g

all: install

install:
		@make -sC libmx
		@cp $(addprefix src/, $(SRC)) .
		@cp $(addprefix inc/, $(INC)) .
		@clang $(CFLAGS) -c $(SRC) -I $(INC)
		@clang $(CFLAGC) libmx/libmx.a $(OBJ) -o $(NAME)
		@mkdir -p obj
		@mv $(OBJ) ./obj
clean:
		@make clean -sC libmx 	       
		@rm -rf $(INC) $(SRC) ./obj

uninstall: clean         
	@rm -rf $(NAME)

reinstall: uninstall install
