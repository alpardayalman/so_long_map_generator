
# Map generator for project so_long.

This map generator is for ecole 42 students whom chosen the project so long.
It randomly generates Maps according and within the limits of project's requirements.
Depending on your custom arguments you can create up to 5 exits and up to a 100 collectibles.
If you don't fill the optional arguments the program will create 1 exit and a formulated amount of collectibles.


## Installation

Install the so_long_map_generator by cloning.

```bash
  git clone git@github.com:alpardayalman/so_long_map_generator.git
```

```bash
  make
```
Example of use:
```bash
  ./map_gen arda 20 10 12 4
```
```bash
  ./map_gen (name of the file generated without .ber) (width) (height) [(optional) (collectibles) (exits)]
```


## Screenshots
After make:
![Alt text](https://github.com/alpardayalman/so_long_map_generator/blob/master/inc/img/ss1.png?raw=true "Optional Title")

```bash
  ./map_gen arda 20 10
```


The program will create a new directory named maps and it will fill with new .ber files.
The program will always show the new name of your map and the names of other maps that you have created previously.
![Alt text](https://github.com/alpardayalman/so_long_map_generator/blob/master/inc/img/ss2.png?raw=true "Optional Title")


This is an example of a randomly generated map with the arguments (arda 20 10).

![Alt text](https://github.com/alpardayalman/so_long_map_generator/blob/master/inc/img/ss4.png?raw=true "Optional Title")

When you make fclean, once generated map files in the maps folder will be erased.

