# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_lstdelone.c ft_lstsize.c ft_memchr.c ft_strncmp.c ft_strlcat.c \
      ft_strrchr.c ft_lstiter.c ft_lstadd_back.c ft_strdup.c ft_strnstr.c \
      ft_strmapi.c ft_isalnum.c ft_memset.c ft_strtrim.c ft_lstmap.c \
      ft_tolower.c ft_lstadd_front.c ft_calloc.c ft_atoi.c ft_lstclear.c \
      ft_bzero.c ft_memcmp.c ft_strjoin.c ft_strlcpy.c ft_lstlast.c \
      ft_split.c ft_memcpy.c ft_toupper.c ft_isalpha.c ft_strchr.c \
      ft_isascii.c ft_striteri.c ft_substr.c get_next_line.c ft_lstnew.c \
      ft_putendl_fd.c ft_strlen.c get_next_line_utils.c ft_putnbr_fd.c \
      ft_isprint.c ft_isdigit.c ft_itoa.c ft_memmove.c printer.c ft_printf.c \
      ft_putchar_fd.c ft_putstr_fd.c itoa_base.c

# Object files
OBJ = $(SRC:.c=.o)

# Header files
HEADERS = libft_ult.h

# Output library
NAME = libft.a

# Default target
all: $(NAME)

# Rule to create the library
$(NAME): $(OBJ)
    ar rcs $@ $^

# Rule to compile object files
%.o: %.c $(HEADERS)
    $(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
    rm -f $(OBJ)

# Clean object files and the library
fclean: clean
    rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean