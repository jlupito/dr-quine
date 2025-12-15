CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = Colleen Grace Sully

all: $(NAME)
	@echo "Compilation done!"

Colleen: Colleen.c
	@$(CC) $(CFLAGS) -o $@ $<

Grace: Grace.c
	@$(CC) $(CFLAGS) -o $@ $<

Sully: Sully.c
	@$(CC) $(CFLAGS) -o $@ $<

clean:
	@rm -f Colleen.o Grace.o Sully.o
	@echo "cleaning done"

fclean: clean
	@rm -rf Colleen Grace Sully
	@rm -f Sully_*
	@rm -f Grace_kid.c
	@echo "fcleaning done"

re: fclean all

.PHONY: all clean fclean re Colleen Grace Sully