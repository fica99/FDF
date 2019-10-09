# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:57:06 by aashara-          #+#    #+#              #
#    Updated: 2019/10/06 21:16:23 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name := libft.a

srcs_dir := srcs

obj_dir := obj

srcs_files := ft_strlen.c\
		ft_strdup.c\
		ft_strcmp.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_isalpha.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putendl.c\
		ft_putnbr_fd.c\
		ft_itoa.c\
		ft_strlcat.c\
		ft_strncat.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		get_next_line.c\
		ft_isspace.c\
		ft_swap.c\

obj_files := $(srcs_files:.c=.o)

objs := $(addprefix $(obj_dir)/, $(obj_files))

header := includes/libft.h includes/get_next_line.h

includes := -I includes

cc := gcc

cflags := -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(name)

$(name): $(obj_dir) $(objs)
	@echo "\033[32m\033[1mLink object files\033[0m"
	@ar rc $(name) $(objs)
	@echo "\033[32m\033[1mBuilding archive content $(CURDIR)/$(name)\033[0m"
	@ranlib $(name)
	@echo "\033[1;33m\033[1mFinish $(CURDIR)/$(name)\033[0m\n"

$(obj_dir):
	@echo "\033[32m\033[1mCreate object directory $(CURDIR)/$(obj_dir)\033[0m"
	@mkdir -p $(obj_dir)
	@echo "\033[32m\033[1mCompile sources:\033[0m"
	@$(MAKE) --no-print-directory $(objs)

$(obj_dir)/%.o:$(srcs_dir)/%.c $(header)
	@echo "* \033[31m\033[1mCreate object file $(CURDIR)/$@\033[0m"
	@$(cc) $(cflags) $(includes) -o $@ -c $<

clean:
	@echo "\033[36m\033[1mRemove $(CURDIR)/$(obj_dir)\033[0m"
	@-rm -rf $(obj_dir)

fclean:
	@$(MAKE) --no-print-directory clean
	@echo "\033[36m\033[1mRemove $(CURDIR)/$(name)\033[0m"
	@-rm -rf $(name)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all
