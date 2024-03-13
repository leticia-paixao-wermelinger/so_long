
NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRCS = \
my_atoi.c \
my_bzero.c \
my_calloc.c \
my_isalnum.c \
my_isalpha.c \
my_isascii.c \
my_isdigit.c \
my_isprint.c \
my_itoa.c \
my_memchr.c \
my_memcmp.c \
my_memcpy.c \
my_memmove.c \
my_memset.c \
my_printf.c \
my_putchar.c \
my_putchar_fd.c \
my_putendl_fd.c \
my_putnbr.c \
my_putnbr_base.c \
my_putnbr_fd.c \
my_putstr.c \
my_putstr_fd.c \
my_split.c \
my_clean_vect.c \
my_strchr.c \
my_strdup.c \
my_striteri.c \
my_strjoin.c \
my_strlcat.c \
my_strlcpy.c \
my_strlen.c \
my_strmapi.c \
my_strncmp.c \
my_strnstr.c \
my_strrchr.c \
my_strtrim.c \
my_substr.c \
my_tolower.c \
my_toupper.c \
get_next_line.c \
get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: ${NAME}

${NAME} : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f ${NAME}

re: fclean all
