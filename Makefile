
CFLAG = -Wall -Wextra -Werror
C_SRC = Colleen.c
C_OUT =Colleen
G_SRC = Grace.c
G_OUT = Grace
S_SRC = Sully.c
S_OUT = Sully
OBJ_FILES =	Sully*.o \
			Grace.o \
			Colleen.o


all: colleen grace sully

colleen: $(C_OUT)
	@gcc $(CFLAG) -o $(C_OUT) $(C_SRC)

$(C_OUT): $(C_SRC)
	@echo "Compiling $@"
	@gcc $(CFLAG) -o $@ -c $<

grace: $(G_OUT)
	@gcc $(CFLAG) -o $(G_OUT) $(G_SRC)

sully: $(S_OUT)
	@gcc $(CFLAG) -o $(S_OUT) $(S_SRC)

clean:
	@rm -rf $(OBJ_FILES)

fclean: clean
	@rm -rf $(C_OUT) $(G_OUT) $(S_OUT)

re: fclean all