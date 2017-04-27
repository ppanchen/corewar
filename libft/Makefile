SRC = ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memccpy.c	ft_memmove.c				    \
	  ft_memchr.c		ft_memcmp.c		ft_strlen.c		ft_strdup.c		ft_strcpy.c					    \
	  ft_strncpy.c		ft_strcat.c		ft_strncat.c	ft_strlcat.c	ft_strchr.c					    \
	  ft_strrchr.c		ft_strstr.c		ft_strnstr.c	ft_strcmp.c		ft_strncmp.c				    \
	  ft_atoi.c			ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c				    \
      ft_isprint.c		ft_toupper.c	ft_tolower.c	ft_memalloc.c	ft_memdel.c 				    \
      ft_strnew.c		ft_strdel.c		ft_strclr.c		ft_striter.c	ft_striteri.c				    \
      ft_strmap.c		ft_strmapi.c	ft_strequ.c		ft_strnequ.c	ft_strsub.c                     \
      ft_strjoin.c		ft_strtrim.c	ft_strsplit.c	ft_itoa.c		ft_putchar.c                    \
	  ft_putstr.c		ft_putendl.c	ft_putnbr.c		ft_putchar_fd.c	ft_putstr_fd.c                  \
	  ft_putendl_fd.c	ft_putnbr_fd.c	ft_lstnew.c		ft_lstdelone.c	ft_lstdel.c                     \
	  ft_lstadd.c		ft_lstiter.c	ft_lstmap.c		ft_strrev.c		ft_strclen.c                    \
	  ft_cwords.c		ft_words.c		ft_strcount.c	ft_modul.c		get_next_line.c                 \
	  ft_atof.c         ft_numlen.c     ft_pow.c		ft_itoa_base.c                                  \
	  ft_printf/Handlers/flags_handler.c				ft_printf/Handlers/type_handlers_cper.c         \
	  ft_printf/Handlers/type_handlers_oouuxxu.c			ft_printf/Handlers/type_handlers_spdduiuu.c \
	  ft_printf/ft_printf.c				ft_printf/ft_printf_parser.c	ft_printf/paste_arg.c           \
	  ft_printf/UHandlers/unicode_chars.c               ft_printf/UHandlers/utools.c                    \
	  ft_printf/UHandlers/wchar_paste.c ft_printf/Handlers/flags_handler2.c                             \
	  count_chars.c     ft_arrdel.c     ft_arrrev.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -cr $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c 
	gcc -Wall -Wextra -Werror -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
