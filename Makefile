# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/24 16:32:39 by lbellona          #+#    #+#              #
#    Updated: 2019/10/11 21:37:15 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name := fdf

lib_dir := libraries

mlx = minilibx_macos/libmlx.a

srcs_dir := srcs

obj_dir := obj

inc_dir := includes

lib_archive := $(addprefix $(lib_dir)/, lib_archive)

srcs_files = fdf.c\
		read_map.c\
		draw_landscape.c\
		draw.c\
		params.c\
		handlers.c\
		params_other.c\
		linear_gradient.c\

.LIBPATTERNS := "lib%.a"

obj_files := $(srcs_files:.c=.o)

objects := $(addprefix $(obj_dir)/, $(obj_files))

cc := gcc

cflags := -Wall -Wextra -Werror

includes_libft := $(addprefix $(addprefix $(lib_dir)/, libft/), includes)

includes_libstr := $(addprefix $(addprefix $(lib_dir)/, libstr/), includes)

includes_libdir := $(addprefix $(addprefix $(lib_dir)/, libdir/), includes)

includes_libdar := $(addprefix $(addprefix $(lib_dir)/, libdar/), includes)

includes_libstack := $(addprefix $(addprefix $(lib_dir)/, libstack/), includes)

includes_libfifo := $(addprefix $(addprefix $(lib_dir)/, libfifo/), includes)

includes_libhash := $(addprefix $(addprefix $(lib_dir)/, libhash/), includes)

lib_flags := -lft -lstr -ldir -ldar -lfifo -lstack -lncurses -lhash -lmlx -framework OpenGL -framework AppKit

includes := -I $(inc_dir) -I $(includes_libdar) -I $(includes_libdir) \
	-I $(includes_libfifo) -I $(includes_libft) -I $(includes_libstack) -I $(includes_libstr) -I $(includes_libhash) -I minilibx_macos

header := includes/fdf.h

.PHONY: all lall llall llclean llfclean lfclean oclean clean fclean re

all: $(name)

$(name): $(mlx) lall $(obj_dir) $(objects)
	@echo "\033[32m\033[1m--->Create binary file $(CURDIR)/$(name)\033[0m"
	@$(cc) -O0 -g $(objects) -o $@ -L $(lib_archive) -L minilibx_macos $(lib_flags)

$(obj_dir):
	@echo "\033[32m\033[1m--->Create object directory $(CURDIR)/$(obj_dir)\033[0m"
	@mkdir -p $(obj_dir) $(obj_dir)/$(builtins_dir) $(obj_dirs)
	@echo "\033[32m\033[1m--->Compile sources:\033[0m"
	@$(MAKE) --no-print-directory $(objects)

$(obj_dir)/%.o:$(srcs_dir)/%.c $(header)
	@echo "\033[31m\033[1m--->Create object file $(CURDIR)/$@\033[0m"
	@$(cc) -O0 -g $(cflags) $(includes) -o $@ -c $<

$(mlx):
	@echo "\033[0;30m\033[1m--->Start compiling minilibx library\033[0m"
	@$(MAKE) --no-print-directory -C minilibx_macos
	@echo "\033[0;30m\033[1m--->Finish minilibx library compilation\033[0m"

lall:
	@echo "\033[0;30m\033[1m--->Start compiling libraries archive\033[0m"
	@$(MAKE) all --no-print-directory -C $(lib_dir)
	@echo "\033[0;30m\033[1m--->Finish libraries archieve compilation\033[0m"
	@echo "\033[0;30m\033[1m--->Finish getting libraries archieve\033[0m"

llall:
	@$(MAKE) lall --no-print-directory -C $(lib_dir)

llclean:
	@$(MAKE) lclean --no-print-directory -C $(lib_dir)

llfclean:
	@$(MAKE) lfclean --no-print-directory -C $(lib_dir)

lfclean:
	@$(MAKE) fclean --no-print-directory -C $(lib_dir)

oclean:
	@echo "\033[36m\033[1m--->Remove $(CURDIR)/$(obj_dir)\033[0m"
	@-rm -rf $(obj_dir)

clean:
	@$(MAKE) --no-print-directory oclean
	@$(MAKE) --no-print-directory lfclean
	@echo "\033[36m\033[1m--->Clean minilibx library\033[0m"
	@$(MAKE) clean --no-print-directory -C minilibx_macos

fclean:
	@$(MAKE) --no-print-directory clean
	@echo "\033[36m\033[1m--->Remove $(CURDIR)/$(name)\033[0m"
	@-rm -rf $(name)

re:
	@$(MAKE) --no-print-directory fclean
	@$(MAKE) --no-print-directory all
