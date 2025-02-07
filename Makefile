CC = cc
CFLAGS = -Wall -Wextra -Werror
EXEC = push_swap

SRC = ft_split.c \
      ft_strjoin.c \
      instructions.c \
      main.c \
      parsing.c \
      small_sort.c \
      sort.c \
      utils.c \
      verif_parsing.c

OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Compilation réussie ✓"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@


clean:
	@rm -f $(OBJ)
	@echo "Nettoyage des .o ✓"

fclean: clean
	@rm -f $(EXEC)
	@echo "Nettoyage complet ✓"

re: fclean all

.PHONY: all clean fclean re