NAME			= libft.a


SRCS_DIR		= srcs
HEAD_DIR		= includes
OBJS_DIR		= objs

SRC 			= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
				ft_isascii.c ft_isprint.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c \
				ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c \
				ft_calloc.c ft_strdup.c ft_itoa.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c \
				ft_split.c ft_strmapi.c ft_striteri.c \
				ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
				ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
				ft_printf.c \
				ft_putlchar.c \
				ft_putlnbr.c \
				ft_putlstr.c \
				ft_putlnbrbase.c \
				ft_putlptr.c \
				get_next_line.c \
				get_next_line_utils.c


SRCS			= $(addprefix $(SRCS_DIR)/, $(SRC))
OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)


CC				= cc
RM				= rm -f
AR				= ar -rcs

FLAGS			= -Wall -Wextra -Werror


all:		$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEAD_DIR)/libft.h
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -I ./$(HEAD_DIR)/ -c $< -o $@

.c.o:
			$(CC) $(FLAGS) -c -I ./$(HEAD_DIR)/ $< -o $(<:.c=.o)

clean:
			$(RM) -r $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re