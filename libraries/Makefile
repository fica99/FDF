# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/03 11:46:19 by olegmulko         #+#    #+#              #
#    Updated: 2019/09/17 13:58:03 by aashara-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

libft := libft

libstr := libstr

libdir := libdir

libdar := libdar

libstack := libstack

libfifo := libfifo

libhash := libhash

lib_dir := lib_archive

.PHONY: all lall lclean lfclean fclean create_dir

all: $(libft) $(libstr) $(libdir) $(libdar) $(libstack) $(libfifo) $(lib_dir) $(libhash)

$(libft):
	@$(MAKE) --no-print-directory -C $(libft)

$(libstr):
	@$(MAKE) --no-print-directory -C $(libstr)

$(libdir):
	@$(MAKE) --no-print-directory -C $(libdir)

$(libdar):
	@$(MAKE) --no-print-directory -C $(libdar)

$(libstack):
	@$(MAKE) --no-print-directory -C $(libstack)

$(libfifo):
	@$(MAKE) --no-print-directory -C $(libfifo)

$(libhash):
	@$(MAKE) --no-print-directory -C $(libhash)

$(lib_dir): $(libft) $(libstr) $(libdir) $(libdar) $(libstack) $(libfifo) $(libhash) lall
	@echo "\033[32m\033[1mCreate libs directory $(CURDIR)/$(lib_dir)\033[0m"
	@mkdir -p $(lib_dir)
	@echo "\033[32m\033[1mCopy libs to $(CURDIR)/$(lib_dir)\033[0m"
	@cp $(libft)/$(libft).a $(libstr)/$(libstr).a $(libdir)/$(libdir).a \
	$(libdar)/$(libdar).a $(libstack)/$(libstack).a $(libfifo)/$(libfifo).a $(libhash)/$(libhash).a $(lib_dir)
	@echo "\033[1;33m\033[1mFinish $(lib_dir): $(libft) $(libstr) $(libdir)\
		$(libdar) $(libstack) $(libfifo) $(libhash)\033[0m\n"

lall:
	@$(MAKE) all --no-print-directory -C  $(libft)
	@$(MAKE) all --no-print-directory -C  $(libstr)
	@$(MAKE) all --no-print-directory -C  $(libdir)
	@$(MAKE) all --no-print-directory -C  $(libdar)
	@$(MAKE) all --no-print-directory -C  $(libstack)
	@$(MAKE) all --no-print-directory -C  $(libfifo)
	@$(MAKE) all --no-print-directory -C  $(libhash)

lclean:
	@$(MAKE) clean --no-print-directory -C  $(libft)
	@$(MAKE) clean --no-print-directory -C  $(libstr)
	@$(MAKE) clean --no-print-directory -C  $(libdir)
	@$(MAKE) clean --no-print-directory -C  $(libdar)
	@$(MAKE) clean --no-print-directory -C  $(libstack)
	@$(MAKE) clean --no-print-directory -C  $(libfifo)
	@$(MAKE) clean --no-print-directory -C  $(libhash)

lfclean:
	@$(MAKE) fclean --no-print-directory -C  $(libft)
	@$(MAKE) fclean --no-print-directory -C  $(libstr)
	@$(MAKE) fclean --no-print-directory -C  $(libdir)
	@$(MAKE) fclean --no-print-directory -C  $(libdar)
	@$(MAKE) fclean --no-print-directory -C  $(libstack)
	@$(MAKE) fclean --no-print-directory -C  $(libfifo)
	@$(MAKE) fclean --no-print-directory -C  $(libhash)

fclean:
	@$(MAKE) --no-print-directory lfclean
	@echo "\033[36m\033[1mRemove libs directory $(CURDIR)/$(lib_dir)\033[0m\n"
	@rm -rf $(lib_dir)

re: fclean all
