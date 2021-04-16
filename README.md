# CPPND: Capstone Project: Solar-Runner

## Introduction

This is my reposity of the final / capstone project of the Udacity "C++ Developer" Nanodegree. The game's basic structure was inspired by the Udacity team's example project found here (https://github.com/udacity/CppND-Capstone-Snake-Game). 

The game's logic was built from scratch, with game play inspired by games such as the bullet-hell classic "Solar Striker" for the original GameBoy (which also inspired the name of this project), and the minimal geometric arcade classic "Asteroids". It was build to showcase some of the key tools learned during the Nanodegree itself, such as Object-Oriented Programming, Control-flows, and Memory Management. Concurrency was not implemented (yet) owing to time constraints.

The goal of the game itself is very straight-forward: dodge the incoming meteors by controlling your ship using the <left> and <right> arrow keys. Each meteor dodged (that goes out of bounds) is worth 1 point. As the you accumulate points, the incoming meteors grow in size, and come at you faster. It should be noted that this difficulty curve is fairly flat, and plateaus quite quickly. In accordance with the arcade classics that inspired this game, there is no win state, only a high-score. 

## Code Structure

The program is implemented using a variety of classes, each of which is named in accordance with its function. The 'Renderer' renders the game state, the 'Game' is the game loop and houses some of the key game logic, and the 'Controller' listens for user input. The two most important classes are probably the 'Ship' and 'Meteor' classes, both children of the abrstract 'Object' parent class. These contain all the information pertaining to their location on screen, their movement pattenr, and their vertices which are crucial for collision detection. Said collision are not handled *within* the class instances (owing to ownership-reasons of their unique_ptrs<>). Instead these are handled within the 'Game' class.

Once compiled and run, the program's 'Main.cpp' 'main' function initializes the renderer, controller, and game. The 'Game' then commences with 'Run', i.e. the main game loop. During each loop, the game i) listens for user input to control and move the ship, ii) possibly spawn meteors, iii) move all meteors on screen and delete those that go out of scope, iv) render the scene present, v) tally the user's score for every meteor dodged, and vi) adds dead-frames to ensure each game loop takes 1/60 of a second.  

The console should only output your final score upon 'Game Over' and a message indicating that the game has terminated succesfully. All additional messages are warnings or errors.

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
4. Run it: `./Solar Runner`.

## Rubric

### README (All Rubric Points REQUIRED)

**A README with instructions is included with the project**
* The README is included with the project and has instructions for building/running the project. (yes)
* If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. (there are none)
* You can submit your writeup as markdown or pdf (markdown)

**The README indicates which project is chosen.**
* The README describes the project you have built.  (yes)
* The README also indicates the file and class structure, along with the expected behavior or output of the program (yes)

### Compiling and Testing (All Rubric Points REQUIRED)

**The submission must compile and run.**
* The project code must compile and run without errors. (yes)
* We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform. (yes)

### Loops, Functions, I/O

**The project demonstrates an understanding of C++ functions and control structures.**
* A variety of control structures are used in the project. (for loops, while loops, if statements using AND and OR, functions)
* The project code is clearly organized into functions. (yes)

**The project accepts user input and processes the input.**
* the user must provide input in the form of the spaceship directions

### Object Oriented Programming

**The project uses Object Oriented Programming techniques.**
* yes, everything is organized into classes

**Classes use appropriate access specifiers for class members.**
* yes, getters and setters are present in order to logically divide a class' fields into public / protected

**Class constructors utilize member initialization lists.**
* All class members that are set to argument values are initialized through member initialization lists. (where necessary/possible intitializer lists are used

**Classes abstract implementation details from their interfaces.**
* yes, the abstract "Object" parent / super class is implemented, and defines the common behavior of the "Ship" and "Meteor" child / sub classes.

**Classes encapsulate behavior.**
* yes, everything is abstracted to make reading the code easier to follow and understand 

**Classes follow an appropriate inheritance hierarchy.**
* Both "Ship" and "Meteor" child classes are related logically to the parent class "Object" as they do share some high level functionality

### Memory Management

**The project makes use of references in function declarations.**
* yes, as a particular example: the method "CheckCollision" in the "Game" class uses only references to unique pointers.

**The project uses destructors appropriately.**
* yes, the desctructors of all "Meteor" instances is called periodically to ensure no memory leaks occur. The "Ship" instance has its destructor called automatically as it is created as a unique_ptr<>.

**The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate.**
* see above

**The project uses move semantics to move data, instead of copying it, where possible.**
* in order to ensure that ownership of unique_ptrs is respected, all unique pointers of instances of "Meteor" and "Ship" are passed to functions and back using smart pointers.

**The project uses smart pointers instead of raw pointers.**
* see above

Sield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
