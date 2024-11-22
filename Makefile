NAME = philo

RM = rm -rf
COMPILER = cc -Wall -Wextra -Werror -pthread

DIR_OBJS = builds/
DIR_SRCS = srcs/
DIR_INCLUDES = includes/

GET_SRCS = $(shell find $(DIR_SRCS))

PRE-FILTER_SRCS = $(filter %.c, $(GET_SRCS))

FILTER_SRCS = $(filter-out %testing.c, $(PRE-FILTER_SRCS))

OBJS = $(FILTER_SRCS:%.c=$(DIR_OBJS)/%.o)

all: $(NAME)

$(NAME): $(OBJS) $(DIR_OBJS)
	$(COMPILER) $(OBJS) -o $(NAME)

$(DIR_OBJS):
	mkdir builds

$(DIR_OBJS)/%.o : %.c
	mkdir -p $(dir $@)
	$(COMPILER) -c $< -o $@

val: all
	valgrind  --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME) $(DIR_OBJS)

re: fclean all

debug:	FLAGS += -ggdb3
debug:	fclean ${NAME}
