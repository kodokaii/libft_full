NAME 		= libft.a
CC 			= cc
CFLAGS 		+= -Wall -Wextra -Werror
SRC 		= bst/ft_bstchr.c\
			  bst/ft_bstclear.c\
			  bst/ft_bstiter_infix.c\
			  bst/ft_bstiter_prefix.c\
			  bst/ft_bstiter_suffix.c\
			  bst/ft_bstlevel_count.c\
			  bst/ft_bstnew.c\
			  bst/ft_bstpush.c\
			  buf/ft_buf_alloc.c\
			  buf/ft_buf_free.c\
			  buf/ft_buf_realloc.c\
			  buf/ft_buf_write.c\
			  convert/ft_atof.c\
			  convert/ft_atoi.c\
			  convert/ft_itoa.c\
			  convert/ft_nblen.c\
			  convert/ft_split.c\
			  convert/ft_strtoi.c\
			  convert/ft_word.c\
			  gnl/ft_gnl.c\
			  gnl/ft_read_line.c\
			  is/ft_isalnum.c\
			  is/ft_isalpha.c\
			  is/ft_isascii.c\
			  is/ft_isblank.c\
			  is/ft_isdigit.c\
			  is/ft_isprint.c\
			  is/ft_isspace.c\
			  lst/ft_lstadd_back.c\
			  lst/ft_lstadd_front.c\
			  lst/ft_lstchr.c\
			  lst/ft_lstclear.c\
			  lst/ft_lstdelone.c\
			  lst/ft_lstdup.c\
			  lst/ft_lstget.c\
			  lst/ft_lstis_sort.c\
			  lst/ft_lstiter.c\
			  lst/ft_lstiter_inv.c\
			  lst/ft_lstlast.c\
			  lst/ft_lstmap.c\
			  lst/ft_lstnew.c\
			  lst/ft_lstnext_roll.c\
			  lst/ft_lstremove.c\
			  lst/ft_lstsize.c\
			  lst/ft_lstsort.c\
			  lst/ft_lstsort_merge.c\
			  math/ft_exp.c\
			  mem/ft_bzero.c\
			  mem/ft_calloc.c\
			  mem/ft_malloc.c\
			  mem/ft_memchr.c\
			  mem/ft_memchrset.c\
			  mem/ft_memcmp.c\
			  mem/ft_memcpy.c\
			  mem/ft_memdup.c\
			  mem/ft_memmove.c\
			  mem/ft_memset.c\
			  mem/ft_realloc.c\
			  printf/ft_check.c\
			  printf/ft_dprintf.c\
			  printf/ft_hexa.c\
			  printf/ft_integer.c\
			  printf/ft_option.c\
			  printf/ft_parsing.c\
			  printf/ft_pointer.c\
			  printf/ft_printf.c\
			  put/ft_putchar_fd.c\
			  put/ft_putendl_fd.c\
			  put/ft_putlst_fd.c\
			  put/ft_putnbr_base_fd.c\
			  put/ft_putnbr_fd.c\
			  put/ft_putstr_fd.c\
			  put/ft_putstrn_fd.c\
			  shell/ft_heredoc.c\
			  shell/ft_which.c\
			  shell/ft_execve.c\
			  str/ft_strcat.c\
			  str/ft_strchr.c\
			  str/ft_strcmp.c\
			  str/ft_strcpy.c\
			  str/ft_strdup.c\
			  str/ft_striteri.c\
			  str/ft_strjoin.c\
			  str/ft_strlcat.c\
			  str/ft_strlcpy.c\
			  str/ft_strlen.c\
			  str/ft_strmapi.c\
			  str/ft_strncmp.c\
			  str/ft_strndup.c\
			  str/ft_strnstr.c\
			  str/ft_strpbrk.c\
			  str/ft_strrchr.c\
			  str/ft_strtrim.c\
			  str/ft_substr.c\
			  str/ft_tolower.c\
			  str/ft_toupper.c\
			  utils/ft_abs.c\
			  utils/ft_argv.c\
			  utils/ft_basename.c\
			  utils/ft_errloc.c\
			  utils/ft_get_envp.c\
			  utils/ft_max.c\
			  utils/ft_min.c\
			  utils/ft_swap.c\
			  utils/random.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
