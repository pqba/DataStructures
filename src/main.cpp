// basic utils
#include <iostream>
// tests
#include "../test/Structures/qTest.cpp"
#include "../test/Structures/dllTest.cpp"
#include "../test/Common/mTest.cpp"

// Common
#include "Common/RPN.cpp" //technically bad practice.
#include "../include/Common/MusicPlayer.h"
#include "../include/Common/Event.h"
#include "../include/Common/EventHandler.h"

// Structures
#include "../include/Structures/Queue.h"
#include "../include/Structures/Data.h"
#include "../include/Structures/DoublyLinkedList.h"

/*
MAIN.CPP File for entire project.
Run project:
$: make all
$: bin/main_executable
$: make clean
*/

void playRPN(){
    std::string userEquation = "";
    std::cout << "Enter Reverse Polish Notation you want evaluated:";
    getline(std::cin, userEquation);
    RPN eq(userEquation);
    std::cout << "\nInitialized Equation.\nResult is: " << eq.getResult() << " " << std::endl;
}

void testDLL(){
    TestDLL::testDLL();
}

void testMusic(){
    testM::testM();
}

void testQ(){
    TestQ::testQ();
}

void testEventHandler(){
    EH::runEventHandle();
}

int main() {
    std::cout << "BEGIN MAIN()" << std::endl;

    testEventHandler();

    std::cout << "END MAIN()" << std::endl;
    return 0;
}
