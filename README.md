# FDF
## Description

School 42 project in graphic branch\. The representation in 3D of a landscape\.
Full description in [subject file](https://cdn.intra.42.fr/pdf/pdf/1803/fdf.en.pdf "school project")\.


![Example](https://i.ibb.co/vzz1YHc/Screen-Shot-2020-11-13-at-2-05-48-PM.png)


## Compilation

To generate an executable for this project run `make` in the root of the project directory.
This project will only work on MacOS El Capitan/Sierra/HighSierra(maybe) and even then, no promises!

* `make` \- executable file compilation\.
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

```
$> make
$> ./fdf [test_maps/filename>]
```

A valid fdf file will consist of a matrix of number delimited by spaces. Each number's position represents an (x , y) coordinate with the value of the number itself representing a height (z).

Valid fdf files will always have the same number of elements per row.

Example:
```
$> cat -e test_maps/42.fdf
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0 10 10  0  0 10 10  0  0  0 10 10 10 10 10  0  0  0$
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0$
0  0 10 10  0  0 10 10  0  0  0  0  0  0  0 10 10  0  0$
0  0 10 10 10 10 10 10  0  0  0  0 10 10 10 10  0  0  0$
0  0  0 10 10 10 10 10  0  0  0 10 10  0  0  0  0  0  0$
0  0  0  0  0  0 10 10  0  0  0 10 10  0  0  0  0  0  0$
0  0  0  0  0  0 10 10  0  0  0 10 10 10 10 10 10  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0$
```

## Features

* Key `+` to increase\.
* Key `-` to decrease\.
* Key `P` to see parallel projection\.
* Key `I` to see isometric projection\.
* Key `W` to rotate up around the x axis\.
* Key `S` to rotate down around the x axis\.
* Key `A` to rotate left around the y axis\.
* Key `D` to rotate right around the y axis\.
* Key `Q` to rotate left around the z axis\.
* Key `E` to rotate right around the z axis\.
* Key `Y` set yellow colour\.
* Key `R` set red colour\.
* Key `T` set default colour\.

