NAME		=	push_swap


LIBFT_DIR	=	libft
LIBFT_HDR	=	$(LIBFT_DIR)/libft.h
LIBFT		=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	$(LIBFT_DIR)/Makefile


SRCS		= 	push_swap.c set_up_scores.c small_sort.c utils_1.c utils_2.c handler_1.c handler_2.c\
				stack/stack.c stack/methods.c stack/operators_1.c stack/operators_2.c\
				input_handler/input_handler.c
OBJS		=	$(SRCS:.c=.o)
HDRS		=	push_swap.h stack/stack.h input_handler/input_handler.h


FLAGS		=	-Wall -Wextra -Werror
CC			=	gcc
GCC			=	$(CC) $(FLAGS)


all:			$(NAME)

%.o:			%.c $(HDRS) $(LIBFT_HDR)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS) $(LIBFT_HDR)
				cd $(LIBFT_DIR) && $(MAKE)
				$(GCC) $(OBJS) $(LIBFT) -o $(NAME)

clean:				
				rm -f $(OBJS)
				cd $(LIBFT_DIR) && make clean

fclean:			clean
				cd $(LIBFT_DIR) && make fclean
				rm -f $(NAME)				

re:				fclean $(NAME)

.PHONY:			all clean fclean re
