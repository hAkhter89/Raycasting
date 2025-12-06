Pre-requisites to running the program --
**SFML 2.6.1(IT WILL NOT WORK WITH SFML 3) --

FOR WINDOWS:
--> Unless you have set up the SFML library before, use WSL. Don't bother with path shenanigans on Windows.

>>> For compiling the project, use the following command:
-----> g++ *.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system (inside the root folder, /Raycasting)

>>> For running the project, use:
-----> ./main

FOR LINUX:
--> Remove your current sfml build:
sudo pacman -R sfml (OR EQUIVALENT FOR YOUR DISTRO)
--> then to download 2.6.1 specifically:
sudo pacman -U https://archive.archlinux.org/packages/s/sfml/sfml-2.6.1-1-x86_64.pkg.tar.zst (OR EQUIVALENT IN YOUR DISTRO LOOK IT UP DUDE)
then in /etc/pacman.conf, add sfml to IGNOREPKG line.

>>> For compiling the project:
g++ *.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system (inside the root folder, /Raycasting)

>>> For running the project:
 ./main

AND THERE YOU HAVE IT, DOOM64 BUT SUCKS VERISON (IT IS NOT LIKE DOOM64 AT ALL, THAT GAME DOESNT EVEN USE RAYCASTING)


CREDITS -> RAUF, HASSAN
