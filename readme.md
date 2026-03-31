# IPv4PrefixSet

Is an implementation of a unique-value unsorted collection of address/mask pairs in C++.

## Usage
Before use the program must be compiled. This can be done by running **comp.sh** on a Unix-based system.

Otherwise the program can be compiled with any preferred C++ compiler. 


After the compilation the program can be run from the compiled executable file (**main.o** by default).

## Structure

The program is separated into:

### IPv4Prefix.h

A class to manage the address/mask pair and compute addresses with masks applied.

### Set.h

A template set class to manage abstract objects.

### IPv4PrefixSet.h

A class inheriting **Set.h** and suited for **IPv4Prefix** specifically.

### includes.h

A shared file to access common **include**d libraries.

### main.cpp

The file in which the main function is declared.


## Decisions

### .h and .cpp

While it would have been righteous to divide classes into .h and .cpp files, for a project of this size it is much more readable to keep it compact.

### Speed and sorting

While sorting could have brought about significant increase of speed if it was applied properly, it places the solution farther from the concept of the basic unordered set.
