# Udacity Nanodegree C++ Developer Rubric's fulfilled

Below, I have indicated what aspects of the Udacity "C++ Developer" capstone project's rubric that I believe I fulfilled, with additional explanations where necessary. 

## README (All Rubric Points REQUIRED)

**A README with instructions is included with the project**
* The README is included with the project and has instructions for building/running the project. (yes)
* If any additional libraries are needed to run the project, these are indicated with cross-platform installation instructions. (there are none)
* You can submit your writeup as markdown or pdf (markdown)

**The README indicates which project is chosen.**
* The README describes the project you have built.  (no)
* The README also indicates the file and class structure, along with the expected behavior or output of the program (no)

## Compiling and Testing (All Rubric Points REQUIRED)

**The submission must compile and run.**
* The project code must compile and run without errors. (yes)
* We strongly recommend using cmake and make, as provided in the starter repos. If you choose another build system, the code must compile on any reviewer platform. (yes)

## Loops, Functions, I/O

**The project demonstrates an understanding of C++ functions and control structures.**
* A variety of control structures are used in the project. (for loops, while loops, if statements using AND and OR, functions)
* The project code is clearly organized into functions. (yes)

**The project accepts user input and processes the input.**
* the user must provide input in the form of the spaceship directions

## Object Oriented Programming

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

## Memory Management

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

## Concurrency
