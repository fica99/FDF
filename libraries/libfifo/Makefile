# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:57:06 by aashara-          #+#    #+#              #
#    Updated: 2019/09/15 21:14:12 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name := libfifo.a

srcs_dir := srcs

obj_dir := obj

srcs_files := ft_newfifo.c\
			ft_del_fifo.c\
			ft_clear_fifo.c\
			ft_add_fifo.c\
			ft_get_fifo.c\
			ft_fifo.c\

obj_files := $(srcs_files:.c=.o)

objs := $(addprefix $(obj_dir)/, $(obj_files))

header := includes/libfifo.h

includes := -I ./includes -I ../libft/includes

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
