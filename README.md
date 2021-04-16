# CPPND: Capstone Project: Solar-Runner

## Introduction

This is my reposity of the final / capstone project of the Udacity "C++ Developer" Nanodegree. The game's basic structure was inspired by the Udacity team's example project found here (https://github.com/udacity/CppND-Capstone-Snake-Game). 

The game's logic was built from scratch, with game play inspired by games such as the bullet-hell classic "Solar Striker" for the original GameBoy (which also inspired the name of this project), and the minimal geometric arcade classic "Asteroids". It was build to showcase some of the key tools learned during the Nanodegree itself, such as Object-Oriented Programming, Control-flows, and Memory Management. Concurrency was not implemented (yet) owing to time constraints.

The goal of the game itself is very straight-forward: dodge the incoming meteors by controlling your ship using the <left> and <right> arrow keys. Each meteor dodged (that goes out of bounds) is worth 1 point. As the you accumulate points, the incoming meteors grow in size, and come at you faster. It should be noted that this difficulty curve is fairly flat, and plateaus quite quickly. In accordance with the arcade classics that inspired this game, there is no win state, only a high-score.

## Dependencies for Local Execution

To ensure easy execution for Udacity mentors, the dependencies are identical to those of the aforementioned example game. From the that repository:

* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## How to build it

Again, to ensure ease of grading for Udacity mentors, the build instructions are identical to the example code base:

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
