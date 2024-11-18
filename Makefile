# Compiler and flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

# Library name
NAME        := libft.a

# Directories
SRCDIR      := src
OBJDIR      := obj
BONUSDIR    := bonus

# Mandatory source files
SRCS        := ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlen.c \
               ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
               ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
               ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
               ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
               ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
               ft_putnbr_fd.c

# Bonus source files
SRCS_BONUS  := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
               ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
               ft_lstmap.c

# Object files
OBJS        := $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJS_BONUS  := $(addprefix $(OBJDIR)/, $(SRCS_BONUS:.c=.o))

# Rules
all: $(NAME)

# Compile the library from mandatory object files
$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Compile bonus part
bonus: $(OBJS) $(OBJS_BONUS)
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

# Compile object files for mandatory sources
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile object files for bonus sources
$(OBJDIR)/%.o: $(BONUSDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -rf $(OBJDIR)

# Clean everything including the library
fclean: clean
	@rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

# Mandatory rules for norm
.PHONY: all bonus clean fclean re
