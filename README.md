# Data Structure Collection

A project aimed at learning, implementing, and demonstrating various data structures with their common applications.

<img src="https://upload.wikimedia.org/wikipedia/commons/f/f4/Network_Community_Structure.svg" height="150" alt="" title="Graph Connectivity">

## Features

### Data Structures

- Stack: Last In, First Out (LIFO) data structure.
- Queue: First In, First Out (FIFO) data structure.
- Singly Linked List: Linear collection with each element pointing to the next.
- Doubly Linked List: Similar to singly linked list but with elements pointing to both next and previous.
- Binary Search Tree: Hierarchical structure for fast searching, insertion, and deletion.
    - AVL Tree: Subset of BST which uses rotations to optimally organize nodes
### Common

- Reverse Polish Notation Calculator: Evaluate mathematical expressions in postfix notation.
- Music Player: Basic implementation of a music player.
- Event Handler System: Manage and handle events efficiently.
- Lexicon: Get top keywords, similar words, and other diagnostics from a text file
## Usage
> This project uses CMake, Install [Here](https://cmake.org/download/)

### Build Project
1. Execute `$: cmake ../ -B .`  in a **build/** subdirectory
2. After project is built, simply use **make** command.
2. Execute binary with `$: build/bin/main_executable`.
### Run Configurations
#### Mac/Linux
* Execute in debug mode using `$: cmake -DCMAKE_BUILD_TYPE=Debug .. && cmake --build .` in **build/** subdirectory
    * Use lldb or other debug tools as necessary with generated binary
* Clean up binary and other generated files while in **build/** using `$: make clean_all`.

#### Windows (VSCode)
> This assumes that you have [Ninja](https://ninja-build.org/) in your CMake **bin/** folder and CMake Tools Installed
1. In the top level directory, Open the Command Palette (Ctrl+Shift+P), type `CMake: Configure` and select it. This will configure your project using CMake.
    * You may be prompted to select a kit (compiler). Choose the appropriate one for your system (e.g., Visual Studio, MinGW).
2. After configuring CMake, you can build your project by selecting `CMake: Build` from the Command Palette.
3. Use a `launch.json` file for debugging purposes.

## File Structure

- **src/**: Source code `.cpp` files for data structures and common features.
- **include/**: Header files `.h` files for declaring classes and functions.
- **build/**: CMake project build folder
- **test/**: Test files for verifying data structure implementations.

## License

This project is licensed under the MIT License.

## Acknowledgements

The implementations of data structures were informed with online resources from various institutions including Wikipedia, Stanford Online Library, and cppreference.
