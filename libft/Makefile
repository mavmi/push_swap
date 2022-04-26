SRCS		= 	ft_putendl_fd.c ft_isdigit.c ft_atoi.c ft_itoa.c ft_strncmp.c ft_strlen.c ft_putstr_fd.c ft_putchar_fd.c

OBJS		=	$(SRCS:.c=.o)

INCLUDES	=	libft.h

FLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

GCC			=	$(CC) $(FLAGS)

NAME		=	libft.a

all:		$(NAME)

%.o:		%.c $(INCLUDES)
			$(GCC) -c -o $@ $<

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

libft:		$(NAME)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:		all libft clean fclean re
