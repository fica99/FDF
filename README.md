# fdf
## Desctiption

School 42 project in graphic branch\. The representation in 3D of a landscape\.
Full description in [subject file](https://cdn.intra.42.fr/pdf/pdf/1803/fdf.en.pdf "school project")\.

## Compilation

* `make` \- executable file compilation\.
* `make loadlibs` \- download libraries\.
* `make removelibs` \- remove libraries\.
* `make all` \- same as `make`\.
* `make fclean` \- removing objects directory, full cleaning library archieve directory(removing libraries archieve and objects directory with library in every library directory) and executable file\.
* `make clean` \- removing objects directory, full cleaning library archieve directory(removing libraries archieve and objects directory with library in every library directory)\.
* `make oclean` \- removing objects directory\.
* `make lfclean` \- full cleaning library archieve directory(removing libraries archieve and objects directory with library in every library directory)\.
* `make llfclean` \- full cleaning every library directory(removing objects directory with library in every library directory)\.
* `make llclean` \- cleaning every library directory(removing objects directory in every library directory)\.
* `make llall` \- full compilation every library\.
* `make lall` \- full compilation libraries archieve\.
* `make re` \- removing all intermediate files and after that executable file compilation\.

## Usage

>make

>./fdf \<filename\>

## Features

* Key `+` to increase\.
* Key `-` to decrease\.
* Key `p` to see parallel projection\.
* Key `i` to see isometric projection\.
* Key `w` to rotate up around the x axis\.
* Key `s` to rotate down around the x axis\.
* Key `a` to rotate left around the y axis\.
* Key `d` to rotate right around the y axis\.
* Key `q` to rotate around the z axis\.
* Key `e` to rotate around the z axis\.

## Created with:

* MiniLibX library\.
