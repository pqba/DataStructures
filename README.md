# Data Structures
*A project to learn about, create use cases of, and generally construct useful data structures.*

## Features
What comes included in the project.

### Data Structures

* Stack
* Queue
* Singly Linked List
* Doubly Linked List

### Common
* Reverse Polish Notation Calculator
* Music Player
* Event Handling System

## Usage

Use the classes and data structures by running **main.cpp** this way, using the Makefile:
```
make all
bin/main_executable
make clean
```
In case of bugs, use ```make debug``` instead for tracing.

## File Structure of Project

* Makefile to compile everything correctly
* ```bin/``` and ```obj/``` directories for object and binary files created
* ```include/``` for header files
* ```src/``` for .cpp files
* ```test/``` for test files of structures

### Notes
 1. ```Structures/``` has the data structure part in any specific parent directory
 2. ```Common/``` has the **common** implementations and use cases for any parent directory
Project Structure:
```
.
├── Makefile
├── README.md
├── include
│   ├── Common
│   │   ├── Event.h
│   │   ├── EventHandler.h
│   │   └── MusicPlayer.h
│   └── Structures
│       ├── Data.h
│       ├── DoublyLinkedList.h
│       ├── LinkedList.h
│       ├── Queue.h
│       └── Stack.h
├── src
│   ├── Common
│   │   ├── EventHandler.cpp
│   │   ├── MusicPlayer.cpp
│   │   └── RPN.cpp
│   ├── Structures
│   │   ├── Data.cpp
│   │   ├── DoublyLinkedList.cpp
│   │   ├── LinkedList.cpp
│   │   ├── Queue.cpp
│   │   └── Stack.cpp
│   └── main.cpp
└── test
    ├── Common
    └── Structures
        └── dllTest.cpp
```

## License

This project is licensed under the MIT License.

## Acknowledgements

The implementations of the data structures were informed by online resources from

[Wikipedia](https://en.wikipedia.org/) 
U Nevada Reno, Stanford, CMU, U Western Ontario, Jackson State U
